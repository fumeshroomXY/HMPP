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
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdichild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MdiChild_t {
    QByteArrayData data[50];
    char stringdata0[826];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MdiChild_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MdiChild_t qt_meta_stringdata_MdiChild = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MdiChild"
QT_MOC_LITERAL(1, 9, 12), // "showSCMFault"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "hideProblemTab"
QT_MOC_LITERAL(4, 38, 19), // "showHeaderFileIssue"
QT_MOC_LITERAL(5, 58, 19), // "showSourceFileIssue"
QT_MOC_LITERAL(6, 78, 32), // "QList<ClassUndefinedSyntaxIssue>"
QT_MOC_LITERAL(7, 111, 4), // "list"
QT_MOC_LITERAL(8, 116, 21), // "updateToDoRequireNote"
QT_MOC_LITERAL(9, 138, 8), // "filePath"
QT_MOC_LITERAL(10, 147, 21), // "QVector<RequireNote*>"
QT_MOC_LITERAL(11, 169, 4), // "note"
QT_MOC_LITERAL(12, 174, 16), // "updateClassFiles"
QT_MOC_LITERAL(13, 191, 25), // "QHash<QString,ClassInfo>&"
QT_MOC_LITERAL(14, 217, 13), // "classInfoHash"
QT_MOC_LITERAL(15, 231, 21), // "updateInformalSpecPos"
QT_MOC_LITERAL(16, 253, 24), // "QList<InformalSpecInfo>&"
QT_MOC_LITERAL(17, 278, 17), // "informalSpecInfos"
QT_MOC_LITERAL(18, 296, 22), // "updateMethodNameToCode"
QT_MOC_LITERAL(19, 319, 22), // "QHash<QString,QString>"
QT_MOC_LITERAL(20, 342, 16), // "methodNameToCode"
QT_MOC_LITERAL(21, 359, 18), // "startChatGPTDialog"
QT_MOC_LITERAL(22, 378, 19), // "startChatGPTFixCode"
QT_MOC_LITERAL(23, 398, 11), // "resizeEvent"
QT_MOC_LITERAL(24, 410, 13), // "QResizeEvent*"
QT_MOC_LITERAL(25, 424, 5), // "event"
QT_MOC_LITERAL(26, 430, 14), // "faultLinePaint"
QT_MOC_LITERAL(27, 445, 11), // "blockNumber"
QT_MOC_LITERAL(28, 457, 10), // "setFixText"
QT_MOC_LITERAL(29, 468, 4), // "var1"
QT_MOC_LITERAL(30, 473, 4), // "var2"
QT_MOC_LITERAL(31, 478, 17), // "faultFixOkClicked"
QT_MOC_LITERAL(32, 496, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(33, 517, 19), // "documentWasModified"
QT_MOC_LITERAL(34, 537, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(35, 563, 13), // "newBlockCount"
QT_MOC_LITERAL(36, 577, 20), // "updateLineNumberArea"
QT_MOC_LITERAL(37, 598, 21), // "showFaultPromptDialog"
QT_MOC_LITERAL(38, 620, 10), // "lineNumber"
QT_MOC_LITERAL(39, 631, 16), // "fixButtonHovered"
QT_MOC_LITERAL(40, 648, 16), // "fixButtonClicked"
QT_MOC_LITERAL(41, 665, 12), // "clearPreview"
QT_MOC_LITERAL(42, 678, 14), // "highlightMatch"
QT_MOC_LITERAL(43, 693, 19), // "askChatGPTTriggered"
QT_MOC_LITERAL(44, 713, 16), // "fixCodeTriggered"
QT_MOC_LITERAL(45, 730, 15), // "addBugTriggered"
QT_MOC_LITERAL(46, 746, 11), // "updateMatch"
QT_MOC_LITERAL(47, 758, 27), // "updateInformalSpecPosInFile"
QT_MOC_LITERAL(48, 786, 17), // "autoCompleteMatch"
QT_MOC_LITERAL(49, 804, 21) // "moveFaultPromptDialog"

    },
    "MdiChild\0showSCMFault\0\0hideProblemTab\0"
    "showHeaderFileIssue\0showSourceFileIssue\0"
    "QList<ClassUndefinedSyntaxIssue>\0list\0"
    "updateToDoRequireNote\0filePath\0"
    "QVector<RequireNote*>\0note\0updateClassFiles\0"
    "QHash<QString,ClassInfo>&\0classInfoHash\0"
    "updateInformalSpecPos\0QList<InformalSpecInfo>&\0"
    "informalSpecInfos\0updateMethodNameToCode\0"
    "QHash<QString,QString>\0methodNameToCode\0"
    "startChatGPTDialog\0startChatGPTFixCode\0"
    "resizeEvent\0QResizeEvent*\0event\0"
    "faultLinePaint\0blockNumber\0setFixText\0"
    "var1\0var2\0faultFixOkClicked\0"
    "highlightCurrentLine\0documentWasModified\0"
    "updateLineNumberAreaWidth\0newBlockCount\0"
    "updateLineNumberArea\0showFaultPromptDialog\0"
    "lineNumber\0fixButtonHovered\0"
    "fixButtonClicked\0clearPreview\0"
    "highlightMatch\0askChatGPTTriggered\0"
    "fixCodeTriggered\0addBugTriggered\0"
    "updateMatch\0updateInformalSpecPosInFile\0"
    "autoCompleteMatch\0moveFaultPromptDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MdiChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,
       3,    0,  177,    2, 0x06 /* Public */,
       4,    0,  178,    2, 0x06 /* Public */,
       5,    1,  179,    2, 0x06 /* Public */,
       8,    2,  182,    2, 0x06 /* Public */,
      12,    2,  187,    2, 0x06 /* Public */,
      15,    2,  192,    2, 0x06 /* Public */,
      18,    1,  197,    2, 0x06 /* Public */,
      21,    1,  200,    2, 0x06 /* Public */,
      22,    1,  203,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  206,    2, 0x0a /* Public */,
      26,    1,  209,    2, 0x0a /* Public */,
      28,    2,  212,    2, 0x0a /* Public */,
      31,    0,  217,    2, 0x0a /* Public */,
      32,    0,  218,    2, 0x0a /* Public */,
      33,    0,  219,    2, 0x08 /* Private */,
      34,    1,  220,    2, 0x08 /* Private */,
      36,    1,  223,    2, 0x08 /* Private */,
      36,    1,  226,    2, 0x08 /* Private */,
      36,    0,  229,    2, 0x08 /* Private */,
      37,    1,  230,    2, 0x08 /* Private */,
      39,    0,  233,    2, 0x08 /* Private */,
      40,    0,  234,    2, 0x08 /* Private */,
      41,    0,  235,    2, 0x08 /* Private */,
      42,    0,  236,    2, 0x08 /* Private */,
      43,    0,  237,    2, 0x08 /* Private */,
      44,    0,  238,    2, 0x08 /* Private */,
      45,    0,  239,    2, 0x08 /* Private */,
      46,    0,  240,    2, 0x08 /* Private */,
      47,    0,  241,    2, 0x08 /* Private */,
      48,    0,  242,    2, 0x08 /* Private */,
      49,    0,  243,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    9,   14,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,    9,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->showSCMFault((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->hideProblemTab(); break;
        case 2: _t->showHeaderFileIssue(); break;
        case 3: _t->showSourceFileIssue((*reinterpret_cast< const QList<ClassUndefinedSyntaxIssue>(*)>(_a[1]))); break;
        case 4: _t->updateToDoRequireNote((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<RequireNote*>(*)>(_a[2]))); break;
        case 5: _t->updateClassFiles((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,ClassInfo>(*)>(_a[2]))); break;
        case 6: _t->updateInformalSpecPos((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<InformalSpecInfo>(*)>(_a[2]))); break;
        case 7: _t->updateMethodNameToCode((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 8: _t->startChatGPTDialog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->startChatGPTFixCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 11: _t->faultLinePaint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setFixText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->faultFixOkClicked(); break;
        case 14: _t->highlightCurrentLine(); break;
        case 15: _t->documentWasModified(); break;
        case 16: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->updateLineNumberArea((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 18: _t->updateLineNumberArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->updateLineNumberArea(); break;
        case 20: _t->showFaultPromptDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->fixButtonHovered(); break;
        case 22: _t->fixButtonClicked(); break;
        case 23: _t->clearPreview(); break;
        case 24: _t->highlightMatch(); break;
        case 25: _t->askChatGPTTriggered(); break;
        case 26: _t->fixCodeTriggered(); break;
        case 27: _t->addBugTriggered(); break;
        case 28: _t->updateMatch(); break;
        case 29: _t->updateInformalSpecPosInFile(); break;
        case 30: _t->autoCompleteMatch(); break;
        case 31: _t->moveFaultPromptDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MdiChild::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::showSCMFault)) {
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
        {
            typedef void (MdiChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::showHeaderFileIssue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(const QList<ClassUndefinedSyntaxIssue> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::showSourceFileIssue)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(const QString & , const QVector<RequireNote*> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::updateToDoRequireNote)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QString , QHash<QString,ClassInfo> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::updateClassFiles)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QString , QList<InformalSpecInfo> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::updateInformalSpecPos)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QHash<QString,QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::updateMethodNameToCode)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::startChatGPTDialog)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::startChatGPTFixCode)) {
                *result = 9;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void MdiChild::showSCMFault(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MdiChild::hideProblemTab()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MdiChild::showHeaderFileIssue()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MdiChild::showSourceFileIssue(const QList<ClassUndefinedSyntaxIssue> & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MdiChild::updateToDoRequireNote(const QString & _t1, const QVector<RequireNote*> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MdiChild::updateClassFiles(QString _t1, QHash<QString,ClassInfo> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MdiChild::updateInformalSpecPos(QString _t1, QList<InformalSpecInfo> & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MdiChild::updateMethodNameToCode(QHash<QString,QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MdiChild::startChatGPTDialog(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MdiChild::startChatGPTFixCode(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
struct qt_meta_stringdata_LineNumberArea_t {
    QByteArrayData data[3];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineNumberArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineNumberArea_t qt_meta_stringdata_LineNumberArea = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LineNumberArea"
QT_MOC_LITERAL(1, 15, 24), // "updateFaultImagePosition"
QT_MOC_LITERAL(2, 40, 0) // ""

    },
    "LineNumberArea\0updateFaultImagePosition\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineNumberArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void LineNumberArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineNumberArea *_t = static_cast<LineNumberArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateFaultImagePosition(); break;
        default: ;
        }
    }
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
struct qt_meta_stringdata_FoldingWidget_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FoldingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FoldingWidget_t qt_meta_stringdata_FoldingWidget = {
    {
QT_MOC_LITERAL(0, 0, 13) // "FoldingWidget"

    },
    "FoldingWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FoldingWidget[] = {

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

void FoldingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject FoldingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FoldingWidget.data,
      qt_meta_data_FoldingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FoldingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FoldingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FoldingWidget.stringdata0))
        return static_cast<void*>(const_cast< FoldingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FoldingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
