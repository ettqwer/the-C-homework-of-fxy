#ifndef THENUMBEEOFGOODSCHARTS_H
#define THENUMBEEOFGOODSCHARTS_H

#include <QMainWindow>

namespace Ui {
class TheNumbeeOfGoodsCharts;
}

class TheNumbeeOfGoodsCharts : public QMainWindow
{
    Q_OBJECT

public:
    explicit TheNumbeeOfGoodsCharts(QWidget *parent = nullptr);
    ~TheNumbeeOfGoodsCharts();

private:
    Ui::TheNumbeeOfGoodsCharts *ui;
};

#endif // THENUMBEEOFGOODSCHARTS_H
