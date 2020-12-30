#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QMainWindow>

namespace Ui {
class DeleteUser;
}

class DeleteUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteUser(QWidget *parent = nullptr);
    ~DeleteUser();
    int FindPosVector(std::vector <QString> input , QString number);
    void WriteToUserFile();
private slots:
    void on_pb_back_clicked();

    void on_pb_SearchUser_clicked();

    void on_pb_GoDelete_clicked();

private:
    Ui::DeleteUser *ui;
};

#endif // DELETEUSER_H
