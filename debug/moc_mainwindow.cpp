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
    QByteArrayData data[90];
    char stringdata0[1485];
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
QT_MOC_LITERAL(27, 458, 16), // "fixCodeByChatGPT"
QT_MOC_LITERAL(28, 475, 19), // "findClassMemberType"
QT_MOC_LITERAL(29, 495, 9), // "className"
QT_MOC_LITERAL(30, 505, 10), // "expression"
QT_MOC_LITERAL(31, 516, 17), // "loadBugReportFile"
QT_MOC_LITERAL(32, 534, 17), // "bugReportFilePath"
QT_MOC_LITERAL(33, 552, 16), // "reviewMethodCode"
QT_MOC_LITERAL(34, 569, 10), // "methodName"
QT_MOC_LITERAL(35, 580, 27), // "setCscrToolMethodNameToCode"
QT_MOC_LITERAL(36, 608, 22), // "QHash<QString,QString>"
QT_MOC_LITERAL(37, 631, 5), // "value"
QT_MOC_LITERAL(38, 637, 7), // "newFile"
QT_MOC_LITERAL(39, 645, 17), // "newReviewCodeFile"
QT_MOC_LITERAL(40, 663, 9), // "MdiChild*"
QT_MOC_LITERAL(41, 673, 8), // "fileName"
QT_MOC_LITERAL(42, 682, 4), // "open"
QT_MOC_LITERAL(43, 687, 4), // "save"
QT_MOC_LITERAL(44, 692, 6), // "saveAs"
QT_MOC_LITERAL(45, 699, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(46, 723, 14), // "openRecentFile"
QT_MOC_LITERAL(47, 738, 3), // "cut"
QT_MOC_LITERAL(48, 742, 4), // "copy"
QT_MOC_LITERAL(49, 747, 5), // "paste"
QT_MOC_LITERAL(50, 753, 5), // "about"
QT_MOC_LITERAL(51, 759, 14), // "aboutDeveloper"
QT_MOC_LITERAL(52, 774, 11), // "updateMenus"
QT_MOC_LITERAL(53, 786, 16), // "updateWindowMenu"
QT_MOC_LITERAL(54, 803, 14), // "createMdiChild"
QT_MOC_LITERAL(55, 818, 21), // "switchLayoutDirection"
QT_MOC_LITERAL(56, 840, 18), // "configCodeAnalysis"
QT_MOC_LITERAL(57, 859, 17), // "managePropertySet"
QT_MOC_LITERAL(58, 877, 19), // "showAllRuleDescript"
QT_MOC_LITERAL(59, 897, 17), // "updateProgressBar"
QT_MOC_LITERAL(60, 915, 20), // "setCursorToFaultLine"
QT_MOC_LITERAL(61, 936, 12), // "showHMPPView"
QT_MOC_LITERAL(62, 949, 15), // "showProjectView"
QT_MOC_LITERAL(63, 965, 17), // "showFixedCodeView"
QT_MOC_LITERAL(64, 983, 12), // "showCSCRTool"
QT_MOC_LITERAL(65, 996, 15), // "showSCMFaultTab"
QT_MOC_LITERAL(66, 1012, 14), // "lineEditPrompt"
QT_MOC_LITERAL(67, 1027, 24), // "doubleClickedProjectTree"
QT_MOC_LITERAL(68, 1052, 5), // "index"
QT_MOC_LITERAL(69, 1058, 30), // "doubleClickedSpecificationView"
QT_MOC_LITERAL(70, 1089, 26), // "doubleClickedToDoTableView"
QT_MOC_LITERAL(71, 1116, 21), // "completeSpecification"
QT_MOC_LITERAL(72, 1138, 19), // "updateToDoListModel"
QT_MOC_LITERAL(73, 1158, 18), // "clearToDoListModel"
QT_MOC_LITERAL(74, 1177, 16), // "completeToDoNote"
QT_MOC_LITERAL(75, 1194, 20), // "setTargetLangToCplus"
QT_MOC_LITERAL(76, 1215, 19), // "setTargetLangToJava"
QT_MOC_LITERAL(77, 1235, 21), // "setTargetLangToCsharp"
QT_MOC_LITERAL(78, 1257, 22), // "updateProjectClassInfo"
QT_MOC_LITERAL(79, 1280, 25), // "QHash<QString,ClassInfo>&"
QT_MOC_LITERAL(80, 1306, 16), // "newClassInfoHash"
QT_MOC_LITERAL(81, 1323, 22), // "insertProjectClassInfo"
QT_MOC_LITERAL(82, 1346, 16), // "QList<ClassInfo>"
QT_MOC_LITERAL(83, 1363, 16), // "insertClassInfos"
QT_MOC_LITERAL(84, 1380, 25), // "on_copyCodeButton_clicked"
QT_MOC_LITERAL(85, 1406, 30), // "on_copyFixedCodeButton_clicked"
QT_MOC_LITERAL(86, 1437, 8), // "testSlot"
QT_MOC_LITERAL(87, 1446, 22), // "projectViewMenuRequest"
QT_MOC_LITERAL(88, 1469, 3), // "pos"
QT_MOC_LITERAL(89, 1473, 11) // "showDemoSCM"

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
    "startChatGPTDialog\0text\0fixCodeByChatGPT\0"
    "findClassMemberType\0className\0expression\0"
    "loadBugReportFile\0bugReportFilePath\0"
    "reviewMethodCode\0methodName\0"
    "setCscrToolMethodNameToCode\0"
    "QHash<QString,QString>\0value\0newFile\0"
    "newReviewCodeFile\0MdiChild*\0fileName\0"
    "open\0save\0saveAs\0updateRecentFileActions\0"
    "openRecentFile\0cut\0copy\0paste\0about\0"
    "aboutDeveloper\0updateMenus\0updateWindowMenu\0"
    "createMdiChild\0switchLayoutDirection\0"
    "configCodeAnalysis\0managePropertySet\0"
    "showAllRuleDescript\0updateProgressBar\0"
    "setCursorToFaultLine\0showHMPPView\0"
    "showProjectView\0showFixedCodeView\0"
    "showCSCRTool\0showSCMFaultTab\0"
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
    "on_copyFixedCodeButton_clicked\0testSlot\0"
    "projectViewMenuRequest\0pos\0showDemoSCM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  314,    2, 0x0a /* Public */,
       5,    1,  317,    2, 0x0a /* Public */,
       8,    0,  320,    2, 0x0a /* Public */,
       9,    5,  321,    2, 0x0a /* Public */,
      15,    0,  332,    2, 0x0a /* Public */,
      16,    2,  333,    2, 0x0a /* Public */,
      20,    2,  338,    2, 0x0a /* Public */,
      23,    0,  343,    2, 0x0a /* Public */,
      24,    0,  344,    2, 0x0a /* Public */,
      25,    1,  345,    2, 0x0a /* Public */,
      27,    1,  348,    2, 0x0a /* Public */,
      28,    2,  351,    2, 0x0a /* Public */,
      31,    1,  356,    2, 0x0a /* Public */,
      33,    1,  359,    2, 0x0a /* Public */,
      35,    1,  362,    2, 0x0a /* Public */,
      38,    0,  365,    2, 0x08 /* Private */,
      39,    1,  366,    2, 0x08 /* Private */,
      39,    0,  369,    2, 0x28 /* Private | MethodCloned */,
      42,    0,  370,    2, 0x08 /* Private */,
      43,    0,  371,    2, 0x08 /* Private */,
      44,    0,  372,    2, 0x08 /* Private */,
      45,    0,  373,    2, 0x08 /* Private */,
      46,    0,  374,    2, 0x08 /* Private */,
      47,    0,  375,    2, 0x08 /* Private */,
      48,    0,  376,    2, 0x08 /* Private */,
      49,    0,  377,    2, 0x08 /* Private */,
      50,    0,  378,    2, 0x08 /* Private */,
      51,    0,  379,    2, 0x08 /* Private */,
      52,    0,  380,    2, 0x08 /* Private */,
      53,    0,  381,    2, 0x08 /* Private */,
      54,    0,  382,    2, 0x08 /* Private */,
      55,    0,  383,    2, 0x08 /* Private */,
      56,    0,  384,    2, 0x08 /* Private */,
      57,    0,  385,    2, 0x08 /* Private */,
      58,    0,  386,    2, 0x08 /* Private */,
      59,    0,  387,    2, 0x08 /* Private */,
      60,    1,  388,    2, 0x08 /* Private */,
      61,    0,  391,    2, 0x08 /* Private */,
      62,    0,  392,    2, 0x08 /* Private */,
      63,    0,  393,    2, 0x08 /* Private */,
      64,    0,  394,    2, 0x08 /* Private */,
      65,    1,  395,    2, 0x08 /* Private */,
      66,    0,  398,    2, 0x08 /* Private */,
      67,    1,  399,    2, 0x08 /* Private */,
      69,    1,  402,    2, 0x08 /* Private */,
      70,    1,  405,    2, 0x08 /* Private */,
      71,    1,  408,    2, 0x08 /* Private */,
      72,    0,  411,    2, 0x08 /* Private */,
      73,    0,  412,    2, 0x08 /* Private */,
      74,    1,  413,    2, 0x08 /* Private */,
      75,    0,  416,    2, 0x08 /* Private */,
      76,    0,  417,    2, 0x08 /* Private */,
      77,    0,  418,    2, 0x08 /* Private */,
      78,    2,  419,    2, 0x08 /* Private */,
      81,    1,  424,    2, 0x08 /* Private */,
      84,    0,  427,    2, 0x08 /* Private */,
      85,    0,  428,    2, 0x08 /* Private */,
      86,    0,  429,    2, 0x08 /* Private */,
      87,    1,  430,    2, 0x08 /* Private */,
      89,    0,  433,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void,
    0x80000000 | 40, QMetaType::QString,   41,
    0x80000000 | 40,
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
    0x80000000 | 40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 79,   17,   80,
    QMetaType::Void, 0x80000000 | 82,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   88,
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
        case 10: _t->fixCodeByChatGPT((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: { QString _r = _t->findClassMemberType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: _t->loadBugReportFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->reviewMethodCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->setCscrToolMethodNameToCode((*reinterpret_cast< const QHash<QString,QString>(*)>(_a[1]))); break;
        case 15: _t->newFile(); break;
        case 16: { MdiChild* _r = _t->newReviewCodeFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< MdiChild**>(_a[0]) = _r; }  break;
        case 17: { MdiChild* _r = _t->newReviewCodeFile();
            if (_a[0]) *reinterpret_cast< MdiChild**>(_a[0]) = _r; }  break;
        case 18: _t->open(); break;
        case 19: _t->save(); break;
        case 20: _t->saveAs(); break;
        case 21: _t->updateRecentFileActions(); break;
        case 22: _t->openRecentFile(); break;
        case 23: _t->cut(); break;
        case 24: _t->copy(); break;
        case 25: _t->paste(); break;
        case 26: _t->about(); break;
        case 27: _t->aboutDeveloper(); break;
        case 28: _t->updateMenus(); break;
        case 29: _t->updateWindowMenu(); break;
        case 30: { MdiChild* _r = _t->createMdiChild();
            if (_a[0]) *reinterpret_cast< MdiChild**>(_a[0]) = _r; }  break;
        case 31: _t->switchLayoutDirection(); break;
        case 32: _t->configCodeAnalysis(); break;
        case 33: _t->managePropertySet(); break;
        case 34: _t->showAllRuleDescript(); break;
        case 35: _t->updateProgressBar(); break;
        case 36: _t->setCursorToFaultLine((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 37: _t->showHMPPView(); break;
        case 38: _t->showProjectView(); break;
        case 39: _t->showFixedCodeView(); break;
        case 40: _t->showCSCRTool(); break;
        case 41: _t->showSCMFaultTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->lineEditPrompt(); break;
        case 43: _t->doubleClickedProjectTree((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 44: _t->doubleClickedSpecificationView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 45: _t->doubleClickedToDoTableView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 46: _t->completeSpecification((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 47: _t->updateToDoListModel(); break;
        case 48: _t->clearToDoListModel(); break;
        case 49: _t->completeToDoNote((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 50: _t->setTargetLangToCplus(); break;
        case 51: _t->setTargetLangToJava(); break;
        case 52: _t->setTargetLangToCsharp(); break;
        case 53: _t->updateProjectClassInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,ClassInfo>(*)>(_a[2]))); break;
        case 54: _t->insertProjectClassInfo((*reinterpret_cast< const QList<ClassInfo>(*)>(_a[1]))); break;
        case 55: _t->on_copyCodeButton_clicked(); break;
        case 56: _t->on_copyFixedCodeButton_clicked(); break;
        case 57: _t->testSlot(); break;
        case 58: _t->projectViewMenuRequest((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 59: _t->showDemoSCM(); break;
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
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
