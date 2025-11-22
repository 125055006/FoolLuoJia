#ifndef TEAMENU_H
#define TEAMENU_H

#include <QWidget>

namespace Ui {
class TeaMenu;
}

class TeaMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TeaMenu(QWidget *parent = nullptr);
    ~TeaMenu();

private:
    Ui::TeaMenu *ui;
};

#endif // TEAMENU_H
