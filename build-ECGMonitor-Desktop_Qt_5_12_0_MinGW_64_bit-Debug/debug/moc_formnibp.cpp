/****************************************************************************
** Meta object code from reading C++ file 'formnibp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ECGMonitor/formnibp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formnibp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormNIBP_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormNIBP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormNIBP_t qt_meta_stringdata_FormNIBP = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FormNIBP"
QT_MOC_LITERAL(1, 9, 15), // "sendNIBPSetData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "mode"
QT_MOC_LITERAL(4, 31, 12), // "sendNIBPData"
QT_MOC_LITERAL(5, 44, 4), // "data"
QT_MOC_LITERAL(6, 49, 26), // "on_startMeasButton_clicked"
QT_MOC_LITERAL(7, 76, 25), // "on_stopMeasButton_clicked"
QT_MOC_LITERAL(8, 102, 39), // "on_nibpModeComboBox_currentIn..."
QT_MOC_LITERAL(9, 142, 4) // "arg1"

    },
    "FormNIBP\0sendNIBPSetData\0\0mode\0"
    "sendNIBPData\0data\0on_startMeasButton_clicked\0"
    "on_stopMeasButton_clicked\0"
    "on_nibpModeComboBox_currentIndexChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormNIBP[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void FormNIBP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormNIBP *_t = static_cast<FormNIBP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendNIBPSetData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendNIBPData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->on_startMeasButton_clicked(); break;
        case 3: _t->on_stopMeasButton_clicked(); break;
        case 4: _t->on_nibpModeComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormNIBP::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormNIBP::sendNIBPSetData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormNIBP::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormNIBP::sendNIBPData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormNIBP::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FormNIBP.data,
    qt_meta_data_FormNIBP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormNIBP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormNIBP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormNIBP.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormNIBP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormNIBP::sendNIBPSetData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormNIBP::sendNIBPData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
