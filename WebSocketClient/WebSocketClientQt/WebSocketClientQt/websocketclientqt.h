#ifndef WEBSOCKETCLIENTQT_H
#define WEBSOCKETCLIENTQT_H

#include <QtWidgets/QMainWindow>
#include <QtWebSockets/QWebSocket>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QJsonObject>
#include <QJsonDocument>

#include "ui_websocketclientqt.h"

class WebSocketClientQt : public QMainWindow
{
	Q_OBJECT
public:
	void changeView(int state);
	explicit WebSocketClientQt(const QUrl &url, QWidget *parent = 0);
	~WebSocketClientQt();

private:
	QWidget* createAuthPage();
	QWidget* createChatPage();

Q_SIGNALS:
	void closed();

private Q_SLOTS:
	void onDisconnect();
	void onConnectButtonClick();
	void onChatDisconnectButtonClick();
	void onChatSendButtonClick();
	void onConnected();
	void onTextMessageReceived(QString message);

private:
	Ui::WebSocketClientQtClass ui;
	QStackedWidget *stackedWidget;
	int autoriationWidget, chatWidget;
	QTextEdit *chatArea;
	QLineEdit *messageArea;

	QString username;
	QWebSocket webSocket;
	QUrl url;
};

#endif // WEBSOCKETCLIENTQT_H
