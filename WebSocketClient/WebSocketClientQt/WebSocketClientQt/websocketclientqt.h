#ifndef WEBSOCKETCLIENTQT_H
#define WEBSOCKETCLIENTQT_H

#include <QtWidgets/QMainWindow>
#include "ui_websocketclientqt.h"

class WebSocketClientQt : public QMainWindow
{
	Q_OBJECT

public:
	WebSocketClientQt(QWidget *parent = 0);
	~WebSocketClientQt();

private:
	Ui::WebSocketClientQtClass ui;
};

#endif // WEBSOCKETCLIENTQT_H
