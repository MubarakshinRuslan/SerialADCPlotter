#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <complex>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<std::complex<double>> dft(QVector<std::complex<double>> X);
    QVector<std::complex<double>> vecToCompl(QVector<double> arg);
    QVector<double> smooth(int buffer,QVector<double> meas);
    void saveToTXT(const QTextEdit* textEdit);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void savesettings(QString,int,int,int,int,int);
    void writeData(QByteArray);

private slots:
    void on_connectButton_clicked();
    void Print(QString);
    void on_portList_currentTextChanged(const QString &arg1);

    void on_baudrateList_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_cbDataBits_currentTextChanged(const QString &arg1);

    void on_cbParity_currentTextChanged(const QString &arg1);

    void on_cbStopBits_currentTextChanged(const QString &arg1);

    void on_cbFlowControl_currentTextChanged(const QString &arg1);

    void on_btnUpdatePlotRange_clicked();

    void on_btnClearPlot_clicked();

    void on_btnVisiblePlot1_clicked();

    void on_btnVisiblePlot2_clicked();

    void on_btnVisiblePlot3_clicked();

    void on_btnVisiblePlot4_clicked();

    void on_btnVisiblePlot5_clicked();

    void on_btnVisiblePlot6_clicked();

    void on_btnVisiblePlot7_clicked();

    void on_btnVisiblePlot8_clicked();

    void on_btnVisiblePlot9_clicked();

    void on_btnVisiblePlot10_clicked();

    void on_btnOutputSaver_clicked();

    void on_btnSaveCSV_clicked();

    void on_btnSaveCSV_completed();

    void on_btnChangeFilterType_clicked();

    void on_btnMAWindowEdit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
