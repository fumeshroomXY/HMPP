#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include <QObject>
#include <faultpromptdialog.h>
#include <highlighter.h>
#include <issue.h>
#include "syntaxrule.h"

#include <QVector>
#include <QEvent>
#include <QTextBlock>
#include <QScrollBar>
#include <QDebug>
#include <memory>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;
class FoldingWidget;
class CustomButton;
class MainWindow;

//定义作用域
enum SCOPE
{
    NONE, GLOBAL, LOCAL, CLASS
};

struct Variable;
struct Method;
struct ClassInfo;
struct InformalSpecInfo;



//记录文档中的伪码需求注释节点
struct RequireNote{
    QString note = "";
    int startLine = -1;
    int endLine = -1;
    QString filePath;
    bool isRoot = false;   //是否是根节点，即顶级需求

    QVector<RequireNote *> children;

    RequireNote(QString note, int start, int end, QString file) : note(note),
        startLine(start), endLine(end), filePath(file){}
};

//记录文档中的伪码需求注释节点
struct Parenthesis{
    QString type;
    int startLine;
    int startPos;
    int endLine;
    int endPos;
    bool isRoot = false;   //是否是根节点，即顶级括号

    //QVector<Parenthesis *> children;
    Parenthesis(){}
    Parenthesis(QString type, int start, int startPos, int end, int endPos) : type(type),
        startLine(start), startPos(startPos), endLine(end), endPos(endPos){}
};

class MdiChild : public QTextEdit
{
    Q_OBJECT

public:
    explicit MdiChild(QWidget *parent = 0);

    void newFile(QString fileName = "");
    bool loadFile(const QString &fileName);   //加载文件
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile();    //提取文件名
    QString currentFile() { return curFile; }   //返回当前文件路径

    QVector<RequireNote*> getRequireNotes() {return requireNotes ;}


    //和绘制行号有关的代码
    int getFirstVisibleBlockId();
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    int getFaultLineNumber();

    int faultLineNumber = -1;

    int getLineHeight();

    //折叠代码
    void foldingWidgetPaintEvent(QPaintEvent *event);
    void foldingWidgetMousePressEvent(QMouseEvent *event);
    int foldingWidgetWidth();

    //折叠标记高亮
    void foldingWidgetHighlight(QPoint pos);
    void foldingWidgetHighlightEvent(QPaintEvent *event);

    //将需求伪码改为注释
    void changeRequirementToNote(int lineNumber);

    //跳转到当前文档的指定行
    void goToLine(int lineNumber);

    //更新函数和变量信息
    void updateObjectInfoInSourceFile();

    //更新顶层括号信息
    void updateTopParenthesis();

    //匹配对应形式的fault
    void matchFaultPattern(const QRegExp &faultPattern, const QTextCharFormat &format, QString faultName);
    QList<ClassMemberUnspecifiedIssue> getUnspecifiedTypeIssueList();

    //更新头文件的issue信息
    void updateIssueInfoInSourceFile();

    //更新头文件的类信息
    void updateObjectInfoInHeaderFile();

    MainWindow *getMainWindowPtr() const;
    void setMainWindowPtr(MainWindow *value);

    //更新需求注释的具体内容
    void updateRequireNoteContent();

    //将todo需求伪码改为注释
    void completeToDoNote(int lineNumber);

    //根据当前行号找到对应的函数代码
    QString findMethodCodeByName(int currentBlockNumber);

    bool getCscrToolMode() const;
    void setCscrToolMode(bool value);

    int getCurrentReviewLine() const;
    void setCurrentReviewLine(int value);

    void resetBlockColors(int startLine, int endLine, const QColor &color, QList<QTextEdit::ExtraSelection>& selections);

    bool isAllSegmentsReviewed();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;   //关闭事件

    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;   //用于检测快捷按键

    void contextMenuEvent(QContextMenuEvent* event) Q_DECL_OVERRIDE;


    //void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

public slots:
    void resizeEvent(QResizeEvent *event);
    void faultLinePaint(int blockNumber);
    void setFixText(QString var1, QString var2);

    //fault弹窗，quickfix并确定后触发
    void faultFixOkClicked();

    void highlightCurrentLine();

    //更改StructureNumberList
    void clearStructureNumberList();
    void addToStructureNumberList();
    void undoStructureNumberList();

    void scrollToLine(int lineNumber);
    void scrollToCurrentReviewLine();
    void scrollToFirstLine();

    void moveToNextReviewSegment();


private slots:
    void documentWasModified();    //文件被更改时显示更改窗口状态

    void updateLineNumberAreaWidth(int newBlockCount);

    //void updateLineNumberArea(const QRect &, int);
    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea();

    void showFaultPromptDialog(int lineNumber);

    void fixButtonHovered();
    void fixButtonClicked();
    void clearPreview();

    void highlightMatch();

    void askChatGPTTriggered();

    void fixCodeTriggered();

    void addBugTriggered();


    //更新需求括号的匹配
    void updateMatch();

    //更新文件中的自然语言规格的位置
    void updateInformalSpecPosInFile();

    //当检测到>>>，自动插入<<<
    void autoCompleteMatch();

    //更新faultBox的位置
    void moveFaultPromptDialog();

    //绘制Structure后的代码块
    void highlightSegments(const QList<int> &segments);

private:
    //更新需求节点
    void updateRequireNotes(int start, int end, RequireNote* node);

    bool maybeSave();   //是否需要保存
    void setCurrentFile(const QString &fileName);   //设置当前文件
    QString strippedName(const QString &fullFileName);

    QString curFile;     //保存当前文件路径
    bool isUntitled;    //作为当前文件是否被保存到硬盘上的标志

    MainWindow* mainWindowPtr;

    //绘制行号的区域
    LineNumberArea *lineNumberArea;

    QWidget *foldingWidget;

    Highlighter* highlighter;

    FaultPromptDialog* faultPrompt;

    //保存当前文件的类名，比如Student.cpp，保存Student
    QString fileClassName;

    //保存Structure的段号
    QList<int> structureNumberList;
    int recentlyInsertedNumber;

    int currentReviewLine = 0;



    //用于保存语法错误，这里主要是类未定义的，还有UNSPECIFIED的语法错误
    QList<ClassUndefinedSyntaxIssue> syntaxIssueList;

    QList<ClassMemberUnspecifiedIssue> unspecifiedTypeIssueList;

    QString previewText;
    bool insertPreview = false;
    bool faultflag = true;
    bool fixedfalg = false;

    bool cscrToolMode = false;

    bool matchLeftMark(QTextBlock currentBlock, int index,
                              int numRightParentheses, int &matchLineNumber, int &matchPosition,
                              QString startStr, QString endStr);
    bool matchRightMark(QTextBlock currentBlock, int index,
                               int numLeftParentheses, int &matchLineNumber, int &matchPosition,
                               QString startStr, QString endStr);
    void createParenthesisSelection(int pos);

    inline int findParenthesisStartPos(Parenthesis* p){
        return document()->findBlockByLineNumber(p->startLine).position() + p->startPos;
    }

    inline int findParenthesisEndPos(Parenthesis* p){
        return document()->findBlockByLineNumber(p->endLine).position() + p->endPos;
    }

    //需求伪码注释节点列表
    QVector<RequireNote *> requireNotes;

    QList<Parenthesis*> parenthesis;
    QList<Parenthesis*> topParenthesis;   //顶层括号信息


    QHash<QString, QString> classes;   //key = 实例的类名，value = 类名
    QMultiHash<Variable, int> tmpVars;   //局部变量表，key = 实例的变量， value = 文档中绝对位置
    QList<Variable>* globalVars;   //全局变量表
    QList<Method>* definedMethods;    //已经有函数体的函数表，比如类内函数或全局函数
    QList<Method>* Methods;   //调用的函数表

    //当前文件的类信息汇总
    QHash<QString, ClassInfo>* classInfoHash;   //key = 类名，value = 类信息

    QTextCharFormat previewFormat = [](){
        QTextCharFormat format;
        format.setForeground(Qt::gray);  // 灰色预览效果
        return format;
    }();

    QTextCharFormat insertFormat = [](){
        QTextCharFormat format;
        // 在此设置插入文本的格式，例如设置为黑色
        format.setForeground(Qt::black);
        return format;
    }();


    //将函数调用时的实参转化为加上类型的形参字符串
    QString completeMethodParamType(const QString &str, const int &pos);

    //判断两个位置是否在同一作用域内
    bool isInSameScope(const int &defPos, const int &accessPos);

    //找到某一变量名对应的类型
    QString findVarType(const QString &varName, const QString &className, const int &pos);

    //找到某一函数名对应的返回类型
    QString findMethodReturnType(const QString &methodName, const QString &className, const QStringList& param, SCOPE scope);

    //将函数定义体中的形参由全局变量变为局部变量
    void convertMethodParamToTemp(const QString &str, const int &pos);

    //将函数参数列表的参数类型提取出来
    QList<QString> onlyGetMethodParamType(const QString &str);

    //返回任意表达式的类型，如函数调用，变量
    QString getExpressionType(const QString &str, const int &pos);

    //返回任意表达式的类型，如函数调用，变量
    QString getExpressionType(const QString &exp);

    //画Issue所在行号的问题图标
    template <typename T>
    void drawIssueImage(const QList<T> &list, QPainter &painter, int offset, int imageHeight = 0);

signals:
    void showSCMFault(int);
    void hideProblemTab();
    void showHeaderFileIssue();
    void showSourceFileIssue(const QList<ClassUndefinedSyntaxIssue> & list);

    void updateToDoRequireNote(const QString& filePath, const QVector<RequireNote*>& note);

    //通知主窗口更新类文件
    void updateClassFiles(QString filePath, QHash<QString, ClassInfo>& classInfoHash);

    //通知主窗口更新自然语言规格位置
    void updateInformalSpecPos(QString filePath, QList<InformalSpecInfo>& informalSpecInfos);

    //更新当前文件的函数及对应代码
    void updateMethodNameToCode(QHash<QString, QString> methodNameToCode);

    void startChatGPTDialog(QString);

    void startChatGPTFixCode(QString);

    void allSegmentsReviewComplete();


};

class LineNumberArea : public QWidget
{
    Q_OBJECT
    friend class MdiChild;
public:
    LineNumberArea(MdiChild *editor) : QWidget(editor) {
        codeEditor = editor;
        iconX = 0;
        iconY = 0;
        faultWarningButton = new CustomButton(this);
        faultWarningButton->setVisible(false);
        connect(editor->verticalScrollBar(), &QScrollBar::valueChanged, this, &LineNumberArea::updateFaultImagePosition);
    }

    QSize sizeHint() const Q_DECL_OVERRIDE {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

    // 设置图标的位置
    void setIconPosition(int x, int y) {
        iconX = x;
        iconY = y;
        qDebug() << "iconY: " << iconY;
    }

    QPoint getIconPosition(){
        return QPoint(iconX, iconY);
    }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE {   //A paint event is a request to repaint all or part of a widget. It can happen
                                                                                                        //when repaint() or update() was invoked
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    MdiChild *codeEditor;
    CustomButton* faultWarningButton;
    int iconX;
    int iconY;

private slots:
    void updateFaultImagePosition() {
        update();
    }
};

class FoldingWidget: public QWidget
{
    Q_OBJECT

public:
    FoldingWidget(MdiChild *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const Q_DECL_OVERRIDE{
        return QSize(codeEditor->foldingWidgetWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE {
             codeEditor->foldingWidgetPaintEvent(event);
    }

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE{
        codeEditor->foldingWidgetMousePressEvent(event);
    }

    void enterEvent(QEvent *event) Q_DECL_OVERRIDE{
        Q_UNUSED(event);
        // 当光标进入部件时调用
        QPoint cursorPos = QCursor::pos();
        codeEditor->foldingWidgetHighlight(cursorPos);
    }

private:
    MdiChild *codeEditor;
    int width;
};



//定义变量结构
struct Variable
{
    QString name;
    QString className;
    QString type;
    SCOPE scope = NONE;  //作用域
    Variable(QString name, QString className, QString type, SCOPE scope = NONE):
        name(name), className(className), type(type), scope(scope){}

    // 重载 == 运算符
    bool operator==(const Variable& other) const {
        return (name == other.name && className == other.className && type == other.type && scope == other.scope);
    }

    //用于覆盖类型中包括UNSPECIFIED的情况
    bool operator >= (const Variable& other) const {
        bool res1 = (name == other.name && className == other.className && scope == other.scope);
        bool res2 = (other.type == UNSPECIFIED) || (type == other.type);
        return res1 && res2;
    }
};

inline uint qHash(const Variable& var) {
    return qHash(var.name) + qHash(var.className) + qHash(var.type); // 哈希计算方法可以根据具体情况进行修改
}

//定义函数结构
struct Method
{
    QString name;
    QString className;   //所属的类，非成员函数则为空
    QString returnType;
    QList<QString> parameters;   //函数的参数
    QString paramStr;
    SCOPE scope = GLOBAL;
    Method(QString name, QString className, QString returnType = "void",
           QStringList params = {}, QString paramStr = "", SCOPE scope = GLOBAL):
        name(name), className(className), returnType(returnType), parameters(params),
        paramStr(paramStr), scope(scope){}

    //这里重载 == 运算符，先不考虑同名函数，参数不同的情况
    bool operator==(const Method& other) const {
        return (name == other.name && className == other.className
                && returnType == other.returnType && scope == other.scope
                && parameters == other.parameters && paramStr == other.paramStr);
    }

    //用于覆盖类型中包括UNSPECIFIED的情况
    bool operator >= (const Method& other) const {
        bool res1 = (name == other.name && className == other.className && scope == other.scope
                     && parameters.size() == other.parameters.size());
        bool res2 = (other.returnType == UNSPECIFIED) || (returnType == other.returnType);
        bool res3 = res1 && res2;
        for(int i = 0; res3 && i < parameters.size(); ++i){
            bool res = (parameters[i] == other.parameters[i]) || (other.parameters[i] == UNSPECIFIED);
            res3 = res3 && res;
        }
        return res3;
    }
};


//类的信息
struct ClassInfo
{
    QList<Variable>* vars;
    QList<Method>* methods;
    QString name;   //类名

    ClassInfo() : vars(new QList<Variable>()), methods(new QList<Method>()), name(""){}
    ClassInfo(QString name): vars(new QList<Variable>()), methods(new QList<Method>()), name(name){}
};

struct InformalSpecInfo
{
    QString sectionNumber;
    int lineNumber;

    InformalSpecInfo() : sectionNumber(""), lineNumber(0){}
    InformalSpecInfo(QString _sectionNum, int _lineNum) : sectionNumber(_sectionNum), lineNumber(_lineNum){}
};

#endif
