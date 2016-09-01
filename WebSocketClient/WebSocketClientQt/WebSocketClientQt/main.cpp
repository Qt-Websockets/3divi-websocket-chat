#include "websocketclientqt.h"
#include <QtWidgets/QApplication>

#define URL QStringLiteral("ws://192.168.1.81:1234")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	WebSocketClientQt client(QUrl(URL));
	client.show();
	// QObject::connect(&client, &WebSocketClientQt::closed, &a, &QApplication::quit);
	
	return a.exec();
}
