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

void WebSocketClientQt::onChatSendButtonClick(QString message) {
	webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void WebSocketClientQt::onConnectButtonClick() {
	qDebug() << "WebSocket server:" << url;
	connect(&webSocket, &QWebSocket::connected, this, &WebSocketClientQt::onConnected);
	connect(&webSocket, &QWebSocket::disconnected, this, &WebSocketClientQt::closed);
	connect(&webSocket, &QWebSocket::disconnected, this, &WebSocketClientQt::onDisconnect);
	webSocket.open(QUrl(url));
}

void WebSocketClientQt::onConnected() {
	qDebug() << "WebSocket connected";
	connect(&webSocket, &QWebSocket::textMessageReceived,
		this, &WebSocketClientQt::onTextMessageReceived);
	webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void WebSocketClientQt::onDisconnect() {


}

void WebSocketClientQt::onTextMessageReceived(QString message) {
	qDebug() << "Message received:" << message;
}

WebSocketClientQt::~WebSocketClientQt() {

}

QWidget* WebSocketClientQt::createAuthPage() {
	QWidget *w = new QWidget;

	QVBoxLayout *layout = new QVBoxLayout(w);
	QLineEdit *txt = new QLineEdit();
	txt->setText(tr("Enter username"));
	txt->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::AlignCenter);

	QPushButton *button = new QPushButton(tr("Connect"));
	button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(button, &QPushButton::released, this, &WebSocketClientQt::onConnectButtonClick);
	connect(button, &QPushButton::released, this, &WebSocketClientQt::onChangeView);

	layout->addWidget(txt);
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
	connect(sendButton, &QPushButton::released, this, &WebSocketClientQt::onConnectButtonClick);

	QPushButton *disconnectButton = new QPushButton(tr("Disconnect"));
	disconnectButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	connect(disconnectButton, &QPushButton::released, this, &WebSocketClientQt::onDisconnect);
	connect(disconnectButton, &QPushButton::released, this, &WebSocketClientQt::onChangeView);

	navLayout->addWidget(messageArea);
	navLayout->addWidget(sendButton);
	navLayout->addWidget(disconnectButton);
	
	QWidget *nav = new QWidget;
	nav->setLayout(navLayout);

	layout->addWidget(chatArea);
	layout->addWidget(nav);
	w->setLayout(layout);
	
	return w;
}

void WebSocketClientQt::onChangeView() {
	if (stackedWidget->currentIndex() == autoriationWidget) {
		changeView(chatWidget);
	} else {
		changeView(autoriationWidget);
	}
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
