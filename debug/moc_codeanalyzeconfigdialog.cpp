/****************************************************************************
** Meta object code from reading C++ file 'codeanalyzeconfigdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../codeanalyzeconfigdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeanalyzeconfigdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CodeAnalyzeConfigDialog_t {
    QByteArrayData data[6];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeAnalyzeConfigDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeAnalyzeConfigDialog_t qt_meta_stringdata_CodeAnalyzeConfigDialog = {
    {
QT_MOC_LITERAL(0, 0, 23), // "CodeAnalyzeConfigDialog"
QT_MOC_LITERAL(1, 24, 17), // "managePropertySet"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "showRuleDescript"
QT_MOC_LITERAL(4, 60, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 77, 13) // "startAnalysis"

    },
    "CodeAnalyzeConfigDialog\0managePropertySet\0"
    "\0showRuleDescript\0QTreeWidgetItem*\0"
    "startAnalysis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeAnalyzeConfigDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    2,   30,    2, 0x08 /* Private */,
       5,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void,

       0        // eod
};

void CodeAnalyzeConfigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CodeAnalyzeConfigDialog *_t = static_cast<CodeAnalyzeConfigDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->managePropertySet(); break;
        case 1: _t->showRuleDescript((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->startAnalysis(); break;
        default: ;
        }
    }
}

const QMetaObject CodeAnalyzeConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CodeAnalyzeConfigDialog.data,
      qt_meta_data_CodeAnalyzeConfigDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CodeAnalyzeConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeAnalyzeConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CodeAnalyzeConfigDialog.stringdata0))
        return static_cast<void*>(const_cast< CodeAnalyzeConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CodeAnalyzeConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
