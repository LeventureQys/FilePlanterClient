/****************************************************************************
** Meta object code from reading C++ file 'StudentFileTransferClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StudentFileTransferClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StudentFileTransferClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FramelessWidget_t {
    QByteArrayData data[11];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FramelessWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FramelessWidget_t qt_meta_stringdata_FramelessWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FramelessWidget"
QT_MOC_LITERAL(1, 16, 22), // "on_btn_connect_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 7), // "RecvTCP"
QT_MOC_LITERAL(4, 48, 5), // "bytes"
QT_MOC_LITERAL(5, 54, 9), // "Connected"
QT_MOC_LITERAL(6, 64, 12), // "qsServerAddr"
QT_MOC_LITERAL(7, 77, 11), // "nServerPort"
QT_MOC_LITERAL(8, 89, 19), // "on_btn_path_clicked"
QT_MOC_LITERAL(9, 109, 19), // "on_btn_test_clicked"
QT_MOC_LITERAL(10, 129, 20) // "on_btn_close_clicked"

    },
    "FramelessWidget\0on_btn_connect_clicked\0"
    "\0RecvTCP\0bytes\0Connected\0qsServerAddr\0"
    "nServerPort\0on_btn_path_clicked\0"
    "on_btn_test_clicked\0on_btn_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FramelessWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    2,   48,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,
       9,    0,   54,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FramelessWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FramelessWidget *_t = static_cast<FramelessWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_connect_clicked(); break;
        case 1: _t->RecvTCP((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->Connected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 3: _t->on_btn_path_clicked(); break;
        case 4: _t->on_btn_test_clicked(); break;
        case 5: _t->on_btn_close_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FramelessWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FramelessWidget.data,
      qt_meta_data_FramelessWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FramelessWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FramelessWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FramelessWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FramelessWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
