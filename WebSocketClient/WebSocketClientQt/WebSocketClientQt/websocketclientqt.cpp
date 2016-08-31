#include "websocketclientqt.h"

QT_USE_NAMESPACE

//! [constructor]
WebSocketClientQt::WebSocketClientQt(const QUrl &url) :
	m_url(url)
{
	qDebug() << "WebSocket server:" << url;
	connect(&m_webSocket, &QWebSocket::connected, this, &WebSocketClientQt::onConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &WebSocketClientQt::closed);
	m_webSocket.open(QUrl(url));
}
//! [constructor]

//! [onConnected]
void WebSocketClientQt::onConnected()
{
	qDebug() << "WebSocket connected";
	connect(&m_webSocket, &QWebSocket::textMessageReceived,
		this, &WebSocketClientQt::onTextMessageReceived);
	m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}
//! [onConnected]

//! [onTextMessageReceived]
void WebSocketClientQt::onTextMessageReceived(QString message)
{
	qDebug() << "Message received:" << message;
	m_webSocket.close();
}
//! [onTextMessageReceived]

WebSocketClientQt::~WebSocketClientQt()
{

}
