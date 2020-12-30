#ifndef DELETEGOODS_H
#define DELETEGOODS_H

#include <QMainWindow>

namespace Ui {
class DeleteGoods;
}

class DeleteGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteGoods(QWidget *parent = nullptr);
    ~DeleteGoods();

private:
    Ui::DeleteGoods *ui;
};

#endif // DELETEGOODS_H
