//==================================================
// Lamp - test task for Ivideon
// Anna Slastyuk
// 09.09.14
//==================================================

#ifndef LAMP_H
#define LAMP_H

#include <QWidget>

#include "clientlamp.h"

namespace Ui {
class TLamp;
}

//lamp class
class TLamp : public QWidget
{
    Q_OBJECT

public:
    explicit TLamp(QWidget *parent = 0);
    ~TLamp();

private:
    Ui::TLamp *ui;
    TClientLamp *clientLamp;            //client

protected:
    bool eventFilter ( QObject * watched, QEvent * event );

private:
    bool lampIsOn;                      //if the lamp is on
    QColor lampColor;                   //lamp color

    void drawLamp();                    //drawLamp on the frame

private slots:
    void slotBtnConnectClicked();       //connect to server
    void slotBtnExitClicked();          //exit
    void slotGetCommand(int command);   //get command
};

#endif // LAMP_H
