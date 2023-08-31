#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

struct Settings{
    QString name;
    qint32 baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QSerialPort::FlowControl flowControl;
};

class Port : public QObject
{
    Q_OBJECT
public:
    explicit Port(QObject *parent = 0);
    ~Port();
    QSerialPort thisPort;
    Settings SettingsPort;

signals:
    void finished_Port();
    void error_(QString err);
    void outPort(QString data);

public slots:
    void DisconnectPort();
    void ConnectPort(void);
    void WritePortSettings(QString name, int baudRate, int dataBits, int parity, int stopBits, int flowControl);
    void PortProcessing();
    void WriteToPort(QByteArray data);

private slots:
    void HandleError(QSerialPort::SerialPortError);
    void ReadFromPort();

public:

};

#endif // PORT_H
