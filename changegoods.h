#ifndef CHANGEGOODS_H
#define CHANGEGOODS_H

#include <QMainWindow>

namespace Ui {
class ChangeGoods;
}

class ChangeGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeGoods(QWidget *parent = nullptr);
    ~ChangeGoods();

private:
    Ui::ChangeGoods *ui;
};

#endif // CHANGEGOODS_H
