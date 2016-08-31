#ifndef WEBSOCKETCLIENTQT_H
#define WEBSOCKETCLIENTQT_H

#include <QtWidgets/QMainWindow>
#include <QtWebSockets/QWebSocket>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>

#include "ui_websocketclientqt.h"

class WebSocketClientQt : public QMainWindow
{
	Q_OBJECT
public:
	void changeView(int state);
	explicit WebSocketClientQt(const QUrl &url);
	~WebSocketClientQt();

private:
	QWidget* createAuthPage();
	QWidget* createChatPage();

Q_SIGNALS:
	void closed();

	private Q_SLOTS:
	void onConnectButtonClick();
	void onChatDisconnectButtonClick();
	void onChatSendButtonClick(QString message);
	void onConnected();
	void onTextMessageReceived(QString message);

private:
	Ui::WebSocketClientQtClass ui;
	QStackedWidget *stackedWidget;
	int autoriationWidget, chatWidget;

	QString username;
	QWebSocket webSocket;
	QUrl url;
};

#endif // WEBSOCKETCLIENTQT_H
