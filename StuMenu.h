#ifndef STUMENU_H
#define STUMENU_H

#include <QWidget>

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

private:
    Ui::StuMenu *ui;
};

#endif // STUMENU_H
