#ifndef WEBSOCKETSERVERQT_H
#define WEBSOCKETSERVERQT_H

#include <QtWidgets/QMainWindow>
#include "ui_websocketserverqt.h"

class WebSocketServerQt : public QMainWindow
{
	Q_OBJECT

public:
	WebSocketServerQt(QWidget *parent = 0);
	~WebSocketServerQt();

private:
	Ui::WebSocketServerQtClass ui;
};

#endif // WEBSOCKETSERVERQT_H
