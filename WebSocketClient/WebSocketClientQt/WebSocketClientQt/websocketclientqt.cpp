#include "websocketclientqt.h"

QT_USE_NAMESPACE

WebSocketClientQt::WebSocketClientQt(const QUrl &url, QWidget *parent) :
	url(url) {
	ui.setupUi(this);

	stackedWidget = new QStackedWidget;
	autoriationWidget = stackedWidget->addWidget(createAuthPage());
	chatWidget = stackedWidget->addWidget(createChatPage());

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(stackedWidget);
	ui.centralWidget->setLayout(layout);

	changeView(autoriationWidget);
	ui.centralWidget->show();
}

void WebSocketClientQt::onChatDisconnectButtonClick() {
	webSocket.close();
}

void WebSocketClientQt::onChatSendButtonClick() {
	QString msg = messageArea->text();

	QString json = "{\"username\": \"" + username + "\", \"message\": \"" + msg + "\"}";
	QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
	webSocket.sendTextMessage(doc.toJson().data());

	qDebug() << doc.toJson().data();
}

void WebSocketClientQt::onConnectButtonClick() {
	qDebug() << "WebSocket server:" << url;
	chatArea->append("Chat started");
	username = usernameArea->text();

	connect(&webSocket, &QWebSocket::connected, this, &WebSocketClientQt::onConnected, Qt::UniqueConnection);
	connect(&webSocket, &QWebSocket::disconnected, this, &WebSocketClientQt::closed, Qt::QueuedConnection);
	connect(&webSocket, &QWebSocket::disconnected, this, &WebSocketClientQt::onDisconnect, Qt::UniqueConnection);
	webSocket.open(QUrl(url));

	changeView(chatWidget);
}

void WebSocketClientQt::onConnected() {
	qDebug() << "WebSocket connected";
	chatArea->append("Chat connected");
	connect(&webSocket, &QWebSocket::textMessageReceived,
		this, &WebSocketClientQt::onTextMessageReceived);

	QString json = "{\"username\": \"" + username + "\", \"message\": \"connected\"}";
	QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
	webSocket.sendTextMessage(json);
}

void WebSocketClientQt::onDisconnect() {
	chatArea->setText("");
	messageArea->setText("Enter message");

	QString json = "{\"username\": \"" + username + "\", \"message\": \"disconnected\"}";
	QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
	webSocket.sendTextMessage(doc.toJson().data());
	
	changeView(autoriationWidget);

}

void WebSocketClientQt::onTextMessageReceived(QString message) {
	qDebug() << "Message received:" << message;

	QString msg;
	QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());

	// check validity of the document
	if (!doc.isNull()) {
		if (doc.isObject()) {
			QJsonObject obj = doc.object();
				if (obj.contains("username")) {
					QJsonValue value = obj.value(QString("username")).toString();
					msg += value.toString();
					msg += ": ";
				} 

				if (obj.contains("message")) {
					QJsonValue value = obj.value(QString("message")).toString();
					msg += value.toString();
					msg += "\n";
				}

				if (obj.contains("online")) {
					QJsonArray usrs = obj.value("online").toArray();
					usersArea->setText("");
					for (int i = 0; i < usrs.size(); ++i) {
						usersArea->append(usrs.at(i).toString());
					}
				}

		} else {
			qDebug() << "Document is not an object";
		}
	} else {
		qDebug() << "Invalid JSON...";
	}

	chatArea->append(msg);
}

WebSocketClientQt::~WebSocketClientQt() {

}

QWidget* WebSocketClientQt::createAuthPage() {
	QWidget *w = new QWidget;

	QVBoxLayout *layout = new QVBoxLayout(w);
	usernameArea = new QLineEdit();
	usernameArea->setText(tr("Enter username"));
	usernameArea->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::AlignCenter);

	QPushButton *button = new QPushButton(tr("Connect"));
	button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(button, &QPushButton::clicked, this, &WebSocketClientQt::onConnectButtonClick);

	layout->addWidget(usernameArea);
	layout->addWidget(button);
	w->setLayout(layout);

	return w;
}

QWidget* WebSocketClientQt::createChatPage() {
	QWidget *w = new QWidget;

	QVBoxLayout *layout = new QVBoxLayout(w);

	chatArea = new QTextEdit;

	QHBoxLayout *navLayout = new QHBoxLayout(w);
	messageArea = new QLineEdit;
	messageArea->setText(tr("Enter message"));
	messageArea->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::AlignCenter);

	QPushButton *sendButton = new QPushButton(tr("Send"));
	sendButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(sendButton, &QPushButton::clicked, this, &WebSocketClientQt::onChatSendButtonClick);

	QPushButton *disconnectButton = new QPushButton(tr("Disconnect"));
	disconnectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(disconnectButton, &QPushButton::clicked, this, &WebSocketClientQt::onDisconnect);

	usersArea = new QTextEdit;

	navLayout->addWidget(sendButton);
	navLayout->addWidget(disconnectButton);
	navLayout->addWidget(usersArea);
	
	QWidget *nav = new QWidget;
	nav->setLayout(navLayout);

	layout->addWidget(chatArea);
	layout->addWidget(messageArea);
	layout->addWidget(nav);
	w->setLayout(layout);
	
	return w;
}

void WebSocketClientQt::changeView(int state) {
	switch (state) {
	case 0:
		if (stackedWidget->currentIndex() != autoriationWidget) {
			stackedWidget->setCurrentIndex(autoriationWidget);
		}
		return;
	case 1:
		if (stackedWidget->currentIndex() != chatWidget) {
			stackedWidget->setCurrentIndex(chatWidget);
		}
		return;
	default:
		return;
	}

}
