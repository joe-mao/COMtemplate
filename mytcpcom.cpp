#include "mytcpcom.h"

MyTcpCom::MyTcpCom(QObject *parent) : QObject(parent)
{
    connect(mySocket, &QTcpSocket::connected, this, &MyTcpCom::connectOKSignal);
    connect(mySocket, &QTcpSocket::disconnected, this, &MyTcpCom::disconnectOKSignal);
    connect(mySocket, &QTcpSocket::stateChanged, this, &MyTcpCom::onSocketStateChanged);



}


void MyTcpCom::onConnect(QString hostName, quint16 portName)
{
    mySocket->connectToHost(hostName, portName);
}

void MyTcpCom::onDisconnect()
{
    mySocket->abort();
}

void MyTcpCom::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState){
    case QAbstractSocket::UnconnectedState:
        emit stateChangedSignal("UnconnectedState"); break;
    case QAbstractSocket::HostLookupState:
        emit stateChangedSignal("HostLookupState"); break;
    case QAbstractSocket::ConnectingState:
        emit stateChangedSignal("ConnectingState"); break;
    case QAbstractSocket::ConnectedState:
        emit stateChangedSignal("ConnectedState"); break;
    case QAbstractSocket::BoundState:
        emit stateChangedSignal("BoundState"); break;
    case QAbstractSocket::ClosingState:
        emit stateChangedSignal("ClosingState"); break;
    case QAbstractSocket::ListeningState:
        emit stateChangedSignal("ListeningState"); break;
    }
}
