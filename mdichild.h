#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include <QObject>
#include <faultpromptdialog.h>
#include <QVector>
#include <QEvent>

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class LineNumberArea;
class FoldingWidget;
class CustomButton;


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

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;   //关闭事件


    //void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

public slots:
    void resizeEvent(QResizeEvent *event);
    void faultLinePaint(int blockNumber);
    void setFixText(QString var1, QString var2);

private slots:
    void documentWasModified();    //文件被更改时显示更改窗口状态

    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    //void updateLineNumberArea(const QRect &, int);
    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea();

    void showFaultPromptDialog();

    void fixButtonHovered();
    void fixButtonClicked();
    void clearPreview();

    void highlightMatch();


    //更新需求括号的匹配
    void updateMatch();

    //当检测到>>>，自动插入<<<
    void autoCompleteMatch();


private:
    //更新需求节点
    void updateRequireNotes(int start, int end, RequireNote* node);

    bool maybeSave();   //是否需要保存
    void setCurrentFile(const QString &fileName);   //设置当前文件
    QString strippedName(const QString &fullFileName);

    QString curFile;     //保存当前文件路径
    bool isUntitled;    //作为当前文件是否被保存到硬盘上的标志

    //绘制行号的区域
    QWidget *lineNumberArea;

    QWidget *foldingWidget;

    CustomButton * button;
    FaultPromptDialog* faultPrompt;
    QString previewText;
    bool insertPreview = false;
    bool faultflag = true;
    bool fixedfalg = false;

    bool matchLeftParenthesis(QTextBlock currentBlock, int index, int numRightParentheses, int &matchLineNumber, int &matchPosition);
    bool matchRightParenthesis(QTextBlock currentBlock, int index, int numLeftParentheses, int &matchLineNumber, int &matchPosition);
    void createParenthesisSelection(int pos);



    //需求伪码注释节点列表
    QVector<RequireNote *> requireNotes;


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




signals:
    void showProblemTab(int);
    void hideProblemTab();

};

class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(MdiChild *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const Q_DECL_OVERRIDE {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE {   //A paint event is a request to repaint all or part of a widget. It can happen
                                                                                                        //when repaint() or update() was invoked
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    MdiChild *codeEditor;
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


#endif
