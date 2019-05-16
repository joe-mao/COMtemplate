#ifndef MYTCPCOM_H
#define MYTCPCOM_H

#include <QObject>
#include <QTcpSocket>

class MyTcpCom : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpCom(QObject *parent = nullptr);

signals:
    void connectOKSignal();
    void disconnectOKSignal();
    void stateChangedSignal(QString socketState);


public slots:
    void onConnect(QString hostName,quint16 portName);
    void onDisconnect();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);




private:
    QTcpSocket * mySocket;
};

#endif // MYTCPCOM_H
