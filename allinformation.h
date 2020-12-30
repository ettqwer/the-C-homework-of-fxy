#ifndef ALLINFORMATION_H
#define ALLINFORMATION_H

#include <QMainWindow>

namespace Ui {
class AllInformation;
}

class AllInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllInformation(QWidget *parent = nullptr);
    ~AllInformation();

private:
    Ui::AllInformation *ui;
};

#endif // ALLINFORMATION_H
