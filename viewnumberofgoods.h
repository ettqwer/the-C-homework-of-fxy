#ifndef VIEWNUMBEROFGOODS_H
#define VIEWNUMBEROFGOODS_H

#include <QMainWindow>

namespace Ui {
class ViewNumberOfGoods;
}

class ViewNumberOfGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewNumberOfGoods(QWidget *parent = nullptr);
    ~ViewNumberOfGoods();

private:
    Ui::ViewNumberOfGoods *ui;
};

#endif // VIEWNUMBEROFGOODS_H
