#ifndef POORUSERVIEW_H
#define POORUSERVIEW_H

#include <QMainWindow>
#include<ALLIN.h>
namespace Ui {
class PoorUserView;
}

class PoorUserView : public QMainWindow
{
    Q_OBJECT

public:
    explicit PoorUserView(QWidget *parent = nullptr);
    ~PoorUserView();

private slots:
    void on_pb_close_clicked();

    void on_pb_logout_clicked();

private:
    Ui::PoorUserView *ui;

signals:
    void PoorSendsignal();//这个函数用户向主界面通知关闭的消息
};

#endif // POORUSERVIEW_H
