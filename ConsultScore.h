#ifndef CONSULTSCORE_H
#define CONSULTSCORE_H

#include <QWidget>

namespace Ui {
class ConsultScore;
}

class ConsultScore : public QWidget
{
    Q_OBJECT

public:
    explicit ConsultScore(QWidget *parent = nullptr);
    ~ConsultScore();

private slots:
    void on_Return_clicked();

private:
    Ui::ConsultScore *ui;
};

#endif // CONSULTSCORE_H
