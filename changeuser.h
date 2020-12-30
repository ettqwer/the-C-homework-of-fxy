#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QMainWindow>

namespace Ui {
class ChangeUser;
}

class ChangeUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeUser(QWidget *parent = nullptr);
    ~ChangeUser();

private:
    Ui::ChangeUser *ui;
};

#endif // CHANGEUSER_H
