#ifndef WEBSOCKETSERVERQT_H
#define WEBSOCKETSERVERQT_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

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
	QWebSocketServer *m_pWebSocketServer;
	QList<QWebSocket *> m_clients;
};

#endif // WEBSOCKETSERVERQT_H
