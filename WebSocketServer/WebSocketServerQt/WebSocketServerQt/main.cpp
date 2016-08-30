#include "websocketserverqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WebSocketServerQt w;
	w.show();
	return a.exec();
}
