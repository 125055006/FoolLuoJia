#ifndef STUMENU_H
#define STUMENU_H

#include <QWidget>
#include"ConsultScore.h"
#include"personcenter.h"
    namespace Ui {
    class StuMenu;
}

class StuMenu : public QWidget
{
    Q_OBJECT

public:
    explicit StuMenu(QWidget *parent = nullptr);
    ~StuMenu();

private slots:
    void on_Return_clicked();
    void on_con_score_clicked();

    void on_Pcenter_clicked();

private:
    Ui::StuMenu *ui;
    ConsultScore *con_score;
    PersonCenter *go_center;
};

#endif // STUMENU_H
