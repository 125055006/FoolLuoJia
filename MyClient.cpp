#include "MyClient.h"

MyClient::MyClient(QObject *parent):QObject(parent)
{
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,this,&MyClient::onConnected);
    connect(socket,&QTcpSocket::readyRead,this,&MyClient::onReadyRead);
    connect(socket,&QAbstractSocket::errorOccurred,this,&MyClient::onErrorOccurred);
}
void MyClient::connectToServer(const QString &host,quint16 port)
{
    qDebug()<<"尝试连接到服务器:"<<host<<":"<<port;
    socket->connectToHost(host,port);
}
void MyClient::sendMessage(const QString &message)
{
    if(socket->state()==QAbstractSocket::ConnectedState){
        socket->write(message.toUtf8());             //判断是否连接成功
    }
    else{
        qDebug()<<"连接失败";
    }
}
void MyClient::onConnected()
{
    qDebug()<<"连接成功";
    sendMessage("welcome");
}
void MyClient::onReadyRead()
{
    QByteArray data=socket->readAll();
    QString message=QString::fromUtf8(data);
    qDebug()<<"连接错误:"<<socket->errorString();
}
void MyClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    qDebug()<<"连接错误"<<socket->errorString();
}
