/****************************************************************************
** Meta object code from reading C++ file 'plotsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DataVisualization/plotsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlotSettings_t {
    QByteArrayData data[11];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotSettings_t qt_meta_stringdata_PlotSettings = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlotSettings"
QT_MOC_LITERAL(1, 13, 17), // "xAxisLabelChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "label"
QT_MOC_LITERAL(4, 38, 17), // "yAxisLabelChanged"
QT_MOC_LITERAL(5, 56, 17), // "xAxisRangechanged"
QT_MOC_LITERAL(6, 74, 3), // "low"
QT_MOC_LITERAL(7, 78, 4), // "high"
QT_MOC_LITERAL(8, 83, 17), // "yAxisRangechanged"
QT_MOC_LITERAL(9, 101, 33), // "on_saveSettingsPushButton_cli..."
QT_MOC_LITERAL(10, 135, 35) // "on_cancelSettingsPushButton_c..."

    },
    "PlotSettings\0xAxisLabelChanged\0\0label\0"
    "yAxisLabelChanged\0xAxisRangechanged\0"
    "low\0high\0yAxisRangechanged\0"
    "on_saveSettingsPushButton_clicked\0"
    "on_cancelSettingsPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    2,   50,    2, 0x06 /* Public */,
       8,    2,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlotSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotSettings *_t = static_cast<PlotSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xAxisLabelChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->yAxisLabelChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->xAxisRangechanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->yAxisRangechanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->on_saveSettingsPushButton_clicked(); break;
        case 5: _t->on_cancelSettingsPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlotSettings::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotSettings::xAxisLabelChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PlotSettings::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotSettings::yAxisLabelChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (PlotSettings::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotSettings::xAxisRangechanged)) {
                *result = 2;
            }
        }
        {
            typedef void (PlotSettings::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlotSettings::yAxisRangechanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject PlotSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlotSettings.data,
      qt_meta_data_PlotSettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlotSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlotSettings.stringdata0))
        return static_cast<void*>(const_cast< PlotSettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlotSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void PlotSettings::xAxisLabelChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlotSettings::yAxisLabelChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlotSettings::xAxisRangechanged(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlotSettings::yAxisRangechanged(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
