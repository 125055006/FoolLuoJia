#ifndef MYSERVER_H
#define MYSERVER_H

#include<QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QList>
#include<QDebug>
class MyServer :public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent =nullptr);
    bool startServer(quint16 port);      //启动服务器
    void sendToAllClients(const QString &message);    //向所有客户端发信息
    void sendToAllClients(const QByteArray &data);
private slots:
    void onNewConnection();    //处理新客户端的连接
    void onClientReadyRead();    //读取客户端的数据
    void onClientDisconnected();   //处理断开连接的客户端
private:
    QTcpServer *server;
    QList<QTcpSocket*> clients;     //创建数组,储存客户端
};

#endif // MYSERVER_H
