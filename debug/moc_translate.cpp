/****************************************************************************
** Meta object code from reading C++ file 'translate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../translate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'translate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Translate_t {
    QByteArrayData data[16];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Translate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Translate_t qt_meta_stringdata_Translate = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Translate"
QT_MOC_LITERAL(1, 10, 13), // "dataPostReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "rtext"
QT_MOC_LITERAL(4, 31, 13), // "resultChanged"
QT_MOC_LITERAL(5, 45, 12), // "httpFinished"
QT_MOC_LITERAL(6, 58, 13), // "httpReadyRead"
QT_MOC_LITERAL(7, 72, 22), // "updateDataReadProgress"
QT_MOC_LITERAL(8, 95, 9), // "bytesRead"
QT_MOC_LITERAL(9, 105, 10), // "totalBytes"
QT_MOC_LITERAL(10, 116, 12), // "dictSendWord"
QT_MOC_LITERAL(11, 129, 4), // "word"
QT_MOC_LITERAL(12, 134, 4), // "from"
QT_MOC_LITERAL(13, 139, 2), // "to"
QT_MOC_LITERAL(14, 142, 6), // "result"
QT_MOC_LITERAL(15, 149, 19) // "BaiduAPIDictResult*"

    },
    "Translate\0dataPostReady\0\0rtext\0"
    "resultChanged\0httpFinished\0httpReadyRead\0"
    "updateDataReadProgress\0bytesRead\0"
    "totalBytes\0dictSendWord\0word\0from\0to\0"
    "result\0BaiduAPIDictResult*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Translate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    2,   50,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    3,   55,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,

 // properties: name, type, flags
      14, 0x80000000 | 15, 0x0049510b,

 // properties: notify_signal_id
       1,

       0        // eod
};

void Translate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Translate *_t = static_cast<Translate *>(_o);
        switch (_id) {
        case 0: _t->dataPostReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->resultChanged(); break;
        case 2: _t->httpFinished(); break;
        case 3: _t->httpReadyRead(); break;
        case 4: _t->updateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->dictSendWord((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Translate::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::dataPostReady)) {
                *result = 0;
            }
        }
        {
            typedef void (Translate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::resultChanged)) {
                *result = 1;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BaiduAPIDictResult* >(); break;
        }
    }

}

const QMetaObject Translate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Translate.data,
      qt_meta_data_Translate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Translate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Translate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Translate.stringdata))
        return static_cast<void*>(const_cast< Translate*>(this));
    return QObject::qt_metacast(_clname);
}

int Translate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< BaiduAPIDictResult**>(_v) = result(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setResult(*reinterpret_cast< BaiduAPIDictResult**>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Translate::dataPostReady(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Translate::resultChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
