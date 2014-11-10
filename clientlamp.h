//==================================================
// Lamp - test task for Ivideon
// Anna Slastyuk
// 09.09.14
//==================================================

#ifndef CLIENTLAMP_H
#define CLIENTLAMP_H

#include <QObject>
#include <QColor>
#include <QTcpSocket>

class QTcpSocket;
class QNetworkSession;

//command codes
enum enumCommands
{
    CommandOn = 0x12,
    CommandOff = 0x13,
    CommandColor = 0x20
};

//command structure
struct TLampCommand
 {
    quint8 commandType;
    quint16 commandLength;
    std::vector<quint8> commandValue;
 };

//lamp client class
class TClientLamp : public QObject
{
    Q_OBJECT
public:
    explicit TClientLamp(QObject *parent = 0);
    ~TClientLamp();

public slots:
    void connectToServer(QString hostName, int portID);
    void decipherCommand();
    QColor getColor();

signals:
    void signalCommand(int);

private slots:
    void readServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void connectionClosedByServer();

private:
    QTcpSocket *tcpSocket;
    TLampCommand lampCommand;

};

#endif // CLIENTLAMP_H
