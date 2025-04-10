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
    QByteArrayData data[71];
    char stringdata0[1222];
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
QT_MOC_LITERAL(23, 398, 25), // "allSegmentsReviewComplete"
QT_MOC_LITERAL(24, 424, 13), // "reportBugLine"
QT_MOC_LITERAL(25, 438, 21), // "challengeQuestionFlag"
QT_MOC_LITERAL(26, 460, 10), // "currentStr"
QT_MOC_LITERAL(27, 471, 12), // "CodeElements"
QT_MOC_LITERAL(28, 484, 5), // "flags"
QT_MOC_LITERAL(29, 490, 11), // "resizeEvent"
QT_MOC_LITERAL(30, 502, 13), // "QResizeEvent*"
QT_MOC_LITERAL(31, 516, 5), // "event"
QT_MOC_LITERAL(32, 522, 14), // "faultLinePaint"
QT_MOC_LITERAL(33, 537, 11), // "blockNumber"
QT_MOC_LITERAL(34, 549, 10), // "setFixText"
QT_MOC_LITERAL(35, 560, 4), // "var1"
QT_MOC_LITERAL(36, 565, 4), // "var2"
QT_MOC_LITERAL(37, 570, 17), // "faultFixOkClicked"
QT_MOC_LITERAL(38, 588, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(39, 609, 24), // "clearStructureNumberList"
QT_MOC_LITERAL(40, 634, 24), // "addToStructureNumberList"
QT_MOC_LITERAL(41, 659, 23), // "undoStructureNumberList"
QT_MOC_LITERAL(42, 683, 12), // "scrollToLine"
QT_MOC_LITERAL(43, 696, 10), // "lineNumber"
QT_MOC_LITERAL(44, 707, 25), // "scrollToCurrentReviewLine"
QT_MOC_LITERAL(45, 733, 17), // "scrollToFirstLine"
QT_MOC_LITERAL(46, 751, 11), // "startReview"
QT_MOC_LITERAL(47, 763, 23), // "moveToNextReviewSegment"
QT_MOC_LITERAL(48, 787, 21), // "findChallengeQuestion"
QT_MOC_LITERAL(49, 809, 19), // "documentWasModified"
QT_MOC_LITERAL(50, 829, 25), // "updateLineNumberAreaWidth"
QT_MOC_LITERAL(51, 855, 13), // "newBlockCount"
QT_MOC_LITERAL(52, 869, 20), // "updateLineNumberArea"
QT_MOC_LITERAL(53, 890, 21), // "showFaultPromptDialog"
QT_MOC_LITERAL(54, 912, 16), // "fixButtonHovered"
QT_MOC_LITERAL(55, 929, 16), // "fixButtonClicked"
QT_MOC_LITERAL(56, 946, 12), // "clearPreview"
QT_MOC_LITERAL(57, 959, 14), // "highlightMatch"
QT_MOC_LITERAL(58, 974, 19), // "askChatGPTTriggered"
QT_MOC_LITERAL(59, 994, 16), // "fixCodeTriggered"
QT_MOC_LITERAL(60, 1011, 15), // "addBugTriggered"
QT_MOC_LITERAL(61, 1027, 11), // "updateMatch"
QT_MOC_LITERAL(62, 1039, 27), // "updateInformalSpecPosInFile"
QT_MOC_LITERAL(63, 1067, 17), // "autoCompleteMatch"
QT_MOC_LITERAL(64, 1085, 21), // "moveFaultPromptDialog"
QT_MOC_LITERAL(65, 1107, 26), // "highlightStructureSegments"
QT_MOC_LITERAL(66, 1134, 10), // "QList<int>"
QT_MOC_LITERAL(67, 1145, 8), // "segments"
QT_MOC_LITERAL(68, 1154, 22), // "highlightReviewSegment"
QT_MOC_LITERAL(69, 1177, 33), // "QList<QTextEdit::ExtraSelecti..."
QT_MOC_LITERAL(70, 1211, 10) // "selections"

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
    "allSegmentsReviewComplete\0reportBugLine\0"
    "challengeQuestionFlag\0currentStr\0"
    "CodeElements\0flags\0resizeEvent\0"
    "QResizeEvent*\0event\0faultLinePaint\0"
    "blockNumber\0setFixText\0var1\0var2\0"
    "faultFixOkClicked\0highlightCurrentLine\0"
    "clearStructureNumberList\0"
    "addToStructureNumberList\0"
    "undoStructureNumberList\0scrollToLine\0"
    "lineNumber\0scrollToCurrentReviewLine\0"
    "scrollToFirstLine\0startReview\0"
    "moveToNextReviewSegment\0findChallengeQuestion\0"
    "documentWasModified\0updateLineNumberAreaWidth\0"
    "newBlockCount\0updateLineNumberArea\0"
    "showFaultPromptDialog\0fixButtonHovered\0"
    "fixButtonClicked\0clearPreview\0"
    "highlightMatch\0askChatGPTTriggered\0"
    "fixCodeTriggered\0addBugTriggered\0"
    "updateMatch\0updateInformalSpecPosInFile\0"
    "autoCompleteMatch\0moveFaultPromptDialog\0"
    "highlightStructureSegments\0QList<int>\0"
    "segments\0highlightReviewSegment\0"
    "QList<QTextEdit::ExtraSelection>&\0"
    "selections"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MdiChild[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  244,    2, 0x06 /* Public */,
       3,    0,  247,    2, 0x06 /* Public */,
       4,    0,  248,    2, 0x06 /* Public */,
       5,    1,  249,    2, 0x06 /* Public */,
       8,    2,  252,    2, 0x06 /* Public */,
      12,    2,  257,    2, 0x06 /* Public */,
      15,    2,  262,    2, 0x06 /* Public */,
      18,    1,  267,    2, 0x06 /* Public */,
      21,    1,  270,    2, 0x06 /* Public */,
      22,    1,  273,    2, 0x06 /* Public */,
      23,    0,  276,    2, 0x06 /* Public */,
      24,    1,  277,    2, 0x06 /* Public */,
      25,    2,  280,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      29,    1,  285,    2, 0x0a /* Public */,
      32,    1,  288,    2, 0x0a /* Public */,
      34,    2,  291,    2, 0x0a /* Public */,
      37,    0,  296,    2, 0x0a /* Public */,
      38,    0,  297,    2, 0x0a /* Public */,
      39,    0,  298,    2, 0x0a /* Public */,
      40,    0,  299,    2, 0x0a /* Public */,
      41,    0,  300,    2, 0x0a /* Public */,
      42,    1,  301,    2, 0x0a /* Public */,
      44,    0,  304,    2, 0x0a /* Public */,
      45,    0,  305,    2, 0x0a /* Public */,
      46,    0,  306,    2, 0x0a /* Public */,
      47,    0,  307,    2, 0x0a /* Public */,
      48,    0,  308,    2, 0x0a /* Public */,
      49,    0,  309,    2, 0x08 /* Private */,
      50,    1,  310,    2, 0x08 /* Private */,
      52,    1,  313,    2, 0x08 /* Private */,
      52,    1,  316,    2, 0x08 /* Private */,
      52,    0,  319,    2, 0x08 /* Private */,
      53,    1,  320,    2, 0x08 /* Private */,
      54,    0,  323,    2, 0x08 /* Private */,
      55,    0,  324,    2, 0x08 /* Private */,
      56,    0,  325,    2, 0x08 /* Private */,
      57,    0,  326,    2, 0x08 /* Private */,
      58,    0,  327,    2, 0x08 /* Private */,
      59,    0,  328,    2, 0x08 /* Private */,
      60,    0,  329,    2, 0x08 /* Private */,
      61,    0,  330,    2, 0x08 /* Private */,
      62,    0,  331,    2, 0x08 /* Private */,
      63,    0,  332,    2, 0x08 /* Private */,
      64,    0,  333,    2, 0x08 /* Private */,
      65,    1,  334,    2, 0x08 /* Private */,
      68,    2,  337,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 27,   26,   28,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::QRectF,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
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
    QMetaType::Void, 0x80000000 | 66,   67,
    QMetaType::Void, 0x80000000 | 66, 0x80000000 | 69,   67,   70,

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
        case 10: _t->allSegmentsReviewComplete(); break;
        case 11: _t->reportBugLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->challengeQuestionFlag((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< CodeElements(*)>(_a[2]))); break;
        case 13: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 14: _t->faultLinePaint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setFixText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->faultFixOkClicked(); break;
        case 17: _t->highlightCurrentLine(); break;
        case 18: _t->clearStructureNumberList(); break;
        case 19: _t->addToStructureNumberList(); break;
        case 20: _t->undoStructureNumberList(); break;
        case 21: _t->scrollToLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->scrollToCurrentReviewLine(); break;
        case 23: _t->scrollToFirstLine(); break;
        case 24: _t->startReview(); break;
        case 25: _t->moveToNextReviewSegment(); break;
        case 26: _t->findChallengeQuestion(); break;
        case 27: _t->documentWasModified(); break;
        case 28: _t->updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->updateLineNumberArea((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 30: _t->updateLineNumberArea((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->updateLineNumberArea(); break;
        case 32: _t->showFaultPromptDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->fixButtonHovered(); break;
        case 34: _t->fixButtonClicked(); break;
        case 35: _t->clearPreview(); break;
        case 36: _t->highlightMatch(); break;
        case 37: _t->askChatGPTTriggered(); break;
        case 38: _t->fixCodeTriggered(); break;
        case 39: _t->addBugTriggered(); break;
        case 40: _t->updateMatch(); break;
        case 41: _t->updateInformalSpecPosInFile(); break;
        case 42: _t->autoCompleteMatch(); break;
        case 43: _t->moveFaultPromptDialog(); break;
        case 44: _t->highlightStructureSegments((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 45: _t->highlightReviewSegment((*reinterpret_cast< const QList<int>(*)>(_a[1])),(*reinterpret_cast< QList<QTextEdit::ExtraSelection>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 44:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 45:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
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
        {
            typedef void (MdiChild::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::allSegmentsReviewComplete)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::reportBugLine)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (MdiChild::*_t)(QString , CodeElements );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MdiChild::challengeQuestionFlag)) {
                *result = 12;
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
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
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

// SIGNAL 10
void MdiChild::allSegmentsReviewComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MdiChild::reportBugLine(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MdiChild::challengeQuestionFlag(QString _t1, CodeElements _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
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
