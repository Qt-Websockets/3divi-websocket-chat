#include <QtCore/QCoreApplication>
#include "websocketserverqt.h"

//#include "vld.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	WebSocketServerQt server(1234);
	return a.exec();
}
