#include "websocketclientqt.h"
#include <QtWidgets/QApplication>

#define URL QStringLiteral("ws://localhost:1234")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	WebSocketClientQt client(QUrl(URL));
	client.show();
	// QObject::connect(&client, &WebSocketClientQt::closed, &a, &QApplication::quit);
	
	return a.exec();
}
