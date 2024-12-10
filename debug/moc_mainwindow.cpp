/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[74];
    char stringdata0[1217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "setCursorToIssueLine"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(4, 51, 4), // "item"
QT_MOC_LITERAL(5, 56, 29), // "showClassUndefinedSyntaxIssue"
QT_MOC_LITERAL(6, 86, 32), // "QList<ClassUndefinedSyntaxIssue>"
QT_MOC_LITERAL(7, 119, 4), // "list"
QT_MOC_LITERAL(8, 124, 29), // "showClassUnspecifiedTypeIssue"
QT_MOC_LITERAL(9, 154, 26), // "receiveGuideWizardFileInfo"
QT_MOC_LITERAL(10, 181, 13), // "createNewFlag"
QT_MOC_LITERAL(11, 195, 7), // "proName"
QT_MOC_LITERAL(12, 203, 6), // "proDir"
QT_MOC_LITERAL(13, 210, 7), // "specDir"
QT_MOC_LITERAL(14, 218, 10), // "targetLang"
QT_MOC_LITERAL(15, 229, 17), // "getNewProjectInfo"
QT_MOC_LITERAL(16, 247, 26), // "updateFileToDoRequireNotes"
QT_MOC_LITERAL(17, 274, 8), // "filePath"
QT_MOC_LITERAL(18, 283, 21), // "QVector<RequireNote*>"
QT_MOC_LITERAL(19, 305, 5), // "notes"
QT_MOC_LITERAL(20, 311, 19), // "updateInformalSpecs"
QT_MOC_LITERAL(21, 331, 23), // "QList<InformalSpecInfo>"
QT_MOC_LITERAL(22, 355, 17), // "informalSpecInfos"
QT_MOC_LITERAL(23, 373, 32), // "importSpecificationForCurrentPro"
QT_MOC_LITERAL(24, 406, 27), // "buildFilesFromSpecification"
QT_MOC_LITERAL(25, 434, 18), // "startChatGPTDialog"
QT_MOC_LITERAL(26, 453, 4), // "text"
QT_MOC_LITERAL(27, 458, 7), // "newFile"
QT_MOC_LITERAL(28, 466, 4), // "open"
QT_MOC_LITERAL(29, 471, 4), // "save"
QT_MOC_LITERAL(30, 476, 6), // "saveAs"
QT_MOC_LITERAL(31, 483, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(32, 507, 14), // "openRecentFile"
QT_MOC_LITERAL(33, 522, 3), // "cut"
QT_MOC_LITERAL(34, 526, 4), // "copy"
QT_MOC_LITERAL(35, 531, 5), // "paste"
QT_MOC_LITERAL(36, 537, 5), // "about"
QT_MOC_LITERAL(37, 543, 14), // "aboutDeveloper"
QT_MOC_LITERAL(38, 558, 11), // "updateMenus"
QT_MOC_LITERAL(39, 570, 16), // "updateWindowMenu"
QT_MOC_LITERAL(40, 587, 14), // "createMdiChild"
QT_MOC_LITERAL(41, 602, 9), // "MdiChild*"
QT_MOC_LITERAL(42, 612, 21), // "switchLayoutDirection"
QT_MOC_LITERAL(43, 634, 18), // "configCodeAnalysis"
QT_MOC_LITERAL(44, 653, 17), // "managePropertySet"
QT_MOC_LITERAL(45, 671, 19), // "showAllRuleDescript"
QT_MOC_LITERAL(46, 691, 17), // "updateProgressBar"
QT_MOC_LITERAL(47, 709, 20), // "setCursorToFaultLine"
QT_MOC_LITERAL(48, 730, 12), // "showHMPPView"
QT_MOC_LITERAL(49, 743, 15), // "showProjectView"
QT_MOC_LITERAL(50, 759, 15), // "showSCMFaultTab"
QT_MOC_LITERAL(51, 775, 14), // "lineEditPrompt"
QT_MOC_LITERAL(52, 790, 24), // "doubleClickedProjectTree"
QT_MOC_LITERAL(53, 815, 5), // "index"
QT_MOC_LITERAL(54, 821, 30), // "doubleClickedSpecificationView"
QT_MOC_LITERAL(55, 852, 26), // "doubleClickedToDoTableView"
QT_MOC_LITERAL(56, 879, 21), // "completeSpecification"
QT_MOC_LITERAL(57, 901, 19), // "updateToDoListModel"
QT_MOC_LITERAL(58, 921, 18), // "clearToDoListModel"
QT_MOC_LITERAL(59, 940, 16), // "completeToDoNote"
QT_MOC_LITERAL(60, 957, 20), // "setTargetLangToCplus"
QT_MOC_LITERAL(61, 978, 19), // "setTargetLangToJava"
QT_MOC_LITERAL(62, 998, 21), // "setTargetLangToCsharp"
QT_MOC_LITERAL(63, 1020, 22), // "updateProjectClassInfo"
QT_MOC_LITERAL(64, 1043, 25), // "QHash<QString,ClassInfo>&"
QT_MOC_LITERAL(65, 1069, 16), // "newClassInfoHash"
QT_MOC_LITERAL(66, 1086, 22), // "insertProjectClassInfo"
QT_MOC_LITERAL(67, 1109, 16), // "QList<ClassInfo>"
QT_MOC_LITERAL(68, 1126, 16), // "insertClassInfos"
QT_MOC_LITERAL(69, 1143, 25), // "on_copyCodeButton_clicked"
QT_MOC_LITERAL(70, 1169, 8), // "testSlot"
QT_MOC_LITERAL(71, 1178, 22), // "projectViewMenuRequest"
QT_MOC_LITERAL(72, 1201, 3), // "pos"
QT_MOC_LITERAL(73, 1205, 11) // "showDemoSCM"

    },
    "MainWindow\0setCursorToIssueLine\0\0"
    "QTableWidgetItem*\0item\0"
    "showClassUndefinedSyntaxIssue\0"
    "QList<ClassUndefinedSyntaxIssue>\0list\0"
    "showClassUnspecifiedTypeIssue\0"
    "receiveGuideWizardFileInfo\0createNewFlag\0"
    "proName\0proDir\0specDir\0targetLang\0"
    "getNewProjectInfo\0updateFileToDoRequireNotes\0"
    "filePath\0QVector<RequireNote*>\0notes\0"
    "updateInformalSpecs\0QList<InformalSpecInfo>\0"
    "informalSpecInfos\0importSpecificationForCurrentPro\0"
    "buildFilesFromSpecification\0"
    "startChatGPTDialog\0text\0newFile\0open\0"
    "save\0saveAs\0updateRecentFileActions\0"
    "openRecentFile\0cut\0copy\0paste\0about\0"
    "aboutDeveloper\0updateMenus\0updateWindowMenu\0"
    "createMdiChild\0MdiChild*\0switchLayoutDirection\0"
    "configCodeAnalysis\0managePropertySet\0"
    "showAllRuleDescript\0updateProgressBar\0"
    "setCursorToFaultLine\0showHMPPView\0"
    "showProjectView\0showSCMFaultTab\0"
    "lineEditPrompt\0doubleClickedProjectTree\0"
    "index\0doubleClickedSpecificationView\0"
    "doubleClickedToDoTableView\0"
    "completeSpecification\0updateToDoListModel\0"
    "clearToDoListModel\0completeToDoNote\0"
    "setTargetLangToCplus\0setTargetLangToJava\0"
    "setTargetLangToCsharp\0updateProjectClassInfo\0"
    "QHash<QString,ClassInfo>&\0newClassInfoHash\0"
    "insertProjectClassInfo\0QList<ClassInfo>\0"
    "insertClassInfos\0on_copyCodeButton_clicked\0"
    "testSlot\0projectViewMenuRequest\0pos\0"
    "showDemoSCM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  264,    2, 0x0a /* Public */,
       5,    1,  267,    2, 0x0a /* Public */,
       8,    0,  270,    2, 0x0a /* Public */,
       9,    5,  271,    2, 0x0a /* Public */,
      15,    0,  282,    2, 0x0a /* Public */,
      16,    2,  283,    2, 0x0a /* Public */,
      20,    2,  288,    2, 0x0a /* Public */,
      23,    0,  293,    2, 0x0a /* Public */,
      24,    0,  294,    2, 0x0a /* Public */,
      25,    1,  295,    2, 0x0a /* Public */,
      27,    0,  298,    2, 0x08 /* Private */,
      28,    0,  299,    2, 0x08 /* Private */,
      29,    0,  300,    2, 0x08 /* Private */,
      30,    0,  301,    2, 0x08 /* Private */,
      31,    0,  302,    2, 0x08 /* Private */,
      32,    0,  303,    2, 0x08 /* Private */,
      33,    0,  304,    2, 0x08 /* Private */,
      34,    0,  305,    2, 0x08 /* Private */,
      35,    0,  306,    2, 0x08 /* Private */,
      36,    0,  307,    2, 0x08 /* Private */,
      37,    0,  308,    2, 0x08 /* Private */,
      38,    0,  309,    2, 0x08 /* Private */,
      39,    0,  310,    2, 0x08 /* Private */,
      40,    0,  311,    2, 0x08 /* Private */,
      42,    0,  312,    2, 0x08 /* Private */,
      43,    0,  313,    2, 0x08 /* Private */,
      44,    0,  314,    2, 0x08 /* Private */,
      45,    0,  315,    2, 0x08 /* Private */,
      46,    0,  316,    2, 0x08 /* Private */,
      47,    1,  317,    2, 0x08 /* Private */,
      48,    0,  320,    2, 0x08 /* Private */,
      49,    0,  321,    2, 0x08 /* Private */,
      50,    1,  322,    2, 0x08 /* Private */,
      51,    0,  325,    2, 0x08 /* Private */,
      52,    1,  326,    2, 0x08 /* Private */,
      54,    1,  329,    2, 0x08 /* Private */,
      55,    1,  332,    2, 0x08 /* Private */,
      56,    1,  335,    2, 0x08 /* Private */,
      57,    0,  338,    2, 0x08 /* Private */,
      58,    0,  339,    2, 0x08 /* Private */,
      59,    1,  340,    2, 0x08 /* Private */,
      60,    0,  343,    2, 0x08 /* Private */,
      61,    0,  344,    2, 0x08 /* Private */,
      62,    0,  345,    2, 0x08 /* Private */,
      63,    2,  346,    2, 0x08 /* Private */,
      66,    1,  351,    2, 0x08 /* Private */,
      69,    0,  354,    2, 0x08 /* Private */,
      70,    0,  355,    2, 0x08 /* Private */,
      71,    1,  356,    2, 0x08 /* Private */,
      73,    0,  359,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,   17,   19,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 21,   17,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   26,
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
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   53,
    QMetaType::Void, QMetaType::QModelIndex,   53,
    QMetaType::Void, QMetaType::QModelIndex,   53,
    QMetaType::Void, QMetaType::QModelIndex,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 64,   17,   65,
    QMetaType::Void, 0x80000000 | 67,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   72,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCursorToIssueLine((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->showClassUndefinedSyntaxIssue((*reinterpret_cast< const QList<ClassUndefinedSyntaxIssue>(*)>(_a[1]))); break;
        case 2: _t->showClassUnspecifiedTypeIssue(); break;
        case 3: _t->receiveGuideWizardFileInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 4: _t->getNewProjectInfo(); break;
        case 5: _t->updateFileToDoRequireNotes((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<RequireNote*>(*)>(_a[2]))); break;
        case 6: _t->updateInformalSpecs((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<InformalSpecInfo>(*)>(_a[2]))); break;
        case 7: _t->importSpecificationForCurrentPro(); break;
        case 8: _t->buildFilesFromSpecification(); break;
        case 9: _t->startChatGPTDialog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->newFile(); break;
        case 11: _t->open(); break;
        case 12: _t->save(); break;
        case 13: _t->saveAs(); break;
        case 14: _t->updateRecentFileActions(); break;
        case 15: _t->openRecentFile(); break;
        case 16: _t->cut(); break;
        case 17: _t->copy(); break;
        case 18: _t->paste(); break;
        case 19: _t->about(); break;
        case 20: _t->aboutDeveloper(); break;
        case 21: _t->updateMenus(); break;
        case 22: _t->updateWindowMenu(); break;
        case 23: { MdiChild* _r = _t->createMdiChild();
            if (_a[0]) *reinterpret_cast< MdiChild**>(_a[0]) = _r; }  break;
        case 24: _t->switchLayoutDirection(); break;
        case 25: _t->configCodeAnalysis(); break;
        case 26: _t->managePropertySet(); break;
        case 27: _t->showAllRuleDescript(); break;
        case 28: _t->updateProgressBar(); break;
        case 29: _t->setCursorToFaultLine((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 30: _t->showHMPPView(); break;
        case 31: _t->showProjectView(); break;
        case 32: _t->showSCMFaultTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->lineEditPrompt(); break;
        case 34: _t->doubleClickedProjectTree((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 35: _t->doubleClickedSpecificationView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 36: _t->doubleClickedToDoTableView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 37: _t->completeSpecification((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 38: _t->updateToDoListModel(); break;
        case 39: _t->clearToDoListModel(); break;
        case 40: _t->completeToDoNote((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 41: _t->setTargetLangToCplus(); break;
        case 42: _t->setTargetLangToJava(); break;
        case 43: _t->setTargetLangToCsharp(); break;
        case 44: _t->updateProjectClassInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,ClassInfo>(*)>(_a[2]))); break;
        case 45: _t->insertProjectClassInfo((*reinterpret_cast< const QList<ClassInfo>(*)>(_a[1]))); break;
        case 46: _t->on_copyCodeButton_clicked(); break;
        case 47: _t->testSlot(); break;
        case 48: _t->projectViewMenuRequest((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 49: _t->showDemoSCM(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 50;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
