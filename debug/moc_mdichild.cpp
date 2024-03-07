/****************************************************************************
** Meta object code from reading C++ file 'mdichild.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mdichild.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdichild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MdiChild_t {
    QByteArrayData data[21];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MdiChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MdiChild_t qt_meta_stringdata_MdiChild = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MdiChild"
QT_MOC_LITERAL(1, 9, 14), // "showProblemTab"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "hideProblemTab"
QT_MOC_LITERAL(4, 40, 11), // "resizeEvent"
QT_MOC_LITERAL(5, 52, 13), // "QResizeEvent*"
QT_MOC_LITERAL(6, 66, 5), // "event"
QT_MOC_LITERAL(7, 72, 14), // "faultLinePaint"
QT_MOC_LITERAL(8, 87, 11), // "blockNumber"
QT_MOC_LITERAL(9, 99, 10), // "setFixText"
QT_MOC_LITERAL(10, 110, 4), // "var1"
QT_MOC_LITERAL(11, 115, 4), // "var2"
QT_MOC_LITERAL(12, 120, 19), // "documentWasModified"
QT_MOC_LITERAL(13, 140, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(14, 166, 13), // "newBlockCount"
QT_MOC_LITERAL(15, 180, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(16, 201, 20), // "updateLineNumberArea"
QT_MOC_LITERAL(17, 222, 21), // "showFaultPromptDialog"
QT_MOC_LITERAL(18, 244, 16), // "fixButtonHovered"
QT_MOC_LITERAL(19, 261, 16), // "fixButtonClicked"
QT_MOC_LITERAL(20, 278, 12) // "clearPreview"

    },
    "MdiChild\0showProblemTab\0\0hideProblemTab\0"
    "resizeEvent\0QResizeEvent*\0event\0"
    "faultLinePaint\0blockNumber\0setFixText\0"
    "var1\0var2\0documentWasModified\0"
    "updateLineNumberAreaWidth\0newBlockCount\0"
    "highlightCurrentLine\0updateLineNumberArea\0"
    "showFaultPromptDialog\0fixButtonHovered\0"
    "fixButtonClicked\0clearPreview"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MdiChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   93,    2, 0x0a /* Public */,
       7,    1,   96,    2, 0x0a /* Public */,
       9,    2,   99,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,
      17,    0,  116,    2, 0x08 /* Private */,
      18,    0,  117,    2, 0x08 /* Private */,
      19,    0,  118,    2, 0x08 /* Private */,
      20,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MdiChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MdiChild *_t = static_cast<MdiChild *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showProblemTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->hideProblemTab(); break;
        case 2: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 3: _t->faultLinePaint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setFixText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->documentWasModified(); break;
        case 6: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->highlightCurrentLine(); break;
        case 8: _t->updateLineNumberArea((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 9: _t->updateLineNumberArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateLineNumberArea(); break;
        case 11: _t->showFaultPromptDialog(); break;
        case 12: _t->fixButtonHovered(); break;
        case 13: _t->fixButtonClicked(); break;
        case 14: _t->clearPreview(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MdiChild::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::showProblemTab)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::hideProblemTab)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MdiChild::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_MdiChild.data,
      qt_meta_data_MdiChild,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MdiChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MdiChild::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MdiChild.stringdata0))
        return static_cast<void*>(const_cast< MdiChild*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int MdiChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MdiChild::showProblemTab(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MdiChild::hideProblemTab()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_LineNumberArea_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineNumberArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineNumberArea_t qt_meta_stringdata_LineNumberArea = {
    {
QT_MOC_LITERAL(0, 0, 14) // "LineNumberArea"

    },
    "LineNumberArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineNumberArea[] = {

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

void LineNumberArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LineNumberArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineNumberArea.data,
      qt_meta_data_LineNumberArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LineNumberArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineNumberArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LineNumberArea.stringdata0))
        return static_cast<void*>(const_cast< LineNumberArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int LineNumberArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
