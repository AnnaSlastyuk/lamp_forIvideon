//==================================================
// Lamp - test task for Ivideon
// Anna Slastyuk
// 09.09.14
//==================================================

#include <QPainter>
#include <QRegExpValidator>
#include <QMessageBox>

#include "lamp.h"
#include "ui_lamp.h"


const QString DEFAULT_HOST_PORT = "127.000.000.001:09999";


TLamp :: TLamp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLamp)
{
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    ui->setupUi(this);

    //mask to write host/port
    ui->leHostName->setInputMask("000.000.000.000:00000");
    ui->leHostName->setText(DEFAULT_HOST_PORT);
    ui->frame->installEventFilter(this);

    //set start lamp features
    lampIsOn = false;
    lampColor = Qt::white;

    //client to connect server
    clientLamp = new TClientLamp();
    connect(clientLamp, SIGNAL(signalCommand(int)), this, SLOT(slotGetCommand(int)));

    //set window size
    setFixedSize(sizeHint());
}

TLamp :: ~TLamp()
{
    delete clientLamp;
    delete ui;
}

//connect to server
void TLamp :: slotBtnConnectClicked()
{
    QString hostPortStr = ui->leHostName->text();
    QStringList list = hostPortStr.split(":");

    if (list.size() != 2) {
        QMessageBox::information(0, tr("Lamp"), tr("Wrong host/port name."));
        return;
    }
    QString hostName = list[0];
    int portID = list[1].toInt();

    clientLamp->connectToServer(hostName, portID);
}

//get command
void TLamp :: slotGetCommand(int command)
{
    switch ((enumCommands)command) {
    case CommandOn:
        lampIsOn = true;
        break;
    case CommandOff:
        lampIsOn = false;
        break;
    case CommandColor:
        lampColor = clientLamp->getColor();
        break;
    default: break;
    }
    repaint();
}

//rewriting paint event for ui->frame to draw lamp
bool TLamp :: eventFilter( QObject * watched, QEvent * event )
{
    if((watched->objectName() == "frame") && (event->type() == QEvent::Paint))
        drawLamp();
    return false;
}

//drawLamp
void TLamp :: drawLamp()
{
    int width = ui->frame->width();
    int height = ui->frame->height();
    int lampHeight = 40;
    int lampHeadHeight = 60;
    int lampLength = 80;
    int lampHeadLength = 30;
    int leftShift = 30;

    QPainter p;
    p.begin(ui->frame);

    //fill background white
    QBrush brushBackground;
    brushBackground.setStyle(Qt::SolidPattern);
    brushBackground.setColor(Qt::white);
    p.setBrush(brushBackground);
    p.drawRect(0,0,width, height);

    //draw lamp
    QLinearGradient linearGradient1;
    linearGradient1.setStart(leftShift + lampLength/2, height/2 - 10);
    linearGradient1.setFinalStop(leftShift + lampLength/2, height/2 + 10);
    linearGradient1.setColorAt(0.0,Qt::lightGray);
    linearGradient1.setColorAt(1.0,Qt::darkGray);

    p.setBrush(linearGradient1);
    p.drawRect(leftShift, height/2 - lampHeight/2, lampLength, lampHeight);

    QLinearGradient linearGradient2;
    linearGradient2.setStart(leftShift + lampLength/2, height/2 - 10);
    linearGradient2.setFinalStop(leftShift + lampLength/2, height/2 + 10);
    linearGradient2.setColorAt(0.0,Qt::lightGray);
    linearGradient2.setColorAt(1.0,Qt::darkGray);

    p.setBrush(linearGradient2);
    p.drawRect(leftShift + lampLength, height/2 - lampHeadHeight/2, lampHeadLength, lampHeadHeight);

    //draw light if lamp is on
    if (lampIsOn) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(lampColor);
        p.setBrush(brush);

        static const QPoint points[4] = {
             QPoint(leftShift + lampLength + lampHeadLength, height/2 - lampHeight/2),
             QPoint(leftShift + lampLength + lampHeadLength, height/2 + lampHeight/2),
             QPoint(width, height),
             QPoint(width, 0)
         };

         p.drawPolygon(points, 4);
    }
    p.end();
}

//exit
void TLamp :: slotBtnExitClicked()
{
    this->close();
}
