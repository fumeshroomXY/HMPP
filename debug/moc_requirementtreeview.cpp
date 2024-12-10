/****************************************************************************
** Meta object code from reading C++ file 'requirementtreeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../requirementtreeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requirementtreeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RequirementTreeView_t {
    QByteArrayData data[4];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RequirementTreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RequirementTreeView_t qt_meta_stringdata_RequirementTreeView = {
    {
QT_MOC_LITERAL(0, 0, 19), // "RequirementTreeView"
QT_MOC_LITERAL(1, 20, 8), // "complete"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5) // "index"

    },
    "RequirementTreeView\0complete\0\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RequirementTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void RequirementTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RequirementTreeView *_t = static_cast<RequirementTreeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RequirementTreeView::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RequirementTreeView::complete)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RequirementTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_RequirementTreeView.data,
      qt_meta_data_RequirementTreeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RequirementTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RequirementTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RequirementTreeView.stringdata0))
        return static_cast<void*>(const_cast< RequirementTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int RequirementTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RequirementTreeView::complete(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ToDoTableView_t {
    QByteArrayData data[4];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToDoTableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToDoTableView_t qt_meta_stringdata_ToDoTableView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ToDoTableView"
QT_MOC_LITERAL(1, 14, 8), // "complete"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5) // "index"

    },
    "ToDoTableView\0complete\0\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToDoTableView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void ToDoTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToDoTableView *_t = static_cast<ToDoTableView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToDoTableView::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToDoTableView::complete)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ToDoTableView::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_ToDoTableView.data,
      qt_meta_data_ToDoTableView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ToDoTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToDoTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ToDoTableView.stringdata0))
        return static_cast<void*>(const_cast< ToDoTableView*>(this));
    return QTableView::qt_metacast(_clname);
}

int ToDoTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ToDoTableView::complete(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_BuildProFromSpecDialog_t {
    QByteArrayData data[7];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BuildProFromSpecDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BuildProFromSpecDialog_t qt_meta_stringdata_BuildProFromSpecDialog = {
    {
QT_MOC_LITERAL(0, 0, 22), // "BuildProFromSpecDialog"
QT_MOC_LITERAL(1, 23, 18), // "treeStructureReady"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "QList<ClassInfo>"
QT_MOC_LITERAL(4, 60, 13), // "treeStructure"
QT_MOC_LITERAL(5, 74, 11), // "onOkClicked"
QT_MOC_LITERAL(6, 86, 15) // "onCancelClicked"

    },
    "BuildProFromSpecDialog\0treeStructureReady\0"
    "\0QList<ClassInfo>\0treeStructure\0"
    "onOkClicked\0onCancelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BuildProFromSpecDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BuildProFromSpecDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BuildProFromSpecDialog *_t = static_cast<BuildProFromSpecDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->treeStructureReady((*reinterpret_cast< const QList<ClassInfo>(*)>(_a[1]))); break;
        case 1: _t->onOkClicked(); break;
        case 2: _t->onCancelClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BuildProFromSpecDialog::*_t)(const QList<ClassInfo> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BuildProFromSpecDialog::treeStructureReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BuildProFromSpecDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BuildProFromSpecDialog.data,
      qt_meta_data_BuildProFromSpecDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BuildProFromSpecDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuildProFromSpecDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BuildProFromSpecDialog.stringdata0))
        return static_cast<void*>(const_cast< BuildProFromSpecDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BuildProFromSpecDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void BuildProFromSpecDialog::treeStructureReady(const QList<ClassInfo> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SameNameMethodHandleDialog_t {
    QByteArrayData data[5];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SameNameMethodHandleDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SameNameMethodHandleDialog_t qt_meta_stringdata_SameNameMethodHandleDialog = {
    {
QT_MOC_LITERAL(0, 0, 26), // "SameNameMethodHandleDialog"
QT_MOC_LITERAL(1, 27, 16), // "onReplaceClicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 15), // "onAddNewClicked"
QT_MOC_LITERAL(4, 61, 15) // "onCancelClicked"

    },
    "SameNameMethodHandleDialog\0onReplaceClicked\0"
    "\0onAddNewClicked\0onCancelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SameNameMethodHandleDialog[] = {

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
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SameNameMethodHandleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SameNameMethodHandleDialog *_t = static_cast<SameNameMethodHandleDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onReplaceClicked(); break;
        case 1: _t->onAddNewClicked(); break;
        case 2: _t->onCancelClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SameNameMethodHandleDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SameNameMethodHandleDialog.data,
      qt_meta_data_SameNameMethodHandleDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SameNameMethodHandleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SameNameMethodHandleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SameNameMethodHandleDialog.stringdata0))
        return static_cast<void*>(const_cast< SameNameMethodHandleDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SameNameMethodHandleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
