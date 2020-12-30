#ifndef OUTGOODS_H
#define OUTGOODS_H

#include <QMainWindow>

namespace Ui {
class OutGoods;
}

class OutGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit OutGoods(QWidget *parent = nullptr);
    ~OutGoods();

private:
    Ui::OutGoods *ui;
};

#endif // OUTGOODS_H
