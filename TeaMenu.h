#ifndef TEAMENU_H
#define TEAMENU_H

#include <QWidget>
#include"recordifm.h"
namespace Ui {
class TeaMenu;
}

class TeaMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TeaMenu(QWidget *parent = nullptr);
    ~TeaMenu();

private slots:
    void on_Return_clicked();

    void on_RecordIFM_clicked();

private:
    Ui::TeaMenu *ui;
    RecordIFM *re_ifm;
};

#endif // TEAMENU_H
