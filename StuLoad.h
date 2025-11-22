#ifndef STULOAD_H
#define STULOAD_H

#include <QWidget>
#include"StuMenu.h"
    namespace Ui {
    class StuLoad;
}

class StuLoad : public QWidget
{
    Q_OBJECT

public:
    explicit StuLoad(QWidget *parent = nullptr);
    ~StuLoad();

private slots:
    void on_Cancel_clicked();

    void on_Load_clicked();

private:
    Ui::StuLoad *ui;
    StuMenu *stu_menu=new StuMenu;
};

#endif // STULOAD_H
