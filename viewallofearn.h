#ifndef VIEWALLOFEARN_H
#define VIEWALLOFEARN_H

#include <QMainWindow>

namespace Ui {
class ViewAllOfEarn;
}

class ViewAllOfEarn : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewAllOfEarn(QWidget *parent = nullptr);
    ~ViewAllOfEarn();

private:
    Ui::ViewAllOfEarn *ui;
};

#endif // VIEWALLOFEARN_H
