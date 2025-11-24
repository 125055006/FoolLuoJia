#ifndef PERSONCENTER_H
#define PERSONCENTER_H

#include <QWidget>
#include<QTableWidgetItem>
#include"recordifm.h"
#include<QDataStream>
#include"MyClient.h"
namespace Ui {
class PersonCenter;
}

class PersonCenter : public QWidget
{
    Q_OBJECT

public:
    explicit PersonCenter(QWidget *parent = nullptr);
    ~PersonCenter();

private slots:
    void on_Return_clicked();
    void onReadyRead();

private:
    Ui::PersonCenter *ui;
    MyClient *client;
};

#endif // PERSONCENTER_H
