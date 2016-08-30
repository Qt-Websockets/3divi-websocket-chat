#include "websocketclientqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WebSocketClientQt w;
	w.show();
	return a.exec();
}
