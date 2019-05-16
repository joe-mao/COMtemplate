#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mytcpcom.h"
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private:
    void onConnectTcpOK();

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    MyTcpCom * mytcp;
    bool connectState = false;
    QLabel * labelSocketState;
};

#endif // WIDGET_H
