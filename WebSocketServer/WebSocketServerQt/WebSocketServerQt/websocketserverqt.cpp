#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>

#include "websocketserverqt.h"

QT_USE_NAMESPACE

//! [constructor]
WebSocketServerQt::WebSocketServerQt(quint16 port, QObject *parent) :
	QObject(parent),
	m_pWebSocketServer(Q_NULLPTR),
	m_clients()
{
	m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Chat Server"),
		QWebSocketServer::NonSecureMode,
		this);
	if (m_pWebSocketServer->listen(QHostAddress::Any, port))
	{
		qDebug() << "Chat Server listening on port" << port;
		connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
			this, &WebSocketServerQt::onNewConnection);
	}
}

WebSocketServerQt::~WebSocketServerQt()
{
	m_pWebSocketServer->close();
	qDeleteAll(m_clients.begin(), m_clients.end());
}
//! [constructor]

//! [onNewConnection]
void WebSocketServerQt::onNewConnection()
{
	QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

	connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocketServerQt::processMessage);
	connect(pSocket, &QWebSocket::disconnected, this, &WebSocketServerQt::socketDisconnected);

	m_clients << pSocket;
}
//! [onNewConnection]

//! [processMessage]
void WebSocketServerQt::processMessage(QString message)
{
	QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
	Q_FOREACH(QWebSocket *pClient, m_clients)
	{
		if (pClient != pSender) //don't echo message back to sender
		{
			pClient->sendTextMessage(message);
		}
	}
}
//! [processMessage]

//! [socketDisconnected]
void WebSocketServerQt::socketDisconnected()
{
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
	if (pClient)
	{
		m_clients.removeAll(pClient);
		pClient->deleteLater();
	}
}
//! [socketDisconnected]
