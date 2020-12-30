#ifndef SUDONUMBERCHANGE_H
#define SUDONUMBERCHANGE_H

#include <QMainWindow>

namespace Ui {
class SudoNumberChange;
}

class SudoNumberChange : public QMainWindow
{
    Q_OBJECT

public:
    explicit SudoNumberChange(QWidget *parent = nullptr);
    ~SudoNumberChange();

private:
    Ui::SudoNumberChange *ui;
};

#endif // SUDONUMBERCHANGE_H
