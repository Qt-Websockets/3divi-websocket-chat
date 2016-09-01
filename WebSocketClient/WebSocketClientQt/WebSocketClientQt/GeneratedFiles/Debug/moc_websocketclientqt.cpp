/****************************************************************************
** Meta object code from reading C++ file 'websocketclientqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../websocketclientqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websocketclientqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebSocketClientQt_t {
    QByteArrayData data[10];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebSocketClientQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebSocketClientQt_t qt_meta_stringdata_WebSocketClientQt = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WebSocketClientQt"
QT_MOC_LITERAL(1, 18, 6), // "closed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "onDisconnect"
QT_MOC_LITERAL(4, 39, 20), // "onConnectButtonClick"
QT_MOC_LITERAL(5, 60, 27), // "onChatDisconnectButtonClick"
QT_MOC_LITERAL(6, 88, 21), // "onChatSendButtonClick"
QT_MOC_LITERAL(7, 110, 11), // "onConnected"
QT_MOC_LITERAL(8, 122, 21), // "onTextMessageReceived"
QT_MOC_LITERAL(9, 144, 7) // "message"

    },
    "WebSocketClientQt\0closed\0\0onDisconnect\0"
    "onConnectButtonClick\0onChatDisconnectButtonClick\0"
    "onChatSendButtonClick\0onConnected\0"
    "onTextMessageReceived\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebSocketClientQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void WebSocketClientQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebSocketClientQt *_t = static_cast<WebSocketClientQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->onDisconnect(); break;
        case 2: _t->onConnectButtonClick(); break;
        case 3: _t->onChatDisconnectButtonClick(); break;
        case 4: _t->onChatSendButtonClick(); break;
        case 5: _t->onConnected(); break;
        case 6: _t->onTextMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebSocketClientQt::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebSocketClientQt::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WebSocketClientQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WebSocketClientQt.data,
      qt_meta_data_WebSocketClientQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebSocketClientQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebSocketClientQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebSocketClientQt.stringdata0))
        return static_cast<void*>(const_cast< WebSocketClientQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WebSocketClientQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WebSocketClientQt::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
