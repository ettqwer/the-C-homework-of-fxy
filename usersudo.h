#ifndef USERSUDO_H
#define USERSUDO_H

#include <QMainWindow>
#include<ALLIN.h>
namespace Ui {
class UserSudo;
}

class UserSudo : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserSudo(QWidget *parent = nullptr);
    ~UserSudo();
    void SetSudoControlCbs();
private slots:
    void on_pb_back_clicked();

    void on_pb_Save_clicked();

private:
    Ui::UserSudo *ui;
};

#endif // USERSUDO_H
