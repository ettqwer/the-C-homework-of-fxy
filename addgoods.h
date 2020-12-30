#ifndef ADDGOODS_H
#define ADDGOODS_H

#include <QMainWindow>

namespace Ui {
class AddGoods;
}

class AddGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddGoods(QWidget *parent = nullptr);
    ~AddGoods();

private:
    Ui::AddGoods *ui;
};

#endif // ADDGOODS_H
