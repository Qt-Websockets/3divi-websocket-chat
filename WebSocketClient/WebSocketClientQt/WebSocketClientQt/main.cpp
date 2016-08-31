#include "websocketclientqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	WebSocketClientQt client(QUrl(QStringLiteral("ws://localhost:8081")));
	client.show();
	QObject::connect(&client, &WebSocketClientQt::closed, &a, &QApplication::quit);
	
	return a.exec();
}
