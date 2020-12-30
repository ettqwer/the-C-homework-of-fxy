#ifndef VIEWEARNOFGOODS_H
#define VIEWEARNOFGOODS_H

#include <QMainWindow>

namespace Ui {
class ViewEarnOfGoods;
}

class ViewEarnOfGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewEarnOfGoods(QWidget *parent = nullptr);
    ~ViewEarnOfGoods();

private:
    Ui::ViewEarnOfGoods *ui;
};

#endif // VIEWEARNOFGOODS_H
