/****************************************************************************
** Meta object code from reading C++ file 'challengequestionmanagerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../challengequestionmanagerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'challengequestionmanagerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChallengeQuestionManagerDialog_t {
    QByteArrayData data[14];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChallengeQuestionManagerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChallengeQuestionManagerDialog_t qt_meta_stringdata_ChallengeQuestionManagerDialog = {
    {
QT_MOC_LITERAL(0, 0, 30), // "ChallengeQuestionManagerDialog"
QT_MOC_LITERAL(1, 31, 14), // "applyRequested"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 24), // "ChallengeQuestionManager"
QT_MOC_LITERAL(4, 72, 7), // "manager"
QT_MOC_LITERAL(5, 80, 16), // "questionListName"
QT_MOC_LITERAL(6, 97, 17), // "onCategoryChanged"
QT_MOC_LITERAL(7, 115, 5), // "index"
QT_MOC_LITERAL(8, 121, 13), // "onAddQuestion"
QT_MOC_LITERAL(9, 135, 16), // "onRemoveQuestion"
QT_MOC_LITERAL(10, 152, 13), // "onSaveClicked"
QT_MOC_LITERAL(11, 166, 13), // "onLoadClicked"
QT_MOC_LITERAL(12, 180, 14), // "onApplyClicked"
QT_MOC_LITERAL(13, 195, 14) // "onCloseClicked"

    },
    "ChallengeQuestionManagerDialog\0"
    "applyRequested\0\0ChallengeQuestionManager\0"
    "manager\0questionListName\0onCategoryChanged\0"
    "index\0onAddQuestion\0onRemoveQuestion\0"
    "onSaveClicked\0onLoadClicked\0onApplyClicked\0"
    "onCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChallengeQuestionManagerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,
      12,    0,   66,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChallengeQuestionManagerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChallengeQuestionManagerDialog *_t = static_cast<ChallengeQuestionManagerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applyRequested((*reinterpret_cast< const ChallengeQuestionManager(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onCategoryChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onAddQuestion(); break;
        case 3: _t->onRemoveQuestion(); break;
        case 4: _t->onSaveClicked(); break;
        case 5: _t->onLoadClicked(); break;
        case 6: _t->onApplyClicked(); break;
        case 7: _t->onCloseClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChallengeQuestionManagerDialog::*_t)(const ChallengeQuestionManager & , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChallengeQuestionManagerDialog::applyRequested)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChallengeQuestionManagerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChallengeQuestionManagerDialog.data,
      qt_meta_data_ChallengeQuestionManagerDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChallengeQuestionManagerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChallengeQuestionManagerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChallengeQuestionManagerDialog.stringdata0))
        return static_cast<void*>(const_cast< ChallengeQuestionManagerDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChallengeQuestionManagerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChallengeQuestionManagerDialog::applyRequested(const ChallengeQuestionManager & _t1, const QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
