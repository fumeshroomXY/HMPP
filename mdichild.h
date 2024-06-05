#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include <QObject>
#include <faultpromptdialog.h>
#include <highlighter.h>
#include <QVector>
#include <QEvent>
#include <QTextBlock>
#include <QScrollBar>
#include <QDebug>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;
class FoldingWidget;
class CustomButton;

//定义作用域
enum SCOPE
{
    NONE, GLOBAL, LOCAL, CLASS
};

struct Variable;
struct Method;
struct ClassInfo;



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

    void newFile();
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
protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;   //关闭事件


    //void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

public slots:
    void resizeEvent(QResizeEvent *event);
    void faultLinePaint(int blockNumber);
    void setFixText(QString var1, QString var2);

    //fault弹窗，quickfix并确定后触发
    void faultFixOkClicked();

private slots:
    void documentWasModified();    //文件被更改时显示更改窗口状态

    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    //void updateLineNumberArea(const QRect &, int);
    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea();

    void showFaultPromptDialog(int lineNumber);

    void fixButtonHovered();
    void fixButtonClicked();
    void clearPreview();

    void highlightMatch();


    //更新需求括号的匹配
    void updateMatch();

    //当检测到>>>，自动插入<<<
    void autoCompleteMatch();

    //更新faultBox的位置
    void moveFaultPromptDialog();

private:
    //更新需求节点
    void updateRequireNotes(int start, int end, RequireNote* node);

    bool maybeSave();   //是否需要保存
    void setCurrentFile(const QString &fileName);   //设置当前文件
    QString strippedName(const QString &fullFileName);

    QString curFile;     //保存当前文件路径
    bool isUntitled;    //作为当前文件是否被保存到硬盘上的标志

    //绘制行号的区域
    LineNumberArea *lineNumberArea;

    QWidget *foldingWidget;

    Highlighter* highlighter;

    FaultPromptDialog* faultPrompt;
    QString previewText;
    bool insertPreview = false;
    bool faultflag = true;
    bool fixedfalg = false;

    bool matchLeftParenthesis(QTextBlock currentBlock, int index,
                              int numRightParentheses, int &matchLineNumber, int &matchPosition);
    bool matchRightParenthesis(QTextBlock currentBlock, int index,
                               int numLeftParentheses, int &matchLineNumber, int &matchPosition);
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

signals:
    void showProblemTab(int);
    void hideProblemTab();

    //通知主窗口更新类文件
    void updateClassFiles(QString filePath, QHash<QString, ClassInfo>& classInfoHash);

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
                && parameters == other.parameters);
    }
};


//类的信息
struct ClassInfo
{
    QList<Variable>* vars;
    QList<Method>* methods;
    QString name;   //类名

    ClassInfo() {}
    ClassInfo(QString name): vars(new QList<Variable>()), methods(new QList<Method>()), name(name){}
};

#endif
