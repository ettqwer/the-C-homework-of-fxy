#ifndef SEARCHGOODS_H
#define SEARCHGOODS_H

#include <QMainWindow>

namespace Ui {
class SearchGoods;
}

class SearchGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchGoods(QWidget *parent = nullptr);
    ~SearchGoods();

private:
    Ui::SearchGoods *ui;
};

#endif // SEARCHGOODS_H
