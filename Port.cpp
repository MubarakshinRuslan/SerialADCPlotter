#include "Port.h"

Port::Port(QObject *parent) : QObject(parent)
{

}

Port::~Port()
{
    qDebug("Вызван деструктор класса Port");
    emit finished_Port();
}

void Port::PortProcessing()
{
    qDebug("Вызван метод PortProcessing()");
    connect(&thisPort,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(HandleError(QSerialPort::SerialPortError)));
    connect(&thisPort,SIGNAL(readyRead()),this,SLOT(ReadFromPort()));
}

void Port::WritePortSettings(QString name, int baudRate, int dataBits, int parity, int stopBits, int flowControl)
{
    SettingsPort.name = name;
    SettingsPort.baudRate = (QSerialPort::BaudRate) baudRate;
    SettingsPort.dataBits = (QSerialPort::DataBits) dataBits;
    SettingsPort.parity = (QSerialPort::Parity)parity;
    SettingsPort.stopBits = (QSerialPort::StopBits)stopBits;
    SettingsPort.flowControl = (QSerialPort::FlowControl)flowControl;
}

void Port::ConnectPort(void)
{
    thisPort.setPortName(SettingsPort.name);
    if(thisPort.open(QIODevice::ReadWrite)){
        if(thisPort.setBaudRate(SettingsPort.baudRate)
                && thisPort.setDataBits(SettingsPort.dataBits)
                && thisPort.setParity(SettingsPort.parity)
                && thisPort.setStopBits(SettingsPort.stopBits)
                && thisPort.setFlowControl(SettingsPort.flowControl))
        {
            if(thisPort.isOpen()){
                emit error_(SettingsPort.name.toLocal8Bit()+ " >> Открыт!\r");
            }
        }else{
            thisPort.close();
            emit error_(thisPort.errorString().toLocal8Bit());
        }
    }else{
        thisPort.close();
        emit error_(thisPort.errorString().toLocal8Bit());
    }
}

void Port::HandleError(QSerialPort::SerialPortError error)
{
    if((thisPort.isOpen())&&(error==QSerialPort::ResourceError)){
        emit error_(thisPort.errorString().toLocal8Bit());
        DisconnectPort();
    }
}

void Port::DisconnectPort(){
    if(thisPort.isOpen()){
        thisPort.close();
        emit error_(SettingsPort.name.toLocal8Bit()+" >> Закрыт!\r");
    }
}

void Port::WriteToPort(QByteArray data)
{
    if(thisPort.isOpen())
    {
        thisPort.write(data);
    }
}

void Port::ReadFromPort()
{
    QByteArray data;
    data.append(thisPort.readAll());
    emit outPort(data);
}
