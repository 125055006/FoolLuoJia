#ifndef RECORDIFM_H
#define RECORDIFM_H

#include <QWidget>
#include"ui_TeaMenu.h"
#include"stuifm.h"
#include<QDataStream>
#include<QByteArray>
#include<QList>
#include"MyClient.h"
using namespace std;

namespace Ui {
class RecordIFM;
}

class RecordIFM : public QWidget
{
    Q_OBJECT

public:
    QList<Student> students;
    explicit RecordIFM(QWidget *parent = nullptr);
    ~RecordIFM();

private slots:
    void on_Return_clicked();
    void SendIFM();

private:
    Ui::RecordIFM *ui;
    MyClient *client;
};

#endif // RECORDIFM_H
