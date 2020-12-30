#ifndef ADD_USER_H
#define ADD_USER_H

#include <QMainWindow>
#include<ALLIN.h>
namespace Ui {
class Add_User;
}

class Add_User : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_User(QWidget *parent = nullptr);
    ~Add_User();

private slots:
    void on_pb_back_clicked();

    void on_pb_GoAdd_clicked();

    bool isDigitString(const QString& src);
private:
    Ui::Add_User *ui;
};

#endif // ADD_USER_H
