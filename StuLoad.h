#ifndef STULOAD_H
#define STULOAD_H

#include <QWidget>

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

private:
    Ui::StuLoad *ui;
};

#endif // STULOAD_H

