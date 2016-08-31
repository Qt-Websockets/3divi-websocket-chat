#ifndef WEBSOCKETCLIENTQT_H
#define WEBSOCKETCLIENTQT_H

#include <QtWidgets/QMainWindow>
#include <QtWebSockets/QWebSocket>

#include "ui_websocketclientqt.h"

class WebSocketClientQt : public QMainWindow
{
	Q_OBJECT
public:
	explicit WebSocketClientQt(const QUrl &url);
	~WebSocketClientQt();

Q_SIGNALS:
	void closed();

	private Q_SLOTS:
	void onConnected();
	void onTextMessageReceived(QString message);

private:
	Ui::WebSocketClientQtClass ui;
	QWebSocket m_webSocket;
	QUrl m_url;
};

#endif // WEBSOCKETCLIENTQT_H
