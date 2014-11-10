//==================================================
// Lamp - test task for Ivideon
// Anna Slastyuk
// 09.09.14
//==================================================

#include <QtNetwork>
#include <QMessageBox>

#include "clientlamp.h"


TClientLamp :: TClientLamp(QObject *parent) :
    QObject(parent)
{
     tcpSocket = new QTcpSocket(this);
     connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readServer()));
     connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));
     connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(connectionClosedByServer()));
 }

TClientLamp :: ~TClientLamp()
{
    tcpSocket->close();
}

//connect to server with given host, port
 void TClientLamp :: connectToServer(QString hostName, int portID)
 {
     lampCommand.commandType = 0x0;
     lampCommand.commandLength = 0x0;
     lampCommand.commandValue.clear();

     tcpSocket->abort();
     tcpSocket->connectToHost(hostName, portID);
 }

 //read the command from server
 void TClientLamp :: readServer()
 {
     QDataStream in(tcpSocket);
     in.setVersion(QDataStream::Qt_4_0);

     //get command type
     if (tcpSocket->bytesAvailable() < (int)sizeof(quint8))
         return;
     in >> lampCommand.commandType;

     //get command size
     if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
         return;
     in >> lampCommand.commandLength;

     //get command value
     if (tcpSocket->bytesAvailable() < (int)sizeof(quint8)*lampCommand.commandLength)
         return;
     for(uint i=0;i<lampCommand.commandLength;i++) {
         quint8 value;
         in >> value;
         lampCommand.commandValue.push_back(value);
     }

     // decode command
     decipherCommand();
 }


 //if connection closed by server
 void TClientLamp :: connectionClosedByServer()
 {
     QMessageBox::information(0, tr("Lamp"), tr("The connection was closed by server."));
 }

 //display error if any
 void TClientLamp :: displayError(QAbstractSocket::SocketError socketError)
 {
     switch (socketError) {
     case QAbstractSocket::RemoteHostClosedError:
         break;
     case QAbstractSocket::HostNotFoundError:
         QMessageBox::information(0, tr("Lamp"), tr("The host was not found. Please check the "
                                     "host name and port settings."));
         break;
     case QAbstractSocket::ConnectionRefusedError:
         QMessageBox::information(0, tr("Lamp"), tr("The connection was refused. "
                                     "Please check the host name and port settings."));
         break;
     default:
         QMessageBox::information(0, tr("Lamp"),
                                  tr("The following error occurred: %1.").arg(tcpSocket->errorString()));
     }
 }

 //decode command from server
 void TClientLamp::decipherCommand()
 {
     switch((enumCommands)lampCommand.commandType)
     {
     case CommandOn:
         emit signalCommand((int)CommandOn);
         break;
     case CommandOff:
         emit signalCommand((int)CommandOff);
         break;
     case CommandColor:
         emit signalCommand((int)CommandColor);
         break;
     default : break;
     }
 }

 //get color
 QColor TClientLamp :: getColor()
 {
     if(lampCommand.commandValue.size() != 3) {
         QMessageBox::information(0, tr("Lamp"), tr("Failed to get color."));
         return Qt::white;
     }
     QColor color;
     color.setRgb((int)lampCommand.commandValue[0],
                  (int)lampCommand.commandValue[1],
                  (int)lampCommand.commandValue[2]);
     return color;
 }

