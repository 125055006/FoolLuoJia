#include "MyServer.h"

MyServer::MyServer(QObject *parent):QObject(parent)
{
    server=new QTcpServer(this);
    connect(server,&QTcpServer::newConnection,this,&MyServer::onNewConnection);  //获得连接信号
}

bool MyServer::startServer(quint16 port)   //判断是否启动成功
{
    if(!server->listen(QHostAddress::Any,port))
    {
        qDebug()<<"启动失败:"<<server->errorString();    //检测是否监成功
        return false;
    }
    qDebug()<<"启动成功，监听中："<<port;
    return true;
}
void MyServer::onNewConnection()
{
    QTcpSocket *clientSocket=server->nextPendingConnection(); //接收新的客户端
    clients.append(clientSocket);     //将新的客户端加入数组
    qDebug()<<"客户端连接："<<clientSocket->peerAddress().toString()<<":"<<clientSocket->peerPort();   //获取IP地址和端口号
    qDebug()<<"已连接"<<clients.size()<<"个客户端";
    connect(clientSocket,&QTcpSocket::readyRead,this,&::MyServer::onClientReadyRead);
    connect(clientSocket,&QTcpSocket::disconnected,this,&MyServer::onClientDisconnected);
    QString welcome="welcome";
    clientSocket->write(welcome.toUtf8());
}
void MyServer::onClientReadyRead()
{
    QTcpSocket *clientSocket=qobject_cast<QTcpSocket*>(sender());  //获取指针
    if(!clientSocket) return;
    QByteArray data=clientSocket->readAll();
    qDebug()<<"收到大小为"<<data.size()<<"的数据";
    sendToAllClients(data);
}
void MyServer::onClientDisconnected()
{
    QTcpSocket *clientSocket=qobject_cast<QTcpSocket*>(sender()); //获取指针对象
    if(!clientSocket) return;               //检查空指针
    clients.removeOne(clientSocket);   //移除断开客户端
    qDebug()<<clientSocket->peerAddress().toString()<<"断开连接";
    qDebug()<<"剩余"<<clients.size()<<"个客户端";
    clientSocket->deleteLater();     //删除对象
}
void MyServer::sendToAllClients(const QString &message)
{
    QByteArray data=message.toUtf8();
    for(QTcpSocket *client:clients)
    {
        if(client->state()==QTcpSocket::ConnectedState)
        {
            client->write(data);
        }
    }
}
void MyServer::sendToAllClients(const QByteArray &data)
{
    qDebug()<<"开始转发";
    for(QTcpSocket *client:clients)
    {
        if(client->state()==QTcpSocket::ConnectedState)
        {
            client->write(data);
        }
    }
}
