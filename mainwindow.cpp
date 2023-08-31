#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/QSerialPortInfo"
#include "QMessageBox"
#include "Port.h"
#include <QDebug>
#include "qcustomplot.h"
#include <QRegExp>
#include <QTime>
#include "EMAFilter.h"
#include "MovingAverageFilter.h"
#include <QThread>

const int SAMPLES = 4095;
constexpr double VREF = 3.409;
constexpr double EMA_ALPHA = 0.2;
constexpr int MA_WINDOW = 10;
class EMAFilter;
class MovingAverageFilter;

bool isConnected = false;
bool filterType = true;
QSerialPort serialPort;
QTimer *timer = new QTimer;
double xmin = 0,xmax = 100, ymin = -1,ymax = 4;
int adc[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
QVector<double>measurement,
measurement2,
measurement3,
measurement4,
measurement5,
measurement6,
measurement7,
measurement8,
measurement9,
measurement10,
filtered,
filtered2,
filtered3,
filtered4,
filtered5,
filtered6,
filtered7,
filtered8,
filtered9,
filtered10,
timing;
QVector<std::complex<double>> forDft;
QTime first;
bool isFirst = true;
double displayRange = 100;
EMAFilter emaFilter(EMA_ALPHA),
emaFilter2(EMA_ALPHA),
emaFilter3(EMA_ALPHA),
emaFilter4(EMA_ALPHA),
emaFilter5(EMA_ALPHA),
emaFilter6(EMA_ALPHA),
emaFilter7(EMA_ALPHA),
emaFilter8(EMA_ALPHA),
emaFilter9(EMA_ALPHA),
emaFilter10(EMA_ALPHA);
MovingAverageFilter maFilter(MA_WINDOW),
maFilter2(MA_WINDOW),
maFilter3(MA_WINDOW),
maFilter4(MA_WINDOW),
maFilter5(MA_WINDOW),
maFilter6(MA_WINDOW),
maFilter7(MA_WINDOW),
maFilter8(MA_WINDOW),
maFilter9(MA_WINDOW),
maFilter10(MA_WINDOW);

void saveDataToCSV(const QVector<QVector<double>>&data)
{
    QString fileName = "data.csv";
    QFile file(fileName);
    int counter = 1;

    while(file.exists())
    {
        fileName = QString("data_%1.csv").arg(counter);
        file.setFileName(fileName);
        counter++;
    }


    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QVector<QString> columnNames = {"Timing","ADC1","ADC2","ADC3","ADC4","ADC5","ADC6","ADC7","ADC8","ADC9","ADC10"};

        // Записываем заголовки столбцов

        for(int i = 0; i < columnNames.size(); ++i)
        {
            stream << columnNames[i];

            if(i < columnNames.size() - 1)stream << ";";

        }
        stream << "\n";


        // Записываем данные

        int numRows = data[0].size();

        for(int i = 0; i < numRows; i++)
        {

            for(int j = 0; j < data.size(); j++)
            {
                stream << data[j][i];

                if(j < data.size() - 1)stream << ";";

            }

            stream << "\n";

        }
        file.close();
    }
}

class SaveDataThread : public QThread
{
    Q_OBJECT
public:
    explicit SaveDataThread(const QVector<QVector<double>>&data):data_(data){}

signals:
    void saveCompleted();

protected:
    void run() override
    {
        saveDataToCSV(data_);
        emit saveCompleted();
    }
private:
    QVector<QVector<double>> data_;
};


QVector<std::complex<double> > MainWindow::dft(QVector<std::complex<double> > X)
{
    int N = X.size();
    int K = 100000;

    std::complex<double> intSum;

    QVector<std::complex<double>> output;
    output.reserve(K);

    for(int k = 0;k<K;k++)
    {
        intSum = std::complex<double>(0,0);
        for(int n = 0; n<N; n++)
        {
            double realPart = cos(((2*M_PI)/N)*k*n);
            double imagPart = sin(((2*M_PI)/N)*k*n);
            std::complex<double>w(realPart, -imagPart);
            intSum += X[n]*w;
        }
        output.push_back(intSum);
    }
    return output;
}

QVector<std::complex<double> > MainWindow::vecToCompl(QVector<double> arg)
{
    QVector<std::complex<double>> out;
    int N = arg.size();
    out.reserve(N);
    for(int n = 0; n<N;n++)
    {
        std::complex<double>x(arg.at(n),0);
        out.append(x);
    }
    return out;
}

QVector<double> MainWindow::smooth(int buffer, QVector<double> meas)
{
    QVector<double> smoothedVec;
    smoothedVec.reserve(meas.size());
    for(int i = 0; i<meas.size();i++)
    {

    }
    return smoothedVec;
}

void MainWindow::saveToTXT(const QTextEdit* textEdit)
{
    QString text = textEdit->toPlainText();

    QString filePath = QFileDialog::getSaveFileName(nullptr,"Сохранить файл", QString(), "Текстовый файл (*.txt)");

    if(!filePath.isEmpty())
    {
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << text;
            file.close();
            Print(QString("Содержимое сохранено в файл %1").arg(filePath));
        }
        else
        {
            Print(QString("Ошибка при сохранении файла %1").arg(filePath));
        }
    }
    else
    {
        Print("Сохранение файла отменено пользователем");
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->portList->clear();
    QList<QString>check;
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        if(!info.isBusy())
        {
            ui->portList->addItem(info.portName());
            check<<info.portName();
        }
    }
    if(check.isEmpty())
    {
        QMessageBox::warning(this,"Внимание","Порты не найдены.");
    }
    QDate dateToday = QDate::currentDate();
    QString strDateToday;
    strDateToday = dateToday.toString("dd.MM.yyyy");
    ui->outputText->append(strDateToday);



    QThread *thread_New = new QThread;//Создаем поток для порта платы
    Port *PortNew = new Port();//Создаем обьект по классу
    PortNew->moveToThread(thread_New);//помешаем класс  в поток
    PortNew->thisPort.moveToThread(thread_New);//Помещаем сам порт в поток

    connect(PortNew, SIGNAL(error_(QString)), this, SLOT(Print(QString)));//Лог ошибок
    connect(thread_New, SIGNAL(started()), PortNew, SLOT(PortProcessing()));//Переназначения метода run
    connect(PortNew, SIGNAL(finished_Port()), thread_New, SLOT(quit()));//Переназначение метода выход
    connect(thread_New, SIGNAL(finished()), PortNew, SLOT(deleteLater()));//Удалить поток
    connect(PortNew, SIGNAL(finished_Port()), thread_New, SLOT(deleteLater()));//Удалить поток
    connect(this,SIGNAL(savesettings(QString,int,int,int,int,int)),PortNew,SLOT(WritePortSettings(QString,int,int,int,int,int)));//Слот - ввод настроек!
    connect(ui->connectButton, SIGNAL(clicked()),PortNew,SLOT(ConnectPort()));//по нажатию кнопки подключить порт
    connect(ui->disconnectButton, SIGNAL(clicked()),PortNew,SLOT(DisconnectPort()));//по нажатию кнопки отключить порт
    connect(PortNew, SIGNAL(outPort(QString)), this, SLOT(Print(QString)));//вывод в текстовое поле считанных данных
    connect(this,SIGNAL(writeData(QByteArray)),PortNew,SLOT(WriteToPort(QByteArray)));//отправка в порт данных

    // Заполнение combobox
    ui->baudrateList->addItem(QLatin1String("1200"),QSerialPort::Baud1200);
    ui->baudrateList->addItem(QLatin1String("2400"),QSerialPort::Baud2400);
    ui->baudrateList->addItem(QLatin1String("4800"),QSerialPort::Baud4800);
    ui->baudrateList->addItem(QLatin1String("9600"),QSerialPort::Baud9600);
    ui->baudrateList->addItem(QLatin1String("19200"),QSerialPort::Baud19200);
    ui->baudrateList->addItem(QLatin1String("38400"),QSerialPort::Baud38400);
    ui->baudrateList->addItem(QLatin1String("57600"),QSerialPort::Baud57600);
    ui->baudrateList->addItem(QLatin1String("115200"),QSerialPort::Baud115200);
    ui->baudrateList->setCurrentIndex(7);

    ui->cbDataBits->addItem(QLatin1String("5"),QSerialPort::Data5);
    ui->cbDataBits->addItem(QLatin1String("6"),QSerialPort::Data6);
    ui->cbDataBits->addItem(QLatin1String("7"),QSerialPort::Data7);
    ui->cbDataBits->addItem(QLatin1String("8"),QSerialPort::Data8);
    ui->cbDataBits->setCurrentIndex(3);

    ui->cbParity->addItem(QLatin1String("No Parity"),QSerialPort::NoParity);
    ui->cbParity->addItem(QLatin1String("Even"), QSerialPort::EvenParity);
    ui->cbParity->addItem(QLatin1String("Odd"),QSerialPort::OddParity);
    ui->cbParity->addItem(QLatin1String("Space"),QSerialPort::SpaceParity);
    ui->cbParity->addItem(QLatin1String("Mark"),QSerialPort::MarkParity);
    ui->cbParity->setCurrentIndex(0);

    ui->cbStopBits->addItem(QLatin1String("1"),QSerialPort::OneStop);
    ui->cbStopBits->addItem(QLatin1String("1.5"),QSerialPort::OneAndHalfStop);
    ui->cbStopBits->addItem(QLatin1String("2"),QSerialPort::TwoStop);
    ui->cbStopBits->setCurrentIndex(0);

    ui->cbFlowControl->addItem(QLatin1String("No Flow Control"),QSerialPort::NoFlowControl);
    ui->cbFlowControl->addItem(QLatin1String("Hardware Control"), QSerialPort::HardwareControl);
    ui->cbFlowControl->addItem(QLatin1String("Software Control"),QSerialPort::SoftwareControl);
    ui->cbFlowControl->setCurrentIndex(0);
    thread_New->start();

    ui->customPlot->setNoAntialiasingOnDrag(true);
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setName("1 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setName("2 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(Qt::green));
    ui->customPlot->graph(2)->setName("3 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(QPen(Qt::yellow));
    ui->customPlot->graph(3)->setName("4 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(4)->setPen(QPen(Qt::cyan));
    ui->customPlot->graph(4)->setName("5 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(5)->setPen(QPen(Qt::magenta));
    ui->customPlot->graph(5)->setName("6 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(6)->setPen(QPen(Qt::gray));
    ui->customPlot->graph(6)->setName("7 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(7)->setPen(QPen(Qt::darkMagenta));
    ui->customPlot->graph(7)->setName("8 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(8)->setPen(QPen(Qt::darkYellow));
    ui->customPlot->graph(8)->setName("9 канал АЦП");
    ui->customPlot->addGraph();
    ui->customPlot->graph(9)->setPen(QPen(Qt::darkCyan));
    ui->customPlot->graph(9)->setName("10 канал АЦП");
    ui->customPlot->xAxis->setLabel("Время в секундах");
    ui->customPlot->yAxis->setLabel("Напряжение в вольтах");
    ui->customPlot->xAxis->setRange(xmin,xmax);
    ui->customPlot->yAxis->setRange(ymin,ymax);
    for(int i = 0;i<10;i++)
    {
        ui->customPlot->graph(i)->setVisible(false);
    }


    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    ui->customPlot->replot();
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->legend->setVisible(true);

    ui->leAlpha->setText(QString::number(EMA_ALPHA));
    ui->leWindow->setText(QString::number(MA_WINDOW));

    ui->lblADC1->setText(QString::number(adc[0]));
    ui->lblADC2->setText(QString::number(adc[1]));
    ui->lblADC3->setText(QString::number(adc[2]));
    ui->lblADC4->setText(QString::number(adc[3]));
    ui->lblADC5->setText(QString::number(adc[4]));
    ui->lblADC6->setText(QString::number(adc[5]));
    ui->lblADC7->setText(QString::number(adc[6]));
    ui->lblADC8->setText(QString::number(adc[7]));
    ui->lblADC9->setText(QString::number(adc[8]));
    ui->lblADC10->setText(QString::number(adc[9]));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    if(isFirst){
        isFirst=false;
        timing.clear();
        measurement.clear();
        measurement2.clear();
        first = QTime::currentTime();
        Print(first.toString("[hh:mm:ss:zzz]")+" Время отсчета графика зафиксировано");
    }

}

void MainWindow::Print(QString str)
{
    QTime current = QTime::currentTime();
    QString strTimestamp = current.toString("[hh:mm:ss:zzz]");
    double tempsecs = first.msecsTo(current)/1000.0;
    ui->outputText->append(strTimestamp + " " + str);
    QRegExp rx("([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);([0-9]+);\r\n");
    int pos = 0;
    if((pos=rx.indexIn(str,pos))!=-1)
    {


        timing.push_back(tempsecs);
        measurement.push_back(rx.cap(1).toInt()*VREF/SAMPLES);
        measurement2.push_back(rx.cap(2).toInt()*VREF/SAMPLES);
        measurement3.push_back(rx.cap(3).toInt()*VREF/SAMPLES);
        measurement4.push_back(rx.cap(4).toInt()*VREF/SAMPLES);
        measurement5.push_back(rx.cap(5).toInt()*VREF/SAMPLES);
        measurement6.push_back(rx.cap(6).toInt()*VREF/SAMPLES);
        measurement7.push_back(rx.cap(7).toInt()*VREF/SAMPLES);
        measurement8.push_back(rx.cap(8).toInt()*VREF/SAMPLES);
        measurement9.push_back(rx.cap(9).toInt()*VREF/SAMPLES);
        measurement10.push_back(rx.cap(10).toInt()*VREF/SAMPLES);
        filtered.push_back(filterType?emaFilter.filter(measurement.at(measurement.size()-1)):maFilter.filter(measurement.at(measurement.size()-1)));
        filtered2.push_back(filterType?emaFilter2.filter(measurement2.at(measurement2.size()-1)):maFilter2.filter(measurement2.at(measurement2.size()-1)));
        filtered3.push_back(filterType?emaFilter3.filter(measurement3.at(measurement3.size()-1)):maFilter3.filter(measurement3.at(measurement3.size()-1)));
        filtered4.push_back(filterType?emaFilter4.filter(measurement4.at(measurement4.size()-1)):maFilter4.filter(measurement4.at(measurement4.size()-1)));
        filtered5.push_back(filterType?emaFilter5.filter(measurement5.at(measurement5.size()-1)):maFilter5.filter(measurement5.at(measurement5.size()-1)));
        filtered6.push_back(filterType?emaFilter6.filter(measurement6.at(measurement6.size()-1)):maFilter6.filter(measurement6.at(measurement6.size()-1)));
        filtered7.push_back(filterType?emaFilter7.filter(measurement7.at(measurement7.size()-1)):maFilter7.filter(measurement7.at(measurement7.size()-1)));
        filtered8.push_back(filterType?emaFilter8.filter(measurement8.at(measurement8.size()-1)):maFilter8.filter(measurement8.at(measurement8.size()-1)));
        filtered9.push_back(filterType?emaFilter9.filter(measurement9.at(measurement9.size()-1)):maFilter9.filter(measurement9.at(measurement9.size()-1)));
        filtered10.push_back(filterType?emaFilter10.filter(measurement10.at(measurement10.size()-1)):maFilter10.filter(measurement10.at(measurement10.size()-1)));

        ui->lblADC1->setText(QString::number((ui->chFilter1->isChecked()? filtered.last(): measurement.last())));
        ui->lblADC2->setText(QString::number((ui->chFilter2->isChecked()? filtered2.last(): measurement2.last())));
        ui->lblADC3->setText(QString::number((ui->chFilter3->isChecked()? filtered3.last(): measurement3.last())));
        ui->lblADC4->setText(QString::number((ui->chFilter4->isChecked()? filtered4.last(): measurement4.last())));
        ui->lblADC5->setText(QString::number((ui->chFilter5->isChecked()? filtered5.last(): measurement5.last())));
        ui->lblADC6->setText(QString::number((ui->chFilter6->isChecked()? filtered6.last(): measurement6.last())));
        ui->lblADC7->setText(QString::number((ui->chFilter7->isChecked()? filtered7.last(): measurement7.last())));
        ui->lblADC8->setText(QString::number((ui->chFilter8->isChecked()? filtered8.last(): measurement8.last())));
        ui->lblADC9->setText(QString::number((ui->chFilter9->isChecked()? filtered9.last(): measurement9.last())));
        ui->lblADC10->setText(QString::number((ui->chFilter10->isChecked()? filtered10.last(): measurement10.last())));

        ui->customPlot->graph(0)->setData(timing, (ui->chFilter1->isChecked()?filtered:measurement));
        ui->customPlot->graph(1)->setData(timing, (ui->chFilter2->isChecked()?filtered2:measurement2));
        ui->customPlot->graph(2)->setData(timing, (ui->chFilter3->isChecked()?filtered3:measurement3));
        ui->customPlot->graph(3)->setData(timing, (ui->chFilter4->isChecked()?filtered4:measurement4));
        ui->customPlot->graph(4)->setData(timing, (ui->chFilter5->isChecked()?filtered5:measurement5));
        ui->customPlot->graph(5)->setData(timing, (ui->chFilter6->isChecked()?filtered6:measurement6));
        ui->customPlot->graph(6)->setData(timing, (ui->chFilter7->isChecked()?filtered7:measurement7));
        ui->customPlot->graph(7)->setData(timing, (ui->chFilter8->isChecked()?filtered8:measurement8));
        ui->customPlot->graph(8)->setData(timing, (ui->chFilter9->isChecked()?filtered9:measurement9));
        ui->customPlot->graph(9)->setData(timing, (ui->chFilter10->isChecked()?filtered10:measurement10));
        ui->customPlot->replot();
//        if(timing.back()>xmax){
//            xmin = timing.back() - displayRange/2;
//            xmax = timing.back() + displayRange/2;
//            ui->customPlot->xAxis->setRange(xmin, xmax);
//            ui->customPlot->replot();
//        }
        for(int i = 0; i < 10; i++)
        {
            adc[i]=rx.cap(i+1).toInt();
        }
    }

}

void MainWindow::on_portList_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка ComPort:"+arg1);
}

void writeData(QByteArray data)
{

}

void MainWindow::on_baudrateList_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка BaudRate:"+arg1);
}


void MainWindow::on_pushButton_clicked()
{
    double alpha = ui->leAlpha->text().toDouble();
    emaFilter.reInit(alpha);
    emaFilter2.reInit(alpha);
    emaFilter3.reInit(alpha);
    emaFilter4.reInit(alpha);
    emaFilter5.reInit(alpha);
    emaFilter6.reInit(alpha);
    emaFilter7.reInit(alpha);
    emaFilter8.reInit(alpha);
    emaFilter9.reInit(alpha);
    emaFilter10.reInit(alpha);

    filtered.clear();
    filtered2.clear();
    filtered3.clear();
    filtered4.clear();
    filtered5.clear();
    filtered6.clear();
    filtered7.clear();
    filtered8.clear();
    filtered9.clear();
    filtered10.clear();

    for (double value : measurement)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter.filter(value);
        }else{
            filteredValue = maFilter.filter(value);
        }
        filtered.push_back(filteredValue);
    }
    for (double value : measurement2)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter2.filter(value);
        }else{
            filteredValue = maFilter2.filter(value);
        }
        filtered2.push_back(filteredValue);
    }
    for (double value : measurement3)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter3.filter(value);
        }else{
            filteredValue = maFilter3.filter(value);
        }
        filtered3.push_back(filteredValue);
    }
    for (double value : measurement4)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter4.filter(value);
        }else{
            filteredValue = maFilter4.filter(value);
        }
        filtered4.push_back(filteredValue);
    }
    for (double value : measurement5)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter5.filter(value);
        }else{
            filteredValue = maFilter5.filter(value);
        }
        filtered5.push_back(filteredValue);
    }
    for (double value : measurement6)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter6.filter(value);
        }else{
            filteredValue = maFilter6.filter(value);
        }
        filtered6.push_back(filteredValue);
    }
    for (double value : measurement7)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter7.filter(value);
        }else{
            filteredValue = maFilter7.filter(value);
        }
        filtered7.push_back(filteredValue);
    }
    for (double value : measurement8)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter8.filter(value);
        }else{
            filteredValue = maFilter8.filter(value);
        }
        filtered8.push_back(filteredValue);
    }
    for (double value : measurement9)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter9.filter(value);
        }else{
            filteredValue = maFilter9.filter(value);
        }
        filtered9.push_back(filteredValue);
    }
    for (double value : measurement10)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter10.filter(value);
        }else{
            filteredValue = maFilter10.filter(value);
        }
        filtered10.push_back(filteredValue);
    }

    ui->customPlot->graph(0)->setData(timing, (ui->chFilter1->isChecked()?filtered:measurement));
    ui->customPlot->graph(1)->setData(timing, (ui->chFilter2->isChecked()?filtered2:measurement2));
    ui->customPlot->graph(2)->setData(timing, (ui->chFilter3->isChecked()?filtered3:measurement3));
    ui->customPlot->graph(3)->setData(timing, (ui->chFilter4->isChecked()?filtered4:measurement4));
    ui->customPlot->graph(4)->setData(timing, (ui->chFilter5->isChecked()?filtered5:measurement5));
    ui->customPlot->graph(5)->setData(timing, (ui->chFilter6->isChecked()?filtered6:measurement6));
    ui->customPlot->graph(6)->setData(timing, (ui->chFilter7->isChecked()?filtered7:measurement7));
    ui->customPlot->graph(7)->setData(timing, (ui->chFilter8->isChecked()?filtered8:measurement8));
    ui->customPlot->graph(8)->setData(timing, (ui->chFilter9->isChecked()?filtered9:measurement9));
    ui->customPlot->graph(9)->setData(timing, (ui->chFilter10->isChecked()?filtered10:measurement10));
    ui->customPlot->replot();
}


void MainWindow::on_cbDataBits_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка DataBits:"+arg1);
}


void MainWindow::on_cbParity_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка Parity:"+arg1);
}


void MainWindow::on_cbStopBits_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка StopBits:"+arg1);
}


void MainWindow::on_cbFlowControl_currentTextChanged(const QString &arg1)
{
    emit savesettings(ui->portList->currentText(), ui->baudrateList->currentText().toInt(),ui->cbDataBits->currentText().toInt(),
                      ui->cbParity->currentText().toInt(), ui->cbStopBits->currentText().toInt(), ui->cbFlowControl->currentText().toInt());
    Print("Изменена настройка FlowControl:"+arg1);
}

void MainWindow::on_btnUpdatePlotRange_clicked()
{
    xmin = ui->eXmin->text().toDouble();
    xmax = ui->eXmax->text().toDouble();
    ymin = ui->eYmin->text().toDouble();
    ymax = ui->eYmax->text().toDouble();
    ui->customPlot->xAxis->setRange(xmin,xmax);
    ui->customPlot->yAxis->setRange(ymin,ymax);
    ui->customPlot->replot();
}


void MainWindow::on_btnClearPlot_clicked()
{
    timing.clear();
    measurement.clear();
    measurement2.clear();
    measurement3.clear();
    measurement4.clear();
    measurement5.clear();
    measurement6.clear();
    measurement7.clear();
    measurement8.clear();
    measurement9.clear();
    measurement10.clear();
    filtered.clear();
    first = QTime::currentTime();
    xmin = 0;
    xmax = 20;
    ui->customPlot->xAxis->setRange(xmin, xmax);
    Print(first.toString("[hh:mm:ss:zzz]")+" Время отсчета графика зафиксировано");
}

void MainWindow::on_btnVisiblePlot1_clicked()
{
    if(ui->customPlot->graph(0)->visible())
    {
        ui->btnVisiblePlot1->setText("Показать график 1");
        ui->customPlot->graph(0)->setVisible(false);
    }else{
        ui->btnVisiblePlot1->setText("Скрыть график 1");
        ui->customPlot->graph(0)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot2_clicked()
{
    if(ui->customPlot->graph(1)->visible())
    {
        ui->btnVisiblePlot2->setText("Показать график 2");
        ui->customPlot->graph(1)->setVisible(false);
    }else{
        ui->btnVisiblePlot2->setText("Скрыть график 2");
        ui->customPlot->graph(1)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot3_clicked()
{
    if(ui->customPlot->graph(2)->visible())
    {
        ui->btnVisiblePlot3->setText("Показать график 3");
        ui->customPlot->graph(2)->setVisible(false);
    }else{
        ui->btnVisiblePlot3->setText("Скрыть график 3");
        ui->customPlot->graph(2)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot4_clicked()
{
    if(ui->customPlot->graph(3)->visible())
    {
        ui->btnVisiblePlot4->setText("Показать график 4");
        ui->customPlot->graph(3)->setVisible(false);
    }else{
        ui->btnVisiblePlot4->setText("Скрыть график 4");
        ui->customPlot->graph(3)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot5_clicked()
{
    if(ui->customPlot->graph(4)->visible())
    {
        ui->btnVisiblePlot5->setText("Показать график 5");
        ui->customPlot->graph(4)->setVisible(false);
    }else{
        ui->btnVisiblePlot5->setText("Скрыть график 5");
        ui->customPlot->graph(4)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot6_clicked()
{
    if(ui->customPlot->graph(5)->visible())
    {
        ui->btnVisiblePlot6->setText("Показать график 6");
        ui->customPlot->graph(5)->setVisible(false);
    }else{
        ui->btnVisiblePlot6->setText("Скрыть график 6");
        ui->customPlot->graph(5)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot7_clicked()
{
    if(ui->customPlot->graph(6)->visible())
    {
        ui->btnVisiblePlot7->setText("Показать график 7");
        ui->customPlot->graph(6)->setVisible(false);
    }else{
        ui->btnVisiblePlot7->setText("Скрыть график 7");
        ui->customPlot->graph(6)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot8_clicked()
{
    if(ui->customPlot->graph(7)->visible())
    {
        ui->btnVisiblePlot8->setText("Показать график 8");
        ui->customPlot->graph(7)->setVisible(false);
    }else{
        ui->btnVisiblePlot8->setText("Скрыть график 8");
        ui->customPlot->graph(7)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot9_clicked()
{
    if(ui->customPlot->graph(8)->visible())
    {
        ui->btnVisiblePlot9->setText("Показать график 9");
        ui->customPlot->graph(8)->setVisible(false);
    }else{
        ui->btnVisiblePlot9->setText("Скрыть график 9");
        ui->customPlot->graph(8)->setVisible(true);
    }
    ui->customPlot->replot();
}


void MainWindow::on_btnVisiblePlot10_clicked()
{
    if(ui->customPlot->graph(9)->visible())
    {
        ui->btnVisiblePlot10->setText("Показать график 10");
        ui->customPlot->graph(9)->setVisible(false);
    }else{
        ui->btnVisiblePlot10->setText("Скрыть график 10");
        ui->customPlot->graph(9)->setVisible(true);
    }
    ui->customPlot->replot();
}

void MainWindow::on_btnOutputSaver_clicked()
{
    saveToTXT(ui->outputText);
}

void MainWindow::on_btnSaveCSV_clicked()
{

    QVector<QVector<double>> data;

    data.append(timing);
    data.append(measurement);
    data.append(measurement2);
    data.append(measurement3);
    data.append(measurement4);
    data.append(measurement5);
    data.append(measurement6);
    data.append(measurement7);
    data.append(measurement8);
    data.append(measurement9);
    data.append(measurement10);

    SaveDataThread* saveThread = new SaveDataThread(data);
    connect(saveThread,SIGNAL(saveCompleted()),this,SLOT(on_btnSaveCSV_completed()));
    saveThread->start();
}

void MainWindow::on_btnSaveCSV_completed()
{
    Print("Данные успешно сохранены в .CSV таблицу!");
}

#include "mainwindow.moc"

void MainWindow::on_btnChangeFilterType_clicked()
{
    filterType = !filterType;
    ui->btnChangeFilterType->setText(filterType?"Изменить на фильтр с буфером":"Изменить на фильтр экспоненциального скользящего среднего");
}


void MainWindow::on_btnMAWindowEdit_clicked()
{
    int window = ui->leWindow->text().toInt();
    maFilter.reInit(window);
    maFilter2.reInit(window);
    maFilter3.reInit(window);
    maFilter4.reInit(window);
    maFilter5.reInit(window);
    maFilter6.reInit(window);
    maFilter7.reInit(window);
    maFilter8.reInit(window);
    maFilter9.reInit(window);
    maFilter10.reInit(window);

    filtered.clear();
    filtered2.clear();
    filtered3.clear();
    filtered4.clear();
    filtered5.clear();
    filtered6.clear();
    filtered7.clear();
    filtered8.clear();
    filtered9.clear();
    filtered10.clear();

    for (double value : measurement)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter.filter(value);
        }else{
            filteredValue = maFilter.filter(value);
        }
        filtered.push_back(filteredValue);
    }
    for (double value : measurement2)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter2.filter(value);
        }else{
            filteredValue = maFilter2.filter(value);
        }
        filtered2.push_back(filteredValue);
    }
    for (double value : measurement3)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter3.filter(value);
        }else{
            filteredValue = maFilter3.filter(value);
        }
        filtered3.push_back(filteredValue);
    }
    for (double value : measurement4)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter4.filter(value);
        }else{
            filteredValue = maFilter4.filter(value);
        }
        filtered4.push_back(filteredValue);
    }
    for (double value : measurement5)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter5.filter(value);
        }else{
            filteredValue = maFilter5.filter(value);
        }
        filtered5.push_back(filteredValue);
    }
    for (double value : measurement6)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter6.filter(value);
        }else{
            filteredValue = maFilter6.filter(value);
        }
        filtered6.push_back(filteredValue);
    }
    for (double value : measurement7)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter7.filter(value);
        }else{
            filteredValue = maFilter7.filter(value);
        }
        filtered7.push_back(filteredValue);
    }
    for (double value : measurement8)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter8.filter(value);
        }else{
            filteredValue = maFilter8.filter(value);
        }
        filtered8.push_back(filteredValue);
    }
    for (double value : measurement9)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter9.filter(value);
        }else{
            filteredValue = maFilter9.filter(value);
        }
        filtered9.push_back(filteredValue);
    }
    for (double value : measurement10)
    {
        double filteredValue = 0;
        if(filterType){
            filteredValue = emaFilter10.filter(value);
        }else{
            filteredValue = maFilter10.filter(value);
        }
        filtered10.push_back(filteredValue);
    }

    ui->customPlot->graph(0)->setData(timing, (ui->chFilter1->isChecked()?filtered:measurement));
    ui->customPlot->graph(1)->setData(timing, (ui->chFilter2->isChecked()?filtered2:measurement2));
    ui->customPlot->graph(2)->setData(timing, (ui->chFilter3->isChecked()?filtered3:measurement3));
    ui->customPlot->graph(3)->setData(timing, (ui->chFilter4->isChecked()?filtered4:measurement4));
    ui->customPlot->graph(4)->setData(timing, (ui->chFilter5->isChecked()?filtered5:measurement5));
    ui->customPlot->graph(5)->setData(timing, (ui->chFilter6->isChecked()?filtered6:measurement6));
    ui->customPlot->graph(6)->setData(timing, (ui->chFilter7->isChecked()?filtered7:measurement7));
    ui->customPlot->graph(7)->setData(timing, (ui->chFilter8->isChecked()?filtered8:measurement8));
    ui->customPlot->graph(8)->setData(timing, (ui->chFilter9->isChecked()?filtered9:measurement9));
    ui->customPlot->graph(9)->setData(timing, (ui->chFilter10->isChecked()?filtered10:measurement10));
    ui->customPlot->replot();
}

