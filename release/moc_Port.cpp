/****************************************************************************
** Meta object code from reading C++ file 'Port.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Port.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Port.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Port_t {
    QByteArrayData data[21];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Port_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Port_t qt_meta_stringdata_Port = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Port"
QT_MOC_LITERAL(1, 5, 13), // "finished_Port"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "error_"
QT_MOC_LITERAL(4, 27, 3), // "err"
QT_MOC_LITERAL(5, 31, 7), // "outPort"
QT_MOC_LITERAL(6, 39, 4), // "data"
QT_MOC_LITERAL(7, 44, 14), // "DisconnectPort"
QT_MOC_LITERAL(8, 59, 11), // "ConnectPort"
QT_MOC_LITERAL(9, 71, 17), // "WritePortSettings"
QT_MOC_LITERAL(10, 89, 4), // "name"
QT_MOC_LITERAL(11, 94, 8), // "baudRate"
QT_MOC_LITERAL(12, 103, 8), // "dataBits"
QT_MOC_LITERAL(13, 112, 6), // "parity"
QT_MOC_LITERAL(14, 119, 8), // "stopBits"
QT_MOC_LITERAL(15, 128, 11), // "flowControl"
QT_MOC_LITERAL(16, 140, 14), // "PortProcessing"
QT_MOC_LITERAL(17, 155, 11), // "WriteToPort"
QT_MOC_LITERAL(18, 167, 11), // "HandleError"
QT_MOC_LITERAL(19, 179, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(20, 208, 12) // "ReadFromPort"

    },
    "Port\0finished_Port\0\0error_\0err\0outPort\0"
    "data\0DisconnectPort\0ConnectPort\0"
    "WritePortSettings\0name\0baudRate\0"
    "dataBits\0parity\0stopBits\0flowControl\0"
    "PortProcessing\0WriteToPort\0HandleError\0"
    "QSerialPort::SerialPortError\0ReadFromPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Port[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    6,   73,    2, 0x0a /* Public */,
      16,    0,   86,    2, 0x0a /* Public */,
      17,    1,   87,    2, 0x0a /* Public */,
      18,    1,   90,    2, 0x08 /* Private */,
      20,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,

       0        // eod
};

void Port::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Port *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished_Port(); break;
        case 1: _t->error_((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->outPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->DisconnectPort(); break;
        case 4: _t->ConnectPort(); break;
        case 5: _t->WritePortSettings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 6: _t->PortProcessing(); break;
        case 7: _t->WriteToPort((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->HandleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 9: _t->ReadFromPort(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Port::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::finished_Port)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Port::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::error_)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Port::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Port::outPort)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Port::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Port.data,
    qt_meta_data_Port,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Port::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Port::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Port.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Port::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Port::finished_Port()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Port::error_(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Port::outPort(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
