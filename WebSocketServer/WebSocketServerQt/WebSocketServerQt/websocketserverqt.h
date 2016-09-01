#ifndef WEBSOCKETSERVERQT_H
#define WEBSOCKETSERVERQT_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class WebSocketServerQt : public QObject
{
	Q_OBJECT
public:
	explicit WebSocketServerQt(quint16 port, QObject *parent = Q_NULLPTR);
	virtual ~WebSocketServerQt();

	private Q_SLOTS:
	void onNewConnection();
	void processMessage(QString message);
	void socketDisconnected();

private:
	QWebSocketServer *pWebSocketServer;
	QList<QWebSocket *> clients;
	QList<QString> usernames;
};

#endif // WEBSOCKETSERVERQT_H
