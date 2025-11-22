#ifndef TEALOAD_H
#define TEALOAD_H

#include <QWidget>
#include"TeaMenu.h"
namespace Ui {
class TeaLoad;
}

class TeaLoad : public QWidget
{
    Q_OBJECT

public:
    explicit TeaLoad(QWidget *parent = nullptr);
    ~TeaLoad();

private slots:
    void on_Cancel_clicked();

    void on_Load_clicked();

private:
    Ui::TeaLoad *ui;
    TeaMenu *tea_menu=new TeaMenu;
};

#endif // TEALOAD_H
