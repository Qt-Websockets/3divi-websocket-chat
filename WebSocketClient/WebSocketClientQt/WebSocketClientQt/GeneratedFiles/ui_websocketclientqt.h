/********************************************************************************
** Form generated from reading UI file 'websocketclientqt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSOCKETCLIENTQT_H
#define UI_WEBSOCKETCLIENTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebSocketClientQtClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *WebSocketClientQtClass)
    {
        if (WebSocketClientQtClass->objectName().isEmpty())
            WebSocketClientQtClass->setObjectName(QStringLiteral("WebSocketClientQtClass"));
        WebSocketClientQtClass->resize(472, 634);
        centralWidget = new QWidget(WebSocketClientQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        WebSocketClientQtClass->setCentralWidget(centralWidget);

        retranslateUi(WebSocketClientQtClass);

        QMetaObject::connectSlotsByName(WebSocketClientQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebSocketClientQtClass)
    {
        WebSocketClientQtClass->setWindowTitle(QApplication::translate("WebSocketClientQtClass", "WebSocketClientQt", 0));
    } // retranslateUi

};

namespace Ui {
    class WebSocketClientQtClass: public Ui_WebSocketClientQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSOCKETCLIENTQT_H
