/****************************************************************************
** Meta object code from reading C++ file 'alg.h'
**
** Created: Mon 31. Mar 19:46:56 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../alg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Alg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      48,    5,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Alg[] = {
    "Alg\0\0xmin,xmax,ymin,ymax,height,velocity,degree\0"
    "paint(double,double,double,double,double,double,double)\0"
};

const QMetaObject Alg::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Alg,
      qt_meta_data_Alg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Alg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Alg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Alg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Alg))
        return static_cast<void*>(const_cast< Alg*>(this));
    return QLabel::qt_metacast(_clname);
}

int Alg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: paint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
