/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ECGMonitor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "menuSetUART"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "menuOpen"
QT_MOC_LITERAL(4, 33, 10), // "initSerial"
QT_MOC_LITERAL(5, 44, 7), // "portNum"
QT_MOC_LITERAL(6, 52, 8), // "baudRate"
QT_MOC_LITERAL(7, 61, 8), // "dataBits"
QT_MOC_LITERAL(8, 70, 8), // "stopBits"
QT_MOC_LITERAL(9, 79, 6), // "parity"
QT_MOC_LITERAL(10, 86, 8), // "isOpened"
QT_MOC_LITERAL(11, 95, 10), // "readSerial"
QT_MOC_LITERAL(12, 106, 11), // "writeSerial"
QT_MOC_LITERAL(13, 118, 4), // "data"
QT_MOC_LITERAL(14, 123, 10), // "recPrbType"
QT_MOC_LITERAL(15, 134, 4), // "type"
QT_MOC_LITERAL(16, 139, 14), // "recNIBPSetData"
QT_MOC_LITERAL(17, 154, 4), // "mode"
QT_MOC_LITERAL(18, 159, 11), // "recRespGain"
QT_MOC_LITERAL(19, 171, 4), // "gain"
QT_MOC_LITERAL(20, 176, 11), // "recSPO2Data"
QT_MOC_LITERAL(21, 188, 4), // "sens"
QT_MOC_LITERAL(22, 193, 10), // "recECGData"
QT_MOC_LITERAL(23, 204, 5), // "lead1"
QT_MOC_LITERAL(24, 210, 5), // "gain1"
QT_MOC_LITERAL(25, 216, 5), // "lead2"
QT_MOC_LITERAL(26, 222, 5) // "gain2"

    },
    "MainWindow\0menuSetUART\0\0menuOpen\0"
    "initSerial\0portNum\0baudRate\0dataBits\0"
    "stopBits\0parity\0isOpened\0readSerial\0"
    "writeSerial\0data\0recPrbType\0type\0"
    "recNIBPSetData\0mode\0recRespGain\0gain\0"
    "recSPO2Data\0sens\0recECGData\0lead1\0"
    "gain1\0lead2\0gain2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    6,   66,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      14,    2,   83,    2, 0x08 /* Private */,
      16,    1,   88,    2, 0x08 /* Private */,
      18,    2,   91,    2, 0x08 /* Private */,
      20,    2,   96,    2, 0x08 /* Private */,
      22,    5,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   15,   13,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   19,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   21,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QByteArray,   23,   24,   25,   26,   13,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuSetUART(); break;
        case 1: _t->menuOpen(); break;
        case 2: _t->initSerial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 3: _t->readSerial(); break;
        case 4: _t->writeSerial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->recPrbType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->recNIBPSetData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->recRespGain((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 8: _t->recSPO2Data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 9: _t->recECGData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QByteArray(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
