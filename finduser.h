#ifndef FINDUSER_H
#define FINDUSER_H

#include <QMainWindow>
#include<ALLIN.h>
namespace Ui {
class FindUser;
}

class FindUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindUser(QWidget *parent = nullptr);
    ~FindUser();
    void display(int row, QStringList subs);
private slots:
    void on_pb_back_clicked();

    void on_pb_GoSearch_clicked();

private:
    Ui::FindUser *ui;
    QStandardItemModel * model_view;
};

#endif // FINDUSER_H
