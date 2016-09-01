#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QtCore/QDebug>

#include "websocketserverqt.h"

QT_USE_NAMESPACE

WebSocketServerQt::WebSocketServerQt(quint16 port, QObject *parent) :
	QObject(parent),
	pWebSocketServer(Q_NULLPTR),
	clients() {
	pWebSocketServer = new QWebSocketServer(QStringLiteral("Chat Server"),
		QWebSocketServer::NonSecureMode,
		this);
	if (pWebSocketServer->listen(QHostAddress::Any, port)) {
		qDebug() << "Chat Server listening on port" << port;
		connect(pWebSocketServer, &QWebSocketServer::newConnection,
			this, &WebSocketServerQt::onNewConnection);
	}
}

WebSocketServerQt::~WebSocketServerQt() {
	pWebSocketServer->close();
	qDeleteAll(clients.begin(), clients.end());
}

void WebSocketServerQt::onNewConnection() {
	QWebSocket *pSocket = pWebSocketServer->nextPendingConnection();

	connect(pSocket, &QWebSocket::textMessageReceived, this, &WebSocketServerQt::processMessage);
	connect(pSocket, &QWebSocket::disconnected, this, &WebSocketServerQt::socketDisconnected);

	clients << pSocket;
}

void WebSocketServerQt::processMessage(QString message) {
	QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
	Q_FOREACH(QWebSocket *pClient, clients) {
		// if (pClient != pSender) {

		QString username, message;
		QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());

		// check validity of the document
		if (!doc.isNull()) {
			if (doc.isObject()) {
				QJsonObject obj = doc.object();
				if (obj.contains("username")) {
					QJsonValue value = obj.value(QString("username")).toString();
					username += value.toString();
				}

				if (obj.contains("message")) {
					QJsonValue value = obj.value(QString("message")).toString();
					message += value.toString();
				}
			}
			else {
				qDebug() << "Document is not an object";
			}
		}
		else {
			qDebug() << "Invalid JSON...";
		}

		if (!username.isEmpty() || !message.isEmpty()) {
			QString json = "{\"username\": \"" + username + "\", \"message\": \"" + message + "\"}";
			QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());

			pClient->sendTextMessage(doc.toJson().toStdString().data());

			if (message == "connected") {
				usernames.push_back(username);
				json = "{\"online\": ["; 
				for each (QString name in usernames) {
					json += "\"" + name + "\",";
				}
				json += "]}";
				QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
				pClient->sendTextMessage(doc.toJson().toStdString().data());
			}
			if (message == "disconnected") {
				usernames.removeAt(usernames.indexOf(username));
				json = "{\"online\": [";
				for each (QString name in usernames) {
					json += "\"" + name + "\",";
				}
				json += "]}";
				QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
				pClient->sendTextMessage(doc.toJson().toStdString().data());
			}

		}
		// }
	}
}

void WebSocketServerQt::socketDisconnected() {
	QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
	if (pClient) {
		clients.removeAll(pClient);
		pClient->deleteLater();
	}
}
