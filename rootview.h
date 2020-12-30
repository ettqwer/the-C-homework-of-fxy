#ifndef ROOTVIEW_H
#define ROOTVIEW_H

#include <QMainWindow>
#include<ALLIN.h>
namespace Ui {
class RootView;
}

class RootView : public QMainWindow
{
    Q_OBJECT

public:
    explicit RootView(QWidget *parent = nullptr);
    ~RootView();
    void ReadSudoFileTOVector();

private slots:
    void on_pb_close_clicked();

    void on_pb_logout_clicked();

    void on_pb_SudoControl_clicked();

    void on_pb_AddUser_clicked();

    void on_pb_SearchUser_clicked();

    void on_pb_DeleteUser_clicked();

private:
    Ui::RootView *ui;

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息
};

#endif // ROOTVIEW_H
