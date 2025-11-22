#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"StuLoad.h"
#include"TeaLoad.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_StuLoad_clicked();

    void on_TeaLoad_clicked();

private:
    Ui::Widget *ui;
    StuLoad *stu_load=new StuLoad;
    TeaLoad *tea_load=new TeaLoad;
};
#endif // WIDGET_H
