#include "websocketclientqt.h"

QT_USE_NAMESPACE

WebSocketClientQt::WebSocketClientQt(const QUrl &url) :
	url(url) {

	stackedWidget = new QStackedWidget;
	autoriationWidget = stackedWidget->addWidget(createAuthPage());
	chatWidget = stackedWidget->addWidget(createChatPage());
	stackedWidget->setMouseTracking(true);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(stackedWidget);
	ui.centralWidget->setLayout(layout);

	ui.centralWidget->showFullScreen();

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
	webSocket.open(QUrl(url));
}

void WebSocketClientQt::onConnected() {
	qDebug() << "WebSocket connected";
	connect(&webSocket, &QWebSocket::textMessageReceived,
		this, &WebSocketClientQt::onTextMessageReceived);
	webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void WebSocketClientQt::onTextMessageReceived(QString message) {
	qDebug() << "Message received:" << message;
}

WebSocketClientQt::~WebSocketClientQt() {

}

QWidget* WebSocketClientQt::createAuthPage() {
	QWidget *w = new QWidget;
	QPalette pal(palette());

	pal.setColor(QPalette::Background, Qt::black);
	w->setAutoFillBackground(true);
	w->setPalette(pal);

	QVBoxLayout* layout = new QVBoxLayout(w);
	QLabel* label = new QLabel(tr("Камера недоступна"));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::AlignCenter);

	pal.setColor(QPalette::WindowText, Qt::red);
	label->setPalette(pal);

	layout->addWidget(label);
	w->setLayout(layout);
	w->setMouseTracking(true);

	return w;
}

QWidget* WebSocketClientQt::createChatPage() {
	QWidget *w = new QWidget;
	QPalette pal(palette());

	pal.setColor(QPalette::Background, Qt::black);
	w->setAutoFillBackground(true);
	w->setPalette(pal);

	QVBoxLayout* layout = new QVBoxLayout(w);
	QLabel* label = new QLabel(tr("Камера недоступна"));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter | Qt::AlignCenter);

	pal.setColor(QPalette::WindowText, Qt::red);
	label->setPalette(pal);

	layout->addWidget(label);
	w->setLayout(layout);
	w->setMouseTracking(true);

	return w;
}

void WebSocketClientQt::changeView(int state) {
	switch (state) {

	case 0:
		if (stackedWidget->currentIndex() != chatWidget) {
			stackedWidget->setCurrentIndex(chatWidget);
		}
		return;
	case 1:
		if (stackedWidget->currentIndex() != autoriationWidget) {
			stackedWidget->setCurrentIndex(autoriationWidget);
		}
		return;
	default:
		return;
	}

}
