#ifndef SMALL_SHOP_SQL_H
#define SMALL_SHOP_SQL_H

#include <QMainWindow>
#include <ALLIN.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Small_Shop_SQL; }
QT_END_NAMESPACE

class Small_Shop_SQL : public QMainWindow
{
    Q_OBJECT

public:
    Small_Shop_SQL(QWidget *parent = nullptr);
    ~Small_Shop_SQL();
    void ReadUserFileToVector();

private slots:
    void on_pushButton_clicked();

    void on_pb_adduser_clicked();

private:
    Ui::Small_Shop_SQL *ui;
};
#endif // SMALL_SHOP_SQL_H
