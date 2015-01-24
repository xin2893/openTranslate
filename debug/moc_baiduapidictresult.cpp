/****************************************************************************
** Meta object code from reading C++ file 'baiduapidictresult.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../baiduapidictresult.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baiduapidictresult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaiduAPIDictResult_t {
    QByteArrayData data[16];
    char stringdata[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaiduAPIDictResult_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaiduAPIDictResult_t qt_meta_stringdata_BaiduAPIDictResult = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BaiduAPIDictResult"
QT_MOC_LITERAL(1, 19, 12), // "bd_get_errno"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "bd_get_word_name"
QT_MOC_LITERAL(4, 50, 11), // "bd_get_from"
QT_MOC_LITERAL(5, 62, 9), // "bd_get_to"
QT_MOC_LITERAL(6, 72, 12), // "bd_get_ph_am"
QT_MOC_LITERAL(7, 85, 12), // "bd_get_ph_en"
QT_MOC_LITERAL(8, 98, 15), // "bd_get_part_num"
QT_MOC_LITERAL(9, 114, 12), // "bd_get_parts"
QT_MOC_LITERAL(10, 127, 1), // "i"
QT_MOC_LITERAL(11, 129, 6), // "bd_ddd"
QT_MOC_LITERAL(12, 136, 16), // "bd_get_means_num"
QT_MOC_LITERAL(13, 153, 6), // "pindex"
QT_MOC_LITERAL(14, 160, 12), // "bd_get_means"
QT_MOC_LITERAL(15, 173, 6) // "mindex"

    },
    "BaiduAPIDictResult\0bd_get_errno\0\0"
    "bd_get_word_name\0bd_get_from\0bd_get_to\0"
    "bd_get_ph_am\0bd_get_ph_en\0bd_get_part_num\0"
    "bd_get_parts\0i\0bd_ddd\0bd_get_means_num\0"
    "pindex\0bd_get_means\0mindex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaiduAPIDictResult[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      14,    2,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::LongLong,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::LongLong,
    QMetaType::QString, QMetaType::LongLong,   10,
    QMetaType::QString,
    QMetaType::LongLong, QMetaType::LongLong,   13,
    QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,   13,   15,

       0        // eod
};

void BaiduAPIDictResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaiduAPIDictResult *_t = static_cast<BaiduAPIDictResult *>(_o);
        switch (_id) {
        case 0: { qint64 _r = _t->bd_get_errno();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->bd_get_word_name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->bd_get_from();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->bd_get_to();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->bd_get_ph_am();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->bd_get_ph_en();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { qint64 _r = _t->bd_get_part_num();
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->bd_get_parts((*reinterpret_cast< qint64(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->bd_ddd();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { qint64 _r = _t->bd_get_means_num((*reinterpret_cast< qint64(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->bd_get_means((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject BaiduAPIDictResult::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaiduAPIDictResult.data,
      qt_meta_data_BaiduAPIDictResult,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaiduAPIDictResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaiduAPIDictResult::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaiduAPIDictResult.stringdata))
        return static_cast<void*>(const_cast< BaiduAPIDictResult*>(this));
    return QObject::qt_metacast(_clname);
}

int BaiduAPIDictResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
