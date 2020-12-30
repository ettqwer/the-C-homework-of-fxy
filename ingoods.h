#ifndef INGOODS_H
#define INGOODS_H

#include <QMainWindow>

namespace Ui {
class InGoods;
}

class InGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit InGoods(QWidget *parent = nullptr);
    ~InGoods();

private:
    Ui::InGoods *ui;
};

#endif // INGOODS_H
