#ifndef MYCLIENT_H
#define MYCLIENT_H

#include<QObject>
#include<QTcpSocket>
#include<QDebug>
class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent=nullptr);
    QTcpSocket* getSocket() const {return socket;} //暴露socket供外部连接
    void connectToServer(const QString &host,quint16 port);
    void sendMessage(const QString &message);
    void sendData(const QByteArray& data);
private slots:
    void onConnected();
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError error);
private:
    QTcpSocket *socket;
};

#endif // MYCLIENT_H
