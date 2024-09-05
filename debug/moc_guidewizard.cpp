/****************************************************************************
** Meta object code from reading C++ file 'guidewizard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../guidewizard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guidewizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuideWizard_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuideWizard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuideWizard_t qt_meta_stringdata_GuideWizard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GuideWizard"
QT_MOC_LITERAL(1, 12, 14), // "wizardFinished"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "createNewFlag"
QT_MOC_LITERAL(4, 42, 8), // "fileName"
QT_MOC_LITERAL(5, 51, 8), // "filePath"
QT_MOC_LITERAL(6, 60, 10), // "targetLang"
QT_MOC_LITERAL(7, 71, 8) // "showHelp"

    },
    "GuideWizard\0wizardFinished\0\0createNewFlag\0"
    "fileName\0filePath\0targetLang\0showHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuideWizard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GuideWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuideWizard *_t = static_cast<GuideWizard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wizardFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->showHelp(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuideWizard::*_t)(bool , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuideWizard::wizardFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GuideWizard::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_GuideWizard.data,
      qt_meta_data_GuideWizard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuideWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuideWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuideWizard.stringdata0))
        return static_cast<void*>(const_cast< GuideWizard*>(this));
    return QWizard::qt_metacast(_clname);
}

int GuideWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
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
void GuideWizard::wizardFinished(bool _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_IntroPage_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntroPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntroPage_t qt_meta_stringdata_IntroPage = {
    {
QT_MOC_LITERAL(0, 0, 9) // "IntroPage"

    },
    "IntroPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntroPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void IntroPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject IntroPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_IntroPage.data,
      qt_meta_data_IntroPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IntroPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntroPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IntroPage.stringdata0))
        return static_cast<void*>(const_cast< IntroPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int IntroPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_CreateProjectPage_t {
    QByteArrayData data[4];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateProjectPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateProjectPage_t qt_meta_stringdata_CreateProjectPage = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CreateProjectPage"
QT_MOC_LITERAL(1, 18, 19), // "getProjectDirectory"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16) // "getSpecDirectory"

    },
    "CreateProjectPage\0getProjectDirectory\0"
    "\0getSpecDirectory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateProjectPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateProjectPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateProjectPage *_t = static_cast<CreateProjectPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getProjectDirectory(); break;
        case 1: _t->getSpecDirectory(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateProjectPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_CreateProjectPage.data,
      qt_meta_data_CreateProjectPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateProjectPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateProjectPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateProjectPage.stringdata0))
        return static_cast<void*>(const_cast< CreateProjectPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int CreateProjectPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_OpenProjectPage_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenProjectPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenProjectPage_t qt_meta_stringdata_OpenProjectPage = {
    {
QT_MOC_LITERAL(0, 0, 15), // "OpenProjectPage"
QT_MOC_LITERAL(1, 16, 19), // "getProjectDirectory"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16) // "getSpecDirectory"

    },
    "OpenProjectPage\0getProjectDirectory\0"
    "\0getSpecDirectory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenProjectPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OpenProjectPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenProjectPage *_t = static_cast<OpenProjectPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getProjectDirectory(); break;
        case 1: _t->getSpecDirectory(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject OpenProjectPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_OpenProjectPage.data,
      qt_meta_data_OpenProjectPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OpenProjectPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenProjectPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OpenProjectPage.stringdata0))
        return static_cast<void*>(const_cast< OpenProjectPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int OpenProjectPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_ConclusionPage_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConclusionPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConclusionPage_t qt_meta_stringdata_ConclusionPage = {
    {
QT_MOC_LITERAL(0, 0, 14) // "ConclusionPage"

    },
    "ConclusionPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConclusionPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ConclusionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ConclusionPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_ConclusionPage.data,
      qt_meta_data_ConclusionPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConclusionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConclusionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConclusionPage.stringdata0))
        return static_cast<void*>(const_cast< ConclusionPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int ConclusionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
