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
    QByteArrayData data[81];
    char stringdata0[1337];
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
QT_MOC_LITERAL(31, 516, 7), // "newFile"
QT_MOC_LITERAL(32, 524, 4), // "open"
QT_MOC_LITERAL(33, 529, 4), // "save"
QT_MOC_LITERAL(34, 534, 6), // "saveAs"
QT_MOC_LITERAL(35, 541, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(36, 565, 14), // "openRecentFile"
QT_MOC_LITERAL(37, 580, 3), // "cut"
QT_MOC_LITERAL(38, 584, 4), // "copy"
QT_MOC_LITERAL(39, 589, 5), // "paste"
QT_MOC_LITERAL(40, 595, 5), // "about"
QT_MOC_LITERAL(41, 601, 14), // "aboutDeveloper"
QT_MOC_LITERAL(42, 616, 11), // "updateMenus"
QT_MOC_LITERAL(43, 628, 16), // "updateWindowMenu"
QT_MOC_LITERAL(44, 645, 14), // "createMdiChild"
QT_MOC_LITERAL(45, 660, 9), // "MdiChild*"
QT_MOC_LITERAL(46, 670, 21), // "switchLayoutDirection"
QT_MOC_LITERAL(47, 692, 18), // "configCodeAnalysis"
QT_MOC_LITERAL(48, 711, 17), // "managePropertySet"
QT_MOC_LITERAL(49, 729, 19), // "showAllRuleDescript"
QT_MOC_LITERAL(50, 749, 17), // "updateProgressBar"
QT_MOC_LITERAL(51, 767, 20), // "setCursorToFaultLine"
QT_MOC_LITERAL(52, 788, 12), // "showHMPPView"
QT_MOC_LITERAL(53, 801, 15), // "showProjectView"
QT_MOC_LITERAL(54, 817, 17), // "showFixedCodeView"
QT_MOC_LITERAL(55, 835, 12), // "showCSCRTool"
QT_MOC_LITERAL(56, 848, 15), // "showSCMFaultTab"
QT_MOC_LITERAL(57, 864, 14), // "lineEditPrompt"
QT_MOC_LITERAL(58, 879, 24), // "doubleClickedProjectTree"
QT_MOC_LITERAL(59, 904, 5), // "index"
QT_MOC_LITERAL(60, 910, 30), // "doubleClickedSpecificationView"
QT_MOC_LITERAL(61, 941, 26), // "doubleClickedToDoTableView"
QT_MOC_LITERAL(62, 968, 21), // "completeSpecification"
QT_MOC_LITERAL(63, 990, 19), // "updateToDoListModel"
QT_MOC_LITERAL(64, 1010, 18), // "clearToDoListModel"
QT_MOC_LITERAL(65, 1029, 16), // "completeToDoNote"
QT_MOC_LITERAL(66, 1046, 20), // "setTargetLangToCplus"
QT_MOC_LITERAL(67, 1067, 19), // "setTargetLangToJava"
QT_MOC_LITERAL(68, 1087, 21), // "setTargetLangToCsharp"
QT_MOC_LITERAL(69, 1109, 22), // "updateProjectClassInfo"
QT_MOC_LITERAL(70, 1132, 25), // "QHash<QString,ClassInfo>&"
QT_MOC_LITERAL(71, 1158, 16), // "newClassInfoHash"
QT_MOC_LITERAL(72, 1175, 22), // "insertProjectClassInfo"
QT_MOC_LITERAL(73, 1198, 16), // "QList<ClassInfo>"
QT_MOC_LITERAL(74, 1215, 16), // "insertClassInfos"
QT_MOC_LITERAL(75, 1232, 25), // "on_copyCodeButton_clicked"
QT_MOC_LITERAL(76, 1258, 30), // "on_copyFixedCodeButton_clicked"
QT_MOC_LITERAL(77, 1289, 8), // "testSlot"
QT_MOC_LITERAL(78, 1298, 22), // "projectViewMenuRequest"
QT_MOC_LITERAL(79, 1321, 3), // "pos"
QT_MOC_LITERAL(80, 1325, 11) // "showDemoSCM"

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
    "newFile\0open\0save\0saveAs\0"
    "updateRecentFileActions\0openRecentFile\0"
    "cut\0copy\0paste\0about\0aboutDeveloper\0"
    "updateMenus\0updateWindowMenu\0"
    "createMdiChild\0MdiChild*\0switchLayoutDirection\0"
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
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  289,    2, 0x0a /* Public */,
       5,    1,  292,    2, 0x0a /* Public */,
       8,    0,  295,    2, 0x0a /* Public */,
       9,    5,  296,    2, 0x0a /* Public */,
      15,    0,  307,    2, 0x0a /* Public */,
      16,    2,  308,    2, 0x0a /* Public */,
      20,    2,  313,    2, 0x0a /* Public */,
      23,    0,  318,    2, 0x0a /* Public */,
      24,    0,  319,    2, 0x0a /* Public */,
      25,    1,  320,    2, 0x0a /* Public */,
      27,    1,  323,    2, 0x0a /* Public */,
      28,    2,  326,    2, 0x0a /* Public */,
      31,    0,  331,    2, 0x08 /* Private */,
      32,    0,  332,    2, 0x08 /* Private */,
      33,    0,  333,    2, 0x08 /* Private */,
      34,    0,  334,    2, 0x08 /* Private */,
      35,    0,  335,    2, 0x08 /* Private */,
      36,    0,  336,    2, 0x08 /* Private */,
      37,    0,  337,    2, 0x08 /* Private */,
      38,    0,  338,    2, 0x08 /* Private */,
      39,    0,  339,    2, 0x08 /* Private */,
      40,    0,  340,    2, 0x08 /* Private */,
      41,    0,  341,    2, 0x08 /* Private */,
      42,    0,  342,    2, 0x08 /* Private */,
      43,    0,  343,    2, 0x08 /* Private */,
      44,    0,  344,    2, 0x08 /* Private */,
      46,    0,  345,    2, 0x08 /* Private */,
      47,    0,  346,    2, 0x08 /* Private */,
      48,    0,  347,    2, 0x08 /* Private */,
      49,    0,  348,    2, 0x08 /* Private */,
      50,    0,  349,    2, 0x08 /* Private */,
      51,    1,  350,    2, 0x08 /* Private */,
      52,    0,  353,    2, 0x08 /* Private */,
      53,    0,  354,    2, 0x08 /* Private */,
      54,    0,  355,    2, 0x08 /* Private */,
      55,    0,  356,    2, 0x08 /* Private */,
      56,    1,  357,    2, 0x08 /* Private */,
      57,    0,  360,    2, 0x08 /* Private */,
      58,    1,  361,    2, 0x08 /* Private */,
      60,    1,  364,    2, 0x08 /* Private */,
      61,    1,  367,    2, 0x08 /* Private */,
      62,    1,  370,    2, 0x08 /* Private */,
      63,    0,  373,    2, 0x08 /* Private */,
      64,    0,  374,    2, 0x08 /* Private */,
      65,    1,  375,    2, 0x08 /* Private */,
      66,    0,  378,    2, 0x08 /* Private */,
      67,    0,  379,    2, 0x08 /* Private */,
      68,    0,  380,    2, 0x08 /* Private */,
      69,    2,  381,    2, 0x08 /* Private */,
      72,    1,  386,    2, 0x08 /* Private */,
      75,    0,  389,    2, 0x08 /* Private */,
      76,    0,  390,    2, 0x08 /* Private */,
      77,    0,  391,    2, 0x08 /* Private */,
      78,    1,  392,    2, 0x08 /* Private */,
      80,    0,  395,    2, 0x08 /* Private */,

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
    0x80000000 | 45,
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
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 70,   17,   71,
    QMetaType::Void, 0x80000000 | 73,   74,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   79,
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
        case 12: _t->newFile(); break;
        case 13: _t->open(); break;
        case 14: _t->save(); break;
        case 15: _t->saveAs(); break;
        case 16: _t->updateRecentFileActions(); break;
        case 17: _t->openRecentFile(); break;
        case 18: _t->cut(); break;
        case 19: _t->copy(); break;
        case 20: _t->paste(); break;
        case 21: _t->about(); break;
        case 22: _t->aboutDeveloper(); break;
        case 23: _t->updateMenus(); break;
        case 24: _t->updateWindowMenu(); break;
        case 25: { MdiChild* _r = _t->createMdiChild();
            if (_a[0]) *reinterpret_cast< MdiChild**>(_a[0]) = _r; }  break;
        case 26: _t->switchLayoutDirection(); break;
        case 27: _t->configCodeAnalysis(); break;
        case 28: _t->managePropertySet(); break;
        case 29: _t->showAllRuleDescript(); break;
        case 30: _t->updateProgressBar(); break;
        case 31: _t->setCursorToFaultLine((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->showHMPPView(); break;
        case 33: _t->showProjectView(); break;
        case 34: _t->showFixedCodeView(); break;
        case 35: _t->showCSCRTool(); break;
        case 36: _t->showSCMFaultTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->lineEditPrompt(); break;
        case 38: _t->doubleClickedProjectTree((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 39: _t->doubleClickedSpecificationView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 40: _t->doubleClickedToDoTableView((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 41: _t->completeSpecification((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 42: _t->updateToDoListModel(); break;
        case 43: _t->clearToDoListModel(); break;
        case 44: _t->completeToDoNote((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 45: _t->setTargetLangToCplus(); break;
        case 46: _t->setTargetLangToJava(); break;
        case 47: _t->setTargetLangToCsharp(); break;
        case 48: _t->updateProjectClassInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,ClassInfo>(*)>(_a[2]))); break;
        case 49: _t->insertProjectClassInfo((*reinterpret_cast< const QList<ClassInfo>(*)>(_a[1]))); break;
        case 50: _t->on_copyCodeButton_clicked(); break;
        case 51: _t->on_copyFixedCodeButton_clicked(); break;
        case 52: _t->testSlot(); break;
        case 53: _t->projectViewMenuRequest((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 54: _t->showDemoSCM(); break;
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
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 55;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
