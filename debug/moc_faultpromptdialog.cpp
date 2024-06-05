/****************************************************************************
** Meta object code from reading C++ file 'faultpromptdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../faultpromptdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'faultpromptdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CustomButton_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomButton_t qt_meta_stringdata_CustomButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CustomButton"
QT_MOC_LITERAL(1, 13, 11), // "enterSignal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11) // "leaveSignal"

    },
    "CustomButton\0enterSignal\0\0leaveSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustomButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomButton *_t = static_cast<CustomButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enterSignal(); break;
        case 1: _t->leaveSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomButton::enterSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CustomButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomButton::leaveSignal)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CustomButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_CustomButton.data,
      qt_meta_data_CustomButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CustomButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CustomButton.stringdata0))
        return static_cast<void*>(const_cast< CustomButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int CustomButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CustomButton::enterSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CustomButton::leaveSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_FaultPromptDialog_t {
    QByteArrayData data[15];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FaultPromptDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FaultPromptDialog_t qt_meta_stringdata_FaultPromptDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FaultPromptDialog"
QT_MOC_LITERAL(1, 18, 13), // "clickedSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "enteredSignal"
QT_MOC_LITERAL(4, 47, 14), // "releasedSignal"
QT_MOC_LITERAL(5, 62, 10), // "leftSignal"
QT_MOC_LITERAL(6, 73, 11), // "unfixSignal"
QT_MOC_LITERAL(7, 85, 9), // "okclicked"
QT_MOC_LITERAL(8, 95, 15), // "okButtonClicked"
QT_MOC_LITERAL(9, 111, 16), // "showRuleDescript"
QT_MOC_LITERAL(10, 128, 16), // "fixButtonClicked"
QT_MOC_LITERAL(11, 145, 16), // "fixButtonEntered"
QT_MOC_LITERAL(12, 162, 17), // "fixButtonReleased"
QT_MOC_LITERAL(13, 180, 13), // "fixButtonLeft"
QT_MOC_LITERAL(14, 194, 18) // "unfixButtonClicked"

    },
    "FaultPromptDialog\0clickedSignal\0\0"
    "enteredSignal\0releasedSignal\0leftSignal\0"
    "unfixSignal\0okclicked\0okButtonClicked\0"
    "showRuleDescript\0fixButtonClicked\0"
    "fixButtonEntered\0fixButtonReleased\0"
    "fixButtonLeft\0unfixButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FaultPromptDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FaultPromptDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FaultPromptDialog *_t = static_cast<FaultPromptDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedSignal(); break;
        case 1: _t->enteredSignal(); break;
        case 2: _t->releasedSignal(); break;
        case 3: _t->leftSignal(); break;
        case 4: _t->unfixSignal(); break;
        case 5: _t->okclicked(); break;
        case 6: _t->okButtonClicked(); break;
        case 7: _t->showRuleDescript(); break;
        case 8: _t->fixButtonClicked(); break;
        case 9: _t->fixButtonEntered(); break;
        case 10: _t->fixButtonReleased(); break;
        case 11: _t->fixButtonLeft(); break;
        case 12: _t->unfixButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::clickedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::enteredSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::releasedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::leftSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::unfixSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FaultPromptDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FaultPromptDialog::okclicked)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FaultPromptDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FaultPromptDialog.data,
      qt_meta_data_FaultPromptDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FaultPromptDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FaultPromptDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FaultPromptDialog.stringdata0))
        return static_cast<void*>(const_cast< FaultPromptDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FaultPromptDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FaultPromptDialog::clickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FaultPromptDialog::enteredSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FaultPromptDialog::releasedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void FaultPromptDialog::leftSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void FaultPromptDialog::unfixSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void FaultPromptDialog::okclicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
