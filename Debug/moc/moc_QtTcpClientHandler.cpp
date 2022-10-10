/****************************************************************************
** Meta object code from reading C++ file 'QtTcpClientHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LgNetwork/QtTcpClientHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtTcpClientHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtTcpClientHandler_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtTcpClientHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtTcpClientHandler_t qt_meta_stringdata_QtTcpClientHandler = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QtTcpClientHandler"
QT_MOC_LITERAL(1, 19, 9), // "Connected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "qsServerAddr"
QT_MOC_LITERAL(4, 43, 11), // "nServerPort"
QT_MOC_LITERAL(5, 55, 10), // "Disconnect"
QT_MOC_LITERAL(6, 66, 7), // "RecvTCP"
QT_MOC_LITERAL(7, 74, 5), // "bytes"
QT_MOC_LITERAL(8, 80, 15), // "ConnectedServer"
QT_MOC_LITERAL(9, 96, 18), // "DisConnectedServer"
QT_MOC_LITERAL(10, 115, 7) // "RecvMsg"

    },
    "QtTcpClientHandler\0Connected\0\0"
    "qsServerAddr\0nServerPort\0Disconnect\0"
    "RecvTCP\0bytes\0ConnectedServer\0"
    "DisConnectedServer\0RecvMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtTcpClientHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::QByteArray,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtTcpClientHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtTcpClientHandler *_t = static_cast<QtTcpClientHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Connected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 1: _t->Disconnect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 2: _t->RecvTCP((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->ConnectedServer(); break;
        case 4: _t->DisConnectedServer(); break;
        case 5: _t->RecvMsg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QtTcpClientHandler::*_t)(const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTcpClientHandler::Connected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtTcpClientHandler::*_t)(const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTcpClientHandler::Disconnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QtTcpClientHandler::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtTcpClientHandler::RecvTCP)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtTcpClientHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtTcpClientHandler.data,
      qt_meta_data_QtTcpClientHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtTcpClientHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtTcpClientHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtTcpClientHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtTcpClientHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QtTcpClientHandler::Connected(const QString & _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtTcpClientHandler::Disconnect(const QString & _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtTcpClientHandler::RecvTCP(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
