#ifndef VIEWALLOFSOLD_H
#define VIEWALLOFSOLD_H

#include <QMainWindow>

namespace Ui {
class ViewAllOfSold;
}

class ViewAllOfSold : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewAllOfSold(QWidget *parent = nullptr);
    ~ViewAllOfSold();

private:
    Ui::ViewAllOfSold *ui;
};

#endif // VIEWALLOFSOLD_H
