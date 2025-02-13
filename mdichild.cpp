#include <QtWidgets>
#include <QPlainTextEdit>
#include <QtGlobal>
#include <algorithm>

#include "mdichild.h"
#include "faultpromptdialog.h"
#include "highlighter.h"
#include "syntaxrule.h"
#include "faultlinehighlighter.h"
#include "mainwindow.h"



MdiChild::MdiChild(QWidget *parent): QTextEdit(parent)
{
    qDebug() << "-1";
    setAttribute(Qt::WA_DeleteOnClose);   //delete this widget when the widget has accepted the close event
    isUntitled = true;

    lineNumberArea = new LineNumberArea(this);
    foldingWidget = new FoldingWidget(this);
    faultPrompt = new FaultPromptDialog(this);
    classInfoHash = new QHash<QString, ClassInfo>();

    syntaxIssueList = QList<ClassUndefinedSyntaxIssue> ();
    unspecifiedTypeIssueList = QList<ClassMemberUnspecifiedIssue> ();

    highlighter = new Highlighter(this->document());


    globalVars = new QList<Variable>();   //全局变量表
    definedMethods = new QList<Method>();    //已经有函数体的函数表，比如类内函数或全局函数
    Methods = new QList<Method>();   //调用的函数表



    connect(document(), SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(faultLinePaint()));

    //高亮光标所在行
    //connect(this, &QTextEdit::cursorPositionChanged, this, highlightCurrentLine);

    connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateLineNumberArea/*_2*/(int)));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateLineNumberArea()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(updateLineNumberArea()));
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(showFaultPromptDialog()));

    updateLineNumberAreaWidth(0);
    //highlightCurrentLine();
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(faultPrompt, &FaultPromptDialog::clickedSignal, this, &MdiChild::fixButtonClicked);
    //connect(faultPrompt, &FaultPromptDialog::clickedSignal, this, &MdiChild::fixButtonHovered);
    connect(faultPrompt, &FaultPromptDialog::unfixSignal, this, &MdiChild::clearPreview);
    connect(faultPrompt, &FaultPromptDialog::okclicked, this, &MdiChild::faultFixOkClicked);
//    connect(faultPrompt, &FaultPromptDialog::releasedSignal, this, &MdiChild::clearPreview);
//    connect(faultPrompt, &FaultPromptDialog::leftSignal, this, &MdiChild::clearPreview);

    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightMatch()));

    //这个函数有问题，先不用了
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(autoCompleteMatch()));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateMatch()));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateInformalSpecPosInFile()));
    qDebug() << "-1";
}

void MdiChild::newFile(QString fileName)
{
    qDebug() << "-2";
    static int sequenceNumber = 1;

    isUntitled = true;    //新建的文档没有被保存过
    //新建文件，curFile存的不是文件的完整路径，所以不推荐直接新建文件，最好是先新建项目
    if(fileName.isEmpty()){
        curFile = tr("document%1.txt").arg(sequenceNumber++);  //当前文件命名
    }else{
        curFile = fileName;
    }
    setWindowTitle(curFile + "[*]");

    connect(document(), &QTextDocument::contentsChanged,
            this, &MdiChild::documentWasModified);
    qDebug() << "-2";
}

bool MdiChild::loadFile(const QString &fileName)
{
    qDebug() << "-3";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) { //只读方式打开文件，出错则提示
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        qDebug() << "-3";
        return false;
    }

    curFile = QFileInfo(fileName).canonicalFilePath();    //可以去除路径中的符号链接，"."和".."等符号

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);   //设置鼠标状态为等待状态
    setPlainText(in.readAll());    //读取文件全部内容，并添加到编辑器中
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);   //设置当前文件

    connect(document(), &QTextDocument::contentsChanged,
            this, &MdiChild::documentWasModified);

    QString shortFileName = userFriendlyCurrentFile();
    int dotIndex = shortFileName.lastIndexOf('.');
    if(dotIndex <= 0) {
        qDebug() << "Cannot resolve the file className";
        qDebug() << "fileName: " << shortFileName;
    }else{
        fileClassName = shortFileName.left(dotIndex);
    }
    qDebug() << "-3";
    return true;
}

bool MdiChild::save()
{
    qDebug() << "-4";
    //当用户保存时，分析文件结构，得到函数和变量信息


    if (isUntitled) {
        bool flag = saveAs();
        if(flag) {
            updateObjectInfoInSourceFile();
            updateObjectInfoInHeaderFile();
        }
        qDebug() << "-4";
        return flag;
    } else {
        bool flag = saveFile(curFile);
        if(flag) {
            updateObjectInfoInSourceFile();
            updateObjectInfoInHeaderFile();
        }
        qDebug() << "-4";
        return flag;
    }
}

bool MdiChild::saveAs()
{
    qDebug() << "-5";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty()){
        qDebug() << "-5";
        return false;
    }
    qDebug() << "-5";
    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    qDebug() << "-6";
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        qDebug() << "-6";
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();   //以纯文本文件写入
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    qDebug() << "-6";
    return true;
}

QString MdiChild::userFriendlyCurrentFile()  //提取文件名，从文件路径中提取文件名
{
    return strippedName(curFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    qDebug() << "-7";
    if (maybeSave()) {

        event->accept();
    } else {    //如果文档未被更改过，或更改了但取消关闭，或放弃保存

        event->ignore();
    }
    qDebug() << "-7";
}

void MdiChild::keyPressEvent(QKeyEvent *event)
{
    // 检测 Ctrl + T 组合键
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_T) {
        // 检查光标是否在视口内
        // 获取当前光标
        QTextCursor cursor = textCursor();
        // 获取光标的矩形区域
        QRect cursorRect = this->cursorRect(cursor);
        // 获取文本编辑器的视口矩形区域
        QRect viewportRect = this->viewport()->rect();

        if(viewportRect.contains(cursorRect)){
            int pos = cursor.position();
            cursor.insertText(RequireNoteStartStr + "\n\n" + RequireNoteEndStr);
            cursor.setPosition(pos + RequireNoteStartStr.length());
        }
        // 忽略事件
        event->accept();
    } else {
        // 调用父类的键盘事件处理方法
        QTextEdit::keyPressEvent(event);
    }
}

void MdiChild::contextMenuEvent(QContextMenuEvent *event)
{
    // Call the base class method to get the default context menu
    QMenu* menu = createStandardContextMenu();

    QAction* fixCodeAction = menu->addAction("Fix the current method");

    // Connect the action to a custom slot
    connect(fixCodeAction, &QAction::triggered, this, &MdiChild::fixCodeTriggered);

    // Add custom action to the menu
    QAction* askChatGPTAction = menu->addAction("Ask ChatGPT about this...");

    // Connect the action to a custom slot
    connect(askChatGPTAction, &QAction::triggered, this, &MdiChild::askChatGPTTriggered);

    QAction* addBugDescription = menu->addAction("Add a bug description");

    connect(addBugDescription, &QAction::triggered, this, &MdiChild::addBugTriggered);

    if (getCscrToolMode() == false) {
        addBugDescription->setEnabled(false);
    }

    // Show the menu at the cursor's position
    menu->exec(event->globalPos());

    // Don't forget to delete the menu after it's used
    delete menu;
}

void MdiChild::documentWasModified()
{
    qDebug() << "-8";
    setWindowModified(document()->isModified());  //QTextDocument类的isModified函数
    //使用QTextEdit类的document函数获取它的QTextDocument类
    qDebug() << "-8";
}

bool MdiChild::maybeSave()   //是否需要保存
{
    qDebug() << "-9";
    if (!document()->isModified()){  //如果文档未被更改过
        qDebug() << "-9";
        return true;
    }
    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Save warning"),
                                   tr("'%1' has been modified.\n"
                                      "Do you want to save your changes?")
                                   .arg(userFriendlyCurrentFile()),
                                   QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:{
        qDebug() << "-9";
        return save();
    }
    case QMessageBox::Cancel:{
        qDebug() << "-9";
        return false;
    }
    default:
        break;
    }
    qDebug() << "-9";
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    qDebug() << "-10";
    curFile = QFileInfo(fileName).canonicalFilePath();    //可以去除路径中的符号链接，"."和".."等符号
    isUntitled = false;   //文件已经被保存过了
    document()->setModified(false);   //文档没有被更改过
    setWindowModified(false);   //窗口不显示被更改标志
    setWindowTitle(userFriendlyCurrentFile() + "[*]");  //设置窗口标题，userFriendlyCurrentFile返回文件名
    qDebug() << "-10";
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

int MdiChild::getCurrentReviewLine() const
{
    return currentReviewLine;
}

void MdiChild::setCurrentReviewLine(int value)
{
    currentReviewLine = value;
}

bool MdiChild::getCscrToolMode() const
{
    return cscrToolMode;
}

void MdiChild::setCscrToolMode(bool value)
{
    cscrToolMode = value;
}

MainWindow *MdiChild::getMainWindowPtr() const
{
    return mainWindowPtr;
}

void MdiChild::setMainWindowPtr(MainWindow *value)
{
    mainWindowPtr = value;
}

QList<ClassMemberUnspecifiedIssue> MdiChild::getUnspecifiedTypeIssueList()
{
    updateIssueInfoInSourceFile();
    return unspecifiedTypeIssueList;
}


int MdiChild::lineNumberAreaWidth()
{
    int digits = 1;   //行号的位数
    int max = qMax(1, document()->blockCount());  //当前文档的行数
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    int lineHeight = fontMetrics().height();
    int space = lineHeight + fontMetrics().width(QLatin1Char('9')) * digits;   //可以指定其他width
    return space;
}

int MdiChild::foldingWidgetWidth()
{
    int space = fontMetrics().height();
    return space;
}

void MdiChild::foldingWidgetHighlight(QPoint pos)
{
    qDebug() << "-11";
    //复制mousePressEvent的内容，获取开始和结束行号
    QRect rect =  contentsRect();

    //下面的y和height要调整，y取较大值，height取小值
    foldingWidget->update(lineNumberArea->width() + 1, rect.y(), foldingWidget->width() - 2, rect.height());
    qDebug() << "-11";
}

void MdiChild::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth() + foldingWidgetWidth(), 0, 0, 0);  //左边留下行号和折叠标记的空间，可以延长
}

void MdiChild::updateLineNumberArea(QRectF /*rect_f*/)
{
    MdiChild::updateLineNumberArea();
}
void MdiChild::updateLineNumberArea(int /*slider_pos*/)
{
    MdiChild::updateLineNumberArea();
}
void MdiChild::updateLineNumberArea()
{
    qDebug() << "-12";
    //qDebug()  <<  "start: " << "updateLineNumberArea";
    /*
     * When the signal is emitted, the sliderPosition has been adjusted according to the action,
     * but the value has not yet been propagated (meaning the valueChanged() signal was not yet emitted),
     * and the visual display has not been updated. In slots connected to this signal you can thus safely
     * adjust any action by calling setSliderPosition() yourself, based on both the action and the
     * slider's value.
     */
    // Make sure the sliderPosition triggers one last time the valueChanged() signal with the actual value !!!!
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    // Since "QTextEdit" does not have an "updateRequest(...)" signal, we chose
    // to grab the imformations from "sliderPosition()" and "contentsRect()".
    // See the necessary connections used (Class constructor implementation part).

    QRect rect =  contentsRect();   //Returns the area inside the widget's margins.
    // schedules a paint event for processing when Qt returns to the main event loop.
    lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());  //horizontal x，vertical y

    foldingWidget->update(0, rect.y(), foldingWidget->width(), rect.height());

    updateLineNumberAreaWidth(0);
    //----------
    int dy = verticalScrollBar()->sliderPosition();
    if (dy > -1) {
        lineNumberArea->scroll(0, dy);   //dx = 0, dy = dy, 如果scrollbar滚动了的话，linenumberarea也要跟着滚动
        foldingWidget->scroll(0, dy);
    }
    // Adjust slider to alway see the number of the currently being edited line...
    // Not sure what the part does.
    int firstBlockId = getFirstVisibleBlockId();
    if (firstBlockId == 0 || textCursor().block().blockNumber() == firstBlockId - 1)
//        qDebug() << "firstBlockId :" << firstBlockId;
//        qDebug() << "textCursor:" << textCursor().block().blockNumber();
        verticalScrollBar()->setSliderPosition(dy - document()->documentMargin());

    //qDebug()  <<  "end: " << "updateLineNumberArea";
    qDebug() << "-12";
}


void MdiChild::resizeEvent(QResizeEvent *e)
{
    qDebug() << "-13";
    QTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    int width = lineNumberAreaWidth();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), width, cr.height()));
    foldingWidget->setGeometry(QRect(cr.left() + width, cr.top(), foldingWidgetWidth(), cr.height()));
    qDebug() << "-13";
}

int MdiChild::getFirstVisibleBlockId()
{
    qDebug() << "-14";
    // Detect the first block for which bounding rect - once translated
    // in absolute coordinated - is contained by the editor's text area

    // Costly way of doing but since "blockBoundingGeometry(...)" doesn't
    // exists for "QTextEdit"...

    QTextCursor curs = QTextCursor(document());
    curs.movePosition(QTextCursor::Start);    //Move to the start of the document.
    for(int i=0; i < document()->blockCount(); ++i)
    {
        QTextBlock block = curs.block();

        QRect r1 = viewport()->geometry();
        QRect r2 = document()->documentLayout()->blockBoundingRect(block).translated(
                    viewport()->geometry().x(), viewport()->geometry().y() - verticalScrollBar()->sliderPosition()).toRect();

        if (r1.contains(r2, true)) { return i; }

        curs.movePosition(QTextCursor::NextBlock);
    }

    qDebug() << "-14";
    return 0;
}

void MdiChild::highlightCurrentLine()
{
//    QTextBlock block = document()->findBlockByNumber(12);
//    block.setUserState(2);

//    QTextBlock currentBlock = textCursor().block();
//    qDebug() << "currentBlockState: " << currentBlock.userState();

    qDebug() << "-15";
    QList<QTextEdit::ExtraSelection> extraSelections = this->extraSelections();
    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
    qDebug() << "-15";
}

void MdiChild::clearStructureNumberList()
{
    this->structureNumberList.clear();
    highlightSegments(this->structureNumberList);
}

void MdiChild::addToStructureNumberList()
{
    int number = textCursor().blockNumber();
    // Check for duplicates
    if (structureNumberList.contains(number)) {
        return; // Do nothing if the value already exists
    }

    // Insert in sorted order
    auto it = std::lower_bound(structureNumberList.begin(), structureNumberList.end(), number);
    // Convert iterator to index
    int index = std::distance(structureNumberList.begin(), it);

    // Insert at the correct position
    structureNumberList.insert(index, number);

    QStringList stringList;
    for (int i = 0; i < structureNumberList.size(); ++i) {
        stringList << QString::number(structureNumberList[i]);  // Convert each integer to a QString
    }
    qDebug() << "structureNumberList: " <<stringList.join(", ");

    recentlyInsertedNumber = number;
    highlightSegments(this->structureNumberList);
}

void MdiChild::undoStructureNumberList()
{
    structureNumberList.removeOne(recentlyInsertedNumber);
    highlightSegments(this->structureNumberList);
}

void MdiChild::scrollToLine(int lineNumber) {
    qDebug() << "MdiChild::scrollToLine,  lineNumber = " << lineNumber;
    QTextDocument *doc = document();
    if (!doc) return;

    QTextBlock block = doc->findBlockByNumber(lineNumber);
    if (!block.isValid()) return;

    // Move the cursor to the desired block
    QTextCursor cursor(block);
    setTextCursor(cursor);

    // Ensure the cursor is visible
    ensureCursorVisible();

    // Force the block to appear at the top
    QScrollBar *scrollBar = verticalScrollBar();
    if (scrollBar) {
        int cursorY = cursor.block().layout()->position().y();
        qDebug() << "cursorY: " << cursorY;
        scrollBar->setValue(cursorY);
    }
}

void MdiChild::scrollToCurrentReviewLine()
{
    scrollToLine(currentReviewLine);
}

void MdiChild::scrollToFirstLine()
{
    scrollToLine(0);
}

bool MdiChild::isAllSegmentsReviewed()
{
    if(currentReviewLine >= document()->blockCount()){
        return true;
    }else{
        return false;
    }
}

void MdiChild::moveToNextReviewSegment()
{
    QList<QTextEdit::ExtraSelection> selections = this->extraSelections();
    if(structureNumberList.isEmpty()){
        //resetBlockColors(0, document()->blockCount(), Qt::transparent, selections);
        emit allSegmentsReviewComplete();
        currentReviewLine = document()->blockCount();
        scrollToCurrentReviewLine();
        setExtraSelections(selections);
        return;
    }

    auto it = std::lower_bound(structureNumberList.begin(), structureNumberList.end(), currentReviewLine);
    if (it == structureNumberList.end()) {
        //structureNumberList.clear();
        //highlightSegments(structureNumberList);
        //resetBlockColors(currentReviewLine, document()->blockCount(), Qt::transparent, selections);
        emit allSegmentsReviewComplete();
        currentReviewLine = document()->blockCount();
        scrollToCurrentReviewLine();
    }else{
        //structureNumberList.removeOne((*it));
        //highlightSegments(structureNumberList);
        //resetBlockColors(currentReviewLine, (*it) + 1, Qt::transparent, selections);
        currentReviewLine = (*it) + 1;
        scrollToCurrentReviewLine();
    }
    setExtraSelections(selections);
}

void MdiChild::resetBlockColors(int startLine, int endLine, const QColor &color, QList<QTextEdit::ExtraSelection>& selections) {

    // Save the current cursor position
    QTextCursor originalCursor = textCursor();

    qDebug() << "resetBlockColors: startLine = " << startLine << " endLine = " << endLine;
    qDebug() << "QColor: " << color;

    int totalBlocks = document()->blockCount();
    if (startLine < 0 || endLine > totalBlocks || startLine >= endLine) {
        qDebug() << "Invalid block range";
        return;
    }

    QTextDocument *doc = document();
    if (!doc) return;

    // Clear previous selections
    qDebug() << "Applied extraSelections count before:" << selections.size();

    // Iterate through all blocks from startLine to endLine (excluding endLine)
    for (QTextBlock block = doc->findBlockByNumber(startLine);
         block.isValid() && block.blockNumber() < endLine;
         block = block.next()) {

        int blockNumber = block.blockNumber();
        qDebug() << "Processing block: " << blockNumber;

        // Create a selection to reset the background color
        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(color);
        selection.cursor = QTextCursor(block);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selections.append(selection);
    }

    // Apply the selections
    qDebug() << "Applied extraSelections count after:" << selections.size();

    // Restore the original cursor position
    setTextCursor(originalCursor);

    update();
}



void MdiChild::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    qDebug() << "-16";
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    QPainter painter(lineNumberArea);   //将lineNumberArea作为paint device
    painter.fillRect(event->rect(), QColor(240, 240, 240));   //整个边界背景设置为浅灰
    QImage pixmap(":/images/toolbar_images/error.png");

    int blockNumber = getFirstVisibleBlockId();

    QTextBlock block = document()->findBlockByNumber(blockNumber);
    QTextBlock prev_block = (blockNumber > 0) ? document()->findBlockByNumber(blockNumber - 1) : block;
    int translate_y = (blockNumber > 0) ? - verticalScrollBar()->sliderPosition() : 0;

    int top = viewport()->geometry().top();

    // Adjust text position according to the previous "non entirely visible" block
    // if applicable. Also takes in consideration the document's margin offset.
    int additional_margin;
    if (blockNumber == 0)
        // Simply adjust to document's margin, default documentMargin is 4.
        additional_margin = (int) document()->documentMargin() -1 - verticalScrollBar()->sliderPosition();
    else
        // Getting the height of the visible part of the previous "non entirely visible" block
        additional_margin = (int) document()->documentLayout()->blockBoundingRect(prev_block)
                .translated(0, translate_y).intersected(viewport()->geometry()).height();

    // Shift the starting point
    top += additional_margin;

    int bottom = top + (int) document()->documentLayout()->blockBoundingRect(block).height();

    QColor col_1(90, 255, 30);      // Current line (custom green)
    QColor col_0(120, 120, 120);    // Other lines  (custom darkgrey)

    // Draw the numbers (displaying the current line number in green)


    QTextBlock faultBlock = document()->findBlockByNumber(faultLineNumber);
    int lineHeight = (int)document()->documentLayout()->blockBoundingRect(faultBlock).height(); //每行的高度
    int lineTop = (int)document()->documentLayout()->blockBoundingRect(faultBlock).translated(0, translate_y).top();
    qDebug() << "lineHeight: " << lineHeight;
    qDebug() << "lineTop: " << lineTop;

    if(lineNumberArea->getIconPosition().x() >= 0 && lineNumberArea->getIconPosition().y() >= 0
            && faultBlock.isValid() && faultBlock.isVisible()){
        lineNumberArea->setIconPosition(0, lineTop);
        QImage scaledPixmap = pixmap.scaled(lineHeight, lineHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.drawImage(lineNumberArea->getIconPosition(), pixmap);
    }

    drawIssueImage(syntaxIssueList, painter, translate_y);
    drawIssueImage(unspecifiedTypeIssueList, painter, translate_y);

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);   //blockNumber 从0开始，所以要+1
            painter.setPen(col_0);
            //painter.setPen((textCursor().blockNumber() == blockNumber) ? col_1 : col_0);
            painter.drawText(-2, top,   //why starts from -5, 增加了数字的右边距
                             lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);

        }

        block = block.next();
        top = bottom;
        //这里不能直接加lineHeight
        //bottom = top + lineHeight;
        bottom = top + (int)document()->documentLayout()->blockBoundingRect(block).height();
        ++blockNumber;
    }
    if(lineNumberArea->faultWarningButton->getFaultLine() != -1){
        lineNumberArea->faultWarningButton->setVisible(true);
    }
    qDebug() << "-16";
}

template <typename T>
void MdiChild::drawIssueImage(const QList<T>& list, QPainter& painter, int offset, int imageHeight)
{
    int translate_y = offset;
    QTextBlock startBlock = document()->findBlockByNumber(0);
    imageHeight = (int)document()->documentLayout()->blockBoundingRect(startBlock).height(); //每行的高度

    for(const T & issue : list){
        int lineNumber = issue.getIssueLineNumber();
        qDebug() << "ClassEncapsulateSyntaxIssue: " << lineNumber;
        QTextBlock faultBlock = document()->findBlockByNumber(lineNumber);
        //QImage image(":/images/toolbar_images/error.png");
        QImage image = issue.getImage();
        int top = (int)document()->documentLayout()->blockBoundingRect(faultBlock).translated(0, translate_y).top();

        qDebug() << "top" << top;
        if(faultBlock.isValid() && faultBlock.isVisible()){
            qDebug() << "lineHeight" << imageHeight;
            QImage scaledimage = image.scaled(imageHeight, imageHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            painter.drawImage(0, top,  scaledimage);
        }
    }
}

void MdiChild::foldingWidgetPaintEvent(QPaintEvent *event)
{
    qDebug() << "-17";
    if(requireNotes.isEmpty()) {
        qDebug() << "-17";
        return;
        }//需求注释为空直接返回
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    QPainter painter(foldingWidget);   //将foldingWidget作为paint device
    painter.fillRect(event->rect(), QColor(240, 240, 240));   //整个边界背景设置为浅灰
    int blockNumber = getFirstVisibleBlockId();

    QVector<RequireNote*>::const_iterator it = requireNotes.constBegin();
    while(it != requireNotes.constEnd() && (*it)->startLine < blockNumber){  //找到视图中能看到的第一个匹配符所在行的需求注释
        it++;
    }

    int translate_y = (blockNumber > 0) ? - verticalScrollBar()->sliderPosition() : 0;


    //QColor col_1(90, 255, 30);      // Current line (custom green)
    QColor col_0(120, 120, 120);    // Other lines  (custom darkgrey)
    painter.setPen(col_0);

    // 在每个匹配的行上绘制折叠箭头
    while (it != requireNotes.constEnd()) {
        QTextBlock block = document()->findBlockByNumber((*it)->startLine);
        //减去滚轮移动的y轴上的距离，得到viewport中的相对坐标
        QRectF rect = document()->documentLayout()->blockBoundingRect(block).translated(0, translate_y);
        qDebug() << "rect: " << rect;
        if (block.isVisible() && rect.top() >= event->rect().top() && rect.bottom() <= event->rect().bottom()) {

            painter.drawText(-2, rect.top(),   //why starts from -5, 增加了数字的右边距
                             foldingWidget->width(), fontMetrics().height(),
                             Qt::AlignRight, ">");
            it++;
        }else{
            break;
        }
    }
    qDebug() << "-17";
}

void MdiChild::foldingWidgetMousePressEvent(QMouseEvent *event)
{
    qDebug() << "-18";
    if(requireNotes.isEmpty()) {
        qDebug() << "-18";
        return;   //需求注释为空直接返回
    }
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    int blockNumber = getFirstVisibleBlockId();

    QVector<RequireNote*>::const_iterator it = requireNotes.constBegin();
    while(it != requireNotes.constEnd() && (*it)->endLine < blockNumber){  //找到视图中能看到的第一个匹配符所在行的需求注释
        it++;
    }

    if(it != requireNotes.constEnd()) qDebug() << "FirstNote: " << (*it)->endLine;
    int translate_y = (blockNumber > 0) ? - verticalScrollBar()->sliderPosition() : 0;

    int viewTop = viewport()->geometry().top();
    int viewBot = viewport()->geometry().bottom();

    qDebug() << "viewTop:" << viewTop;
    qDebug() << "viewBot:" << viewBot;

    QVector<RequireNote*>::const_iterator res = requireNotes.constEnd();
    while (it != requireNotes.constEnd()) {
        qDebug() << "it: " << (*it)->startLine;
        QTextBlock startBlock = document()->findBlockByNumber((*it)->startLine);
        QTextBlock endBlock = document()->findBlockByNumber((*it)->endLine);
        //减去滚轮移动的y轴上的距离，得到viewport中的相对坐标
        QRectF sRect = document()->documentLayout()->blockBoundingRect(startBlock).translated(0, translate_y);
        QRectF eRect = document()->documentLayout()->blockBoundingRect(endBlock).translated(0, translate_y);
        //qDebug() << "Line: " << (*it)->startLine;
        qDebug() << "top: " << sRect.top();
        qDebug() << "bot: " << eRect.bottom();
        qDebug() << "posy:" << event->pos().y();
        if(sRect.top() > viewBot || eRect.bottom() < viewTop ) break;   //超出可视范围，直接返回
        if ((startBlock.isVisible() || endBlock.isVisible())   //两个文本块，至少有一个是可视的
                && sRect.top() <= event->pos().y() && eRect.bottom() >= event->pos().y()) {  //点击位置位于文本块之间
            res = it;
        }
        it++;
    }
    if(res != requireNotes.constEnd()) {
        qDebug() << "Line: " << (*res)->startLine;
    }
    qDebug() << "-18";
}

void MdiChild::faultLinePaint(int blockNumber)
{
    qDebug() << "-19";
    qDebug() << "faultblockNumber: " << blockNumber;
    //只针对演示文件
    if(!curFile.endsWith("demo/demo.cpp")) return;
    faultLineNumber = blockNumber;

    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());
    int firstBlockNumber = getFirstVisibleBlockId();
    int translate_y = (firstBlockNumber > 0) ? - verticalScrollBar()->sliderPosition() : 0;


    QTextBlock block = document()->findBlockByNumber(blockNumber);
//    int height = (int) document()->documentLayout()->blockBoundingRect(block).height();
//    int top = (int) document()->documentLayout()->blockBoundingRect(block).top();
//    qDebug() << "height: " << height;
//    qDebug() << "top: " << top;
//    qDebug() << "text: " << block.text();
    QRectF blockBox = document()->documentLayout()->blockBoundingRect(block).translated(0, translate_y);
    qDebug() << blockBox;

    QIcon icon = QIcon(":/images/toolbar_images/error.png");
    //QPushButton *faultButton = new QPushButton(this);

    int iconSize = blockBox.height();
    qDebug() << "iconSize: " << iconSize;
    //button->resize(iconSize, iconSize);
    if(block.isValid() && block.isVisible()){
        lineNumberArea->setIconPosition(0, blockBox.top());
        qDebug() << "button appears.";
        qDebug() << blockBox;

//        this->setVisible(true);
//        lineNumberArea->setVisible(true);
//        lineNumberArea->faultWarningButton->setVisible(true);
//        qDebug() << "pos: " << lineNumberArea->faultWarningButton->pos();
    }
    showFaultPromptDialog(blockNumber);
//    setFocus();
    //connect(lineNumberArea->faultWarningButton, &QPushButton::clicked, this, &MdiChild::showFaultPromptDialog);


//    connect(button, &CustomButton::clicked, this, &MdiChild::fixButtonClicked);
//    connect(button, &CustomButton::enterSignal, this, &MdiChild::fixButtonHovered);
//    connect(button, &CustomButton::released, this, &MdiChild::clearPreview);
//    connect(button, &CustomButton::leaveSignal, this, &MdiChild::clearPreview);
    qDebug() << "-19";
}

void MdiChild::showFaultPromptDialog(int lineNumber)
{
    if(faultPrompt->isVisible() == true){
        faultPrompt->setVisible(false);
        return;
    }
    moveFaultPromptDialog();
    faultPrompt->show();
    emit showSCMFault(faultLineNumber);

    connect(this->verticalScrollBar(), &QScrollBar::valueChanged, this, &MdiChild::moveFaultPromptDialog);

    //setFocus();
    //insertPreview = true;
}

void MdiChild::moveFaultPromptDialog()
{
    if(!faultPrompt->isVisible()){
        return;
    }
    QTextBlock block = document()->findBlockByNumber(faultLineNumber);
    if(block.isValid() && block.isVisible()){
        verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());
        int firstBlockNumber = getFirstVisibleBlockId();
        int translate_y = (firstBlockNumber > 0) ? - verticalScrollBar()->sliderPosition() : 0;

        QRectF blockRect = document()->documentLayout()->blockBoundingRect(block).translated(0, translate_y);
        QPoint blockPosition = viewport()->mapToGlobal(blockRect.topLeft().toPoint());
        qDebug() << "blockPosition: " << blockPosition;
        int height = faultPrompt->height();
        // Position the dialog above the block
        QPoint dialogPos(blockPosition.x(), blockPosition.y() - height - blockRect.height() * 2);
        faultPrompt->move(dialogPos);
    }
}

void MdiChild::fixButtonHovered()
{

}

void MdiChild::fixButtonClicked()
{
    if(faultLineNumber == -1){
        return;
    }
    // 按钮悬浮时设置灰色预览效果
    if (insertPreview == false) {
        QTextCursor cursor = textCursor();
        QTextBlock block = document()->findBlockByLineNumber(faultLineNumber);  // 行号从1开始，而 QTextBlock 从0开始，因此需要减去1
        cursor.setPosition(block.position());

        // 设置 QTextEdit 的光标
        setTextCursor(cursor);
        cursor.insertText(previewText, previewFormat);
        insertPreview = true;
    }

    // 点击按钮时插入指定文本
    else{
        QTextCursor cursor = textCursor();
        cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, previewText.length());
        cursor.removeSelectedText();
        cursor.insertText(previewText, insertFormat);
        insertPreview = false;
        lineNumberArea->faultWarningButton->setVisible(false);
        faultPrompt->setVisible(false);
        faultLineNumber = -1;
        emit hideProblemTab();
    }

    //QTextCursor cursor = textCursor();

}

void MdiChild::clearPreview() {
    // 清除预览效果
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, previewText.length());
    cursor.removeSelectedText();
    insertPreview = false;
}

void MdiChild::faultFixOkClicked()
{
    if(insertPreview)  //已经fix了
    {
        faultPrompt->setVisible(false);
        lineNumberArea->setIconPosition(-1, -1);

        QTextCharFormat format;
        format.setUnderlineColor(Qt::red);
        format.setUnderlineStyle(QTextCharFormat::WaveUnderline);

        QRegExp divisionByZero = QRegExp("([a-zA-Z_][a-zA-Z0-9_]*)\\s*/\\s*([a-zA-Z_][a-zA-Z0-9_]*)");
        highlighter->deleteHighlightingRule(divisionByZero, format);
        highlighter->rehighlight();
        emit hideProblemTab();
    }
}

void MdiChild::setFixText(QString var1, QString var2)
{
    previewText = "     if(" + var2 + " == 0){ \"Error: Divide by Zero. Do Something\"} ";
}

int MdiChild::getFaultLineNumber()
{
    return faultLineNumber;
}

int MdiChild::getLineHeight()
{
//    int blockNumber = getFirstVisibleBlockId();
//    QTextBlock block = document()->findBlockByNumber(blockNumber);
//    return (int) document()->documentLayout()->blockBoundingRect(block).height();
    return fontMetrics().height();
}

// walk through and check that we don't exceed 80 chars per line
void MdiChild::highlightMatch()
{
    qDebug() << "-20";
    //qDebug()  <<  "start: " << "highlightMatch";
    //bool match = false;
    QList<QTextEdit::ExtraSelection> selections = extraSelections();
    setExtraSelections(selections);

    //get userdata of the current line where cursor locates
    TextBlockData *data = static_cast<TextBlockData *>(textCursor().block().userData());

    if (data) {
        QVector<MarkInfo *> infos = data->parentheses();
        //Returns the index of the block's first character within the document.
        int pos = textCursor().block().position();
        for (int i = 0; i < infos.size(); ++i) {
            MarkInfo *info = infos.at(i);
            //position of cursor at the current line
            int curPos = textCursor().position() - textCursor().block().position();
            //if cursor is exactly between the first and second char of ">>>", find the match"<<<"
            if(info->matchLineNumber != -1){
                //找到匹配串的位置并高亮
                QTextBlock block = document()->findBlockByLineNumber(info->matchLineNumber);
                QTextCursor cursor(block);
                cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, info->matchPosition);
                int matchPos = cursor.position();


                //光标在{之间就会高亮
                if (curPos >= info->position && curPos <= info->position + info->character.length()) {
                    //if (matchLeftParenthesis(textCursor().block(), i + startStr.size(), 0, info->matchLineNumber, info->matchPosition))
                    //打印匹配到的括号的行号和相对位置
                    //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                    createParenthesisSelection(pos + info->position);   //自身高亮
                    createParenthesisSelection(matchPos);   //匹配串高亮

                } else if (curPos >= info->position && curPos <= info->position + info->character.length()) {
                    //if (matchRightParenthesis(textCursor().block(), i - endStr.size(), 0, info->matchLineNumber, info->matchPosition))
                    //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                    createParenthesisSelection(pos + info->position);
                    createParenthesisSelection(matchPos);   //匹配串高亮
                }
            }

        }
    }
    //updateNotes();
    //requireNotes.clear();
    //updateRequireNotes(-1, document()->lineCount(), nullptr);

    //qDebug()  <<  "end: " << "highlightMatch";
    qDebug() << "-20";
}

void MdiChild::askChatGPTTriggered()
{
    // Get the selected text from the QTextEdit
    QString selectedText = textCursor().selectedText();

    // If there is selected text, return it (e.g., show in a message box)
    if (!selectedText.isEmpty()) {
        emit startChatGPTDialog(selectedText);
    } else {
        QMessageBox::information(this, "No Selection", "No text selected.");
    }
}

void MdiChild::fixCodeTriggered()
{
    // Get the selected text from the QTextEdit
    QString selectedMethod = textCursor().selectedText();

    // If there is selected text, return it (e.g., show in a message box)
    if (!selectedMethod.isEmpty()) {
        emit startChatGPTFixCode(selectedMethod);
    } else {
        QMessageBox::information(this, "No Selection", "No text selected.");
    }
}

void MdiChild::addBugTriggered()
{

}

void MdiChild::updateMatch()
{
    qDebug() << "-21";
    //qDebug() << "start:" << "updateMatch";

    parenthesis.clear();
    requireNotes.clear();
    QTextBlock currentBlock = document()->begin();

    int rootLine = -1;  //当前根括号的右括号所在行
    int rootPos = -1;  //当前根括号的右括号所在位置
    while(currentBlock.isValid()){
        TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
        int lineNumber = currentBlock.blockNumber();


        if (data) {
            QVector<MarkInfo *> infos = data->parentheses();
            //Returns the index of the block's first character within the document.
            for (int i = 0; i < infos.size(); ++i) {
                MarkInfo *info = infos.at(i);

                //position of cursor at the current line
                if (info->character == ParenthesisStartStr) {
                    if(matchLeftMark(currentBlock, i + ParenthesisStartStr.size(), 0, info->matchLineNumber,
                                            info->matchPosition, ParenthesisStartStr, ParenthesisEndStr)){
                        Parenthesis* p = new Parenthesis(info->character, lineNumber, info->position,
                                                     info->matchLineNumber, info->matchPosition);
                        if(p->endLine > rootLine || (p->endLine == rootLine && p->endPos > rootPos)){  //判断根括号
                            p->isRoot = true;
                            rootLine = p->endLine;
                            rootPos = p->endPos;
                        }
                        parenthesis.append(p);
                        //打印匹配到的括号的行号和相对位置
                        //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                    }
                } else if (info->character == ParenthesisEndStr) {
                    if(matchRightMark(currentBlock, i - ParenthesisEndStr.size(), 0, info->matchLineNumber,
                                             info->matchPosition, ParenthesisStartStr, ParenthesisEndStr)){
                        Parenthesis* p = new Parenthesis(info->character, lineNumber, info->position,
                                                     info->matchLineNumber, info->matchPosition);
                        parenthesis.append(p);
                    }
                        //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                }
            }


            QVector<MarkInfo *> noteInfos = data->todoNotes();
            //Returns the index of the block's first character within the document.
            for (int i = 0; i < noteInfos.size(); ++i) {
                MarkInfo *info = noteInfos.at(i);

                //position of cursor at the current line
                if (info->character == RequireNoteStartStr) {
                    if(matchLeftMark(currentBlock, i + RequireNoteStartStr.size(), 0, info->matchLineNumber,
                                            info->matchPosition, RequireNoteStartStr, RequireNoteEndStr)){
                        RequireNote* p = new RequireNote("", lineNumber, info->matchLineNumber, curFile);

                        requireNotes.append(p);
                        //打印匹配到的括号的行号和相对位置
                        //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                    }
                }
            }
        }
        currentBlock = currentBlock.next();
    }
    updateRequireNoteContent();
    emit updateToDoRequireNote(curFile, requireNotes);
    //先不考虑这个函数，存在bug，当一行存在多个匹配括号时，会出现无限循环
    //updateRequireNotes(-1, document()->lineCount(), nullptr);
    //qDebug() << "end:" << "updateMatch";
//    for(int i = 0; i < parenthesis.size(); ++i){
//        if(parenthesis.at(i)->isRoot){
//            qDebug() << "Root:" << "Start: " << parenthesis.at(i)->startLine << "End: " << parenthesis.at(i)->endLine;
//        }
//    }
    qDebug() << "-21";
}

void MdiChild::updateRequireNotes(int startLine, int endLine, RequireNote* node)
{
    //先不考虑这个函数，存在bug，当一行存在多个匹配括号时，会出现无限循环
    qDebug() << "-22";
    //从第一行开始找，存在匹配符，则得到上下行号的范围，在此范围内的一定是该节点的子节点
    for(int i = startLine + 1; i < endLine; ){
        QTextBlock currentBlock = document()->findBlockByLineNumber(i);
        TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
        if(data){
            QVector<MarkInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
            if(infos.empty()) {
                i++;
                continue;
            };
            MarkInfo *info = infos.at(0);
            if(info->matchLineNumber == -1 || info->character == ParenthesisEndStr){  //未匹配到或是结束括号则直接跳过
                //qDebug() << "this" ;
                i++;
                continue;
            }
            //endLine = info->matchLineNumber;
            QString content = "";  //content内容先空着

            RequireNote* newNode = new RequireNote(content, i, info->matchLineNumber, curFile);
            //if(newNode->startLine > node->startLine && newNode->endLine < node->endLine){
            if(node){
                node->children.append(newNode);
            }else{
                newNode->isRoot = true;  //根节点，顶级括号

            }
            requireNotes.append(newNode);
            updateRequireNotes(i, info->matchLineNumber, newNode);
            i = info->matchLineNumber;
            //}
        }else{
            i++;
        }
    }
    qDebug() << "-22";
}

void MdiChild::updateRequireNoteContent()
{
    for(int i = 0; i < requireNotes.size(); ++i){
        RequireNote* p = requireNotes[i];
        if(p->note.isEmpty()){
            int startPos = document()->findBlockByLineNumber(p->startLine).position();
            QTextBlock block = document()->findBlockByLineNumber(p->endLine);
            int endPos = block.position() + block.length();

            QTextCursor cursor(document());
            // 设置光标位置为起始位置
            cursor.setPosition(startPos);
            // 移动光标到结束位置并选择文本
            cursor.setPosition(endPos, QTextCursor::KeepAnchor);
            // 返回选择的文本
            QString text = cursor.selectedText().trimmed();
            if(text.startsWith(RequireNoteStartStr)){
                text.remove(0, RequireNoteStartStr.length());
            }
            if(text.endsWith(RequireNoteEndStr)){
                text.chop(RequireNoteEndStr.length());
            }
            p->note = text.trimmed();
        }
        qDebug() << "updateRequireNoteContent";
        qDebug() << "Line: " << p->startLine;
        qDebug() << "Content: " << p->note;
    }
}


bool MdiChild::matchLeftMark(QTextBlock currentBlock, int i, int numLeftMarks, int &matchLineNumber,
                                    int &matchPosition, QString startStr, QString endStr)
{
    qDebug() << "-23";
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<MarkInfo *> infos = data->getInfos(startStr);

    int docPos = currentBlock.position();
    for (; i < infos.size(); ++i) {
        MarkInfo *info = infos.at(i);

        if (info->character == startStr) {
            ++numLeftMarks;
            continue;
        }

        if (info->character == endStr && numLeftMarks == 0) {
            if(startStr == ParenthesisStartStr){
                createParenthesisSelection(docPos + info->position);
            }
            matchLineNumber = currentBlock.blockNumber();
            matchPosition = info->position;
            qDebug() << "-23";
            return true;
        } else
            --numLeftMarks;
    }

    currentBlock = currentBlock.next();
    if (currentBlock.isValid()){
        qDebug() << "-23";
        return matchLeftMark(currentBlock, 0, numLeftMarks, matchLineNumber,
                                    matchPosition, startStr, endStr);
    }
    qDebug() << "-23";
    return false;
}

bool MdiChild::matchRightMark(QTextBlock currentBlock, int i, int numRightMarks, int &matchLineNumber,
                                     int &matchPosition, QString startStr, QString endStr)
{
    qDebug() << "-24";
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<MarkInfo *> infos = data->getInfos(startStr);

    int docPos = currentBlock.position();
    for (; i > -1 && infos.size() > 0; --i) {
        MarkInfo *info = infos.at(i);
        if (info->character == endStr) {
            ++numRightMarks;
            continue;
        }
        if (info->character == startStr && numRightMarks == 0) {
            if(startStr == ParenthesisStartStr){
                createParenthesisSelection(docPos + info->position);
            }
            matchLineNumber = currentBlock.blockNumber();
            matchPosition = info->position;
            qDebug() << "-24";
            return true;
        } else
            --numRightMarks;
    }

    currentBlock = currentBlock.previous();

    if (currentBlock.isValid()){
        data = static_cast<TextBlockData *>(currentBlock.userData());
        infos = data->getInfos(startStr);
        qDebug() << "-24";
        return matchRightMark(currentBlock, infos.size() - 1, numRightMarks, matchLineNumber,
                                     matchPosition, startStr, endStr);
    }
    qDebug() << "-24";
    return false;
}

void MdiChild::createParenthesisSelection(int pos)
{
    qDebug() << "-25";
    QList<QTextEdit::ExtraSelection> selections = extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    format.setBackground(Qt::green);
    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, ParenthesisStartStr.size());
    selection.cursor = cursor;

    selections.append(selection);

    setExtraSelections(selections);
    qDebug() << "-25";
}

void MdiChild::changeRequirementToNote(int lineNumber)
{
    qDebug() << "-26";
    QTextBlock currentBlock = document()->findBlockByLineNumber(lineNumber);
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    int end;
    if(data){
        QVector<MarkInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
        if(infos.empty()) {
            qDebug() << "-26";
            return;
        };
        MarkInfo *info = infos.at(0);
        end = info->matchLineNumber;
    }

    for(auto req : requireNotes){
        //qDebug() << "Line:" << req->startLine;
        if(req->startLine >= lineNumber && req->endLine <= end){
            qDebug() << "Line:" << req->startLine;
            QTextBlock block = document()->findBlockByLineNumber(req->startLine);  //将>>>替换为//
            QTextCursor cursor(document());
            cursor.setPosition(block.position());
            QString text = block.text();
            int index = text.indexOf(ParenthesisStartStr);
            if(index != -1){
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, ParenthesisStartStr.length());
                cursor.insertText("//");
            }

            block = document()->findBlockByLineNumber(req->endLine);  //将<<<替换为
            cursor.setPosition(block.position());
            text = block.text();
            index = text.indexOf(ParenthesisEndStr);
            if(index != -1){
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, ParenthesisEndStr.length());
                cursor.insertText("");

            }
        }
    }
    qDebug() << "-26";

}

void MdiChild::completeToDoNote(int lineNumber)
{
    qDebug() << "-26";
    QTextBlock currentBlock = document()->findBlockByLineNumber(lineNumber);
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    if(data){
        QVector<MarkInfo *> infos = data->todoNotes();  //这里每行只可以有一个匹配符的情况
        if(infos.empty()) {
            qDebug() << "-26";
            return;
        };
        QString text = currentBlock.text();
        int index = text.indexOf(RequireNoteStartStr);
        if(index != -1){
            QTextCursor cursor(document());
            cursor.setPosition(currentBlock.position());
            cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
            cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, RequireNoteStartStr.length());
            cursor.insertText("/*");
        }
    }

    qDebug() << "-26";
}

void MdiChild::goToLine(int lineNumber)
{
    qDebug() << "-27";
    QTextCursor cursor(document());
    QTextBlock block = document()->findBlockByLineNumber(lineNumber);
    cursor.setPosition(block.position());
    QString text = block.text();
    int index = text.indexOf(ParenthesisStartStr);
    if(index != -1){
        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
    }
    setTextCursor(cursor);
    ensureCursorVisible(); // 确保光标可见
    qDebug() << "-27";
}

void MdiChild::updateTopParenthesis()  //更新顶层括号
{
    topParenthesis.clear();
    for(int i = 0; i < parenthesis.size(); ++i){
        if(parenthesis.at(i)->isRoot){
            topParenthesis.append(parenthesis.at(i));
        }
    }
}

void MdiChild::updateIssueInfoInSourceFile()
{
    qDebug() << "MdiChild::updateIssueInfoInSourceFile";
    qDebug() << "-71";

    qDebug() << "curFile: " << curFile;
    if(!curFile.endsWith(".cpp")) {
        qDebug() << "-71";
        return;   //如果不是.cpp文件，则直接跳过
    }

    unspecifiedTypeIssueList.clear();

    QTextCursor cursor(document());
    cursor.movePosition(QTextCursor::Start);

    int lineNumber = 0;
    QString fileName = userFriendlyCurrentFile();
    QString className = fileName.left(fileName.indexOf("."));
    QString filePath = currentFile();

    QString searchString = UNSPECIFIED;

    while (!cursor.isNull() && !cursor.atEnd()) {
        QTextBlock block = cursor.block();
        QString text = block.text();
        int position = text.indexOf(searchString);
        while (position != -1) {
            ClassMemberUnspecifiedIssue issue(className, filePath, lineNumber, position);
            unspecifiedTypeIssueList.append(issue);
            // Find the next occurrence in the same line
            position = text.indexOf(searchString, position + searchString.length());
        }

        cursor.movePosition(QTextCursor::NextBlock);
        lineNumber++;
    }

}

void MdiChild::updateObjectInfoInHeaderFile()
{
    qDebug() << "MdiChild::updateObjectInfoInHeaderFile";
    qDebug() << "-56";

    qDebug() << "curFile: " << curFile;
    QString className;
    if(!curFile.endsWith(".h")) {
        qDebug() << "-56";
        return;   //如果不是.h文件，则直接跳过
    }else{
        QString fileName = userFriendlyCurrentFile();
        className = fileName.left(fileName.indexOf("."));
    }

    //找到全局作用域
    updateTopParenthesis();
    syntaxIssueList.clear();

    QString text = document()->toPlainText(); // 获取文档中的所有文本

    QString classBodyStart = QString("\\bclass[^\\S\n]+%1[^\\{]*(\\{)").arg(className);
    QRegExp classBodyReg = QRegExp(classBodyStart);

    //寻找类声明函数体括号的开始和结束位置
    int pos = 0;
    int startPos = 0;
    int endPos = 0;
    if((pos = classBodyReg.indexIn(text, pos)) != -1){
        qDebug() << "MatchText: " << classBodyReg.cap(0);
        startPos = classBodyReg.pos(1);

        QTextBlock block = document()->findBlock(startPos);
        int posOffset = startPos - block.position();

        int matchLineNumber = -1;
        int matchPos = -1;
        if(block.isValid()){
            TextBlockData *data = static_cast<TextBlockData *>(block.userData());
            if (data) {
                QVector<MarkInfo *> infos = data->parentheses();
                //Returns the index of the block's first character within the document.
                for (int i = 0; i < infos.size(); ++i) {
                    MarkInfo *info = infos.at(i);
                    if(info->character == "{" && info->position == posOffset){
                        matchLineNumber = info->matchLineNumber;
                        matchPos = info->matchPosition;
                    }
                }
            }
        }
        if(matchLineNumber != -1){
            endPos = document()->findBlockByLineNumber(matchLineNumber).position() + matchPos;
        }

    }else{
        qDebug() << "Cannot find classBody in header file: " << className;
        return;
    }

    startPos = text.indexOf("private:", startPos);
    qDebug() << "startPos" << startPos;
    qDebug() << "endPos" << endPos;



    MainWindow* mw_ptr = getMainWindowPtr();
    if(mw_ptr == nullptr){
        qDebug() << "Parent MainWindow does not exist.";
        return;
    }


    qDebug() << "static_cast";

    qDebug() << "getProClassInfo.";
    ClassInfo info = mw_ptr->getProClassInfo(className);


    // 遍历正则表达式列表，并检测文本是否符合
    QRegExp reg;

    qDebug() << "check the new class info.";
    for(int i = 0; i < info.vars->size(); ++i){
        Variable& v = (*info.vars)[i];
        qDebug() << "Variable: " << v.name;
    }

    if(info.vars == nullptr || info.methods == nullptr){
        qDebug() << "nullptr error.";
    }

    for(int i = 0; i < info.vars->size(); ++i){
        Variable& v = (*info.vars)[i];
        if(v.type != UNSPECIFIED) continue;

        reg = QRegExp(classVarInHeaderStr.arg(v.name));
        int pos = startPos;
        if ((pos = reg.indexIn(text, pos)) != -1) {
            if(pos >= endPos) break;
            // 找到了匹配的内容
            qDebug()  << "classVarInHeader: " ;
            qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
            qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

            v.type = reg.cap(1) + reg.cap(2) + reg.cap(3);
        }
    }


    /*
    for(int i = 0; i < info.methods->size(); ++i){
        Method& m = (*info.methods)[i];
        if(m.returnType != UNSPECIFIED && !m.parameters.contains(UNSPECIFIED)) continue;

        reg = QRegExp(classMethodInHeaderStr.arg(m.name));
        int pos = startPos;
        if ((pos = reg.indexIn(text, pos)) != -1) {
            if(pos >= endPos) break;
            // 找到了匹配的内容
            qDebug()  << "classMethodInHeader: " ;
            qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
            qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

            QString returnType = reg.cap(1) + reg.cap(2);
            QString paramStr = reg.cap(3);
            QList<QString> parameters = onlyGetMethodParamType(paramStr);

            m.returnType = returnType;
            m.parameters = parameters;
            m.paramStr = paramStr;
        }
    }
    */

    //qDebug() << "20241107";
    mw_ptr->setProClassInfo(className, info);
    emit showHeaderFileIssue();
}

QString MdiChild::findMethodCodeByName(int currentBlockNumber)
{
    QString methodCode;
    int minD = document()->blockCount();
    int startLine = -1;
    int endLine = -1;
    for (Parenthesis* p : topParenthesis) {
        if (p && qAbs(currentBlockNumber - p->startLine) < minD) {
             minD = qAbs(currentBlockNumber - p->startLine);
             startLine = p->startLine;
             endLine = p->endLine;
        }
    }
    if(startLine != -1 && endLine != -1 && startLine <= endLine){
        QStringList lines;
        int totalLines = document()->blockCount();
        startLine = qBound(0, startLine, totalLines - 1);
        endLine = qBound(0, endLine, totalLines - 1);

        QTextBlock block = document()->findBlockByLineNumber(startLine);
        for (int i = startLine; i <= endLine && block.isValid(); ++i) {
            lines.append(block.text());
            block = block.next();
        }
        methodCode = lines.join("\n");
        if(methodCode.startsWith("{")){
            QString methodBody = document()->findBlockByLineNumber(currentBlockNumber).text();
            methodCode = methodBody + methodCode;
        }
        return methodCode;
    }else{
        return QString();
    }
}




void MdiChild::updateObjectInfoInSourceFile()
{
    qDebug() << "MdiChild::updateObjectInfoInSourceFile";
    qDebug() << "-28";

    qDebug() << "curFile: " << curFile;
    if(!curFile.endsWith(".cpp")) {
        qDebug() << "-28";
        return;   //如果不是.cpp文件，则直接跳过
    }

    //找到全局作用域
    updateTopParenthesis();
    syntaxIssueList.clear();
    classInfoHash->clear();
    QString fileName = userFriendlyCurrentFile();
    int dotIndex = fileName.lastIndexOf('.');
    if(dotIndex <= 0) {
        qDebug() << "Cannot resolve the file className";
        qDebug() << "fileName: " << fileName;
    }else{
        fileClassName = fileName.left(dotIndex);
    }
    if(fileClassName != "main") classInfoHash->insert(fileClassName, ClassInfo(fileClassName));

    QString text = document()->toPlainText(); // 获取文档中的所有文本

    QHash<QString, QString> methodNameToCode;

    // 遍历正则表达式列表，并检测文本是否符合
    foreach (const QRegExp &reg, syntaxRuleList) {
        if(reg == classPattern){
            int pos = 0;
            int i = 0;
            int start = 0;
            int end = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                qDebug()  << "classPattern: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                //1类名，2*&，3变量名，4;(
                ClassInfo info(reg.cap(1));
                if(!classInfoHash->contains(reg.cap(1))) classInfoHash->insert(reg.cap(1), info);
                classes.insert(reg.cap(3), reg.cap(1));

                //这里检测类的构造函数
                if(reg.cap(2) == "*"){   //如果是指针型类变量，如Student* stu =
                    // 1类名，2*，3变量名，4类名，5参数列表
                    QRegExp regCtr = classConstructPattern1;
                    regCtr.exactMatch(text.mid(pos));  //如果匹配到了，需要为当前类添加构造函数
                    QString matchedStr = text.mid(pos, regCtr.matchedLength());
                    if(regCtr.exactMatch(matchedStr)){
                        //这里要分析参数列表
                        //如果参数中返回的类型包含UNSPECIFIED，怎么处理
                        QString paramStr = completeMethodParamType(regCtr.cap(5), pos);
                        QStringList params = onlyGetMethodParamType(paramStr);
                        qDebug() << "params: " << params;
                        qDebug() << "paramStr: " << paramStr;
                        Method classCtr(regCtr.cap(1), regCtr.cap(1), regCtr.cap(1), params, paramStr, CLASS);
                        ClassInfo& i = (*classInfoHash)[reg.cap(1)];   //用引用修改值
                        if(!i.methods->contains(classCtr)){
                            qDebug() << "not contains";
                            qDebug() << "method size = " << i.methods->size();
                            i.methods->append(classCtr);
                            qDebug() << "method size = " << i.methods->size();
                            qDebug() << i.methods;
                        }

                    }
                }else{   //如果是普通类变量，如Student stu()
                    //1类名，2变量名，3参数列表
                    QRegExp regCtr = classConstructPattern2;
                    regCtr.exactMatch(text.mid(pos));  //如果匹配到了，需要为当前类添加构造函数
                    QString matchedStr = text.mid(pos, regCtr.matchedLength());
                    if(regCtr.exactMatch(matchedStr)){
                        //这里要分析参数列表
                        //如果参数中返回的类型包含UNSPECIFIED，怎么处理
                        QString paramStr = completeMethodParamType(regCtr.cap(3), pos);
                        QStringList params = onlyGetMethodParamType(paramStr);
                        qDebug() << "params: " << params;
                        qDebug() << "paramStr: " << paramStr;
                        Method classCtr(regCtr.cap(1), regCtr.cap(1), regCtr.cap(1), params, paramStr, CLASS);
                        ClassInfo& i = (*classInfoHash)[reg.cap(1)];    //用引用修改值
                        if(!i.methods->contains(classCtr)){
                            qDebug() << "not contains";
                            qDebug() << "method size = " << i.methods->size();
                            i.methods->append(classCtr);
                            qDebug() << "method size = " << i.methods->size();
                            qDebug() << i.methods;
                        }
                    }
                }

                //找到顶级括号的开始和结束位置
                if(i < topParenthesis.size()) {
                    start = findParenthesisStartPos(topParenthesis.at(i));
                    end = findParenthesisEndPos(topParenthesis.at(i));
                }

                if(pos <= start){
                    //全局的类变量
                    Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), GLOBAL);
                    if(!globalVars->contains(classVar)) globalVars->append(classVar);
                    pos += reg.matchedLength(); // 继续查找下一个匹配位置
                }else if(pos > start && pos < end){  //顶级括号内，一定不是全局变量
                    Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), LOCAL);
                    tmpVars.insert(classVar, pos);
                    pos += reg.matchedLength(); // 继续查找下一个匹配位置
                }else if(pos >= end){   //需要找到下一个顶级括号
                    if(i >= topParenthesis.size() - 1){   //顶级括号结束了的话，就是全局的类变量
                        Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), GLOBAL);
                        if(!globalVars->contains(classVar)) globalVars->append(classVar);
                        pos += reg.matchedLength(); // 继续查找下一个匹配位置
                    }else{
                        i++;
                    }
                }
            }
        }

        else if(reg == classVarAssignPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                //1类的实例名，2.->，3成员变量名，4[]，5赋值表达式
                qDebug()  << "classAssignVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString expression = reg.cap(5).trimmed();
                    QString varType = getExpressionType(expression, reg.pos(5));
                    if(!basicType.contains(varType)&& varType != UNSPECIFIED) classes.insert(reg.cap(3), varType);
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength(); // 继续查找下一个匹配位置
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }
                    Variable var(reg.cap(3), className, varType, CLASS);  //type未指定, className = 实例的类变量名
                    tmpVars.insert(var, pos);
                    if(!classInfoHash->contains(className)){
                        classInfoHash->insert(className, ClassInfo(className));
                    }
                    ClassInfo info = classInfoHash->value(className);
                    //怎么保证不重复插入
                    bool flag = false;  //用于标记是否存在同名的类变量
                    for(int i = 0; i < info.vars->size(); ++i){
                        if(info.vars->at(i).name == reg.cap(3)){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) info.vars->append(var);
                }else{
                    qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                    QString filePath = curFile;
                    int lineNumber = document()->findBlock(pos).blockNumber();
                    ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                    if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                }
                pos += reg.matchedLength(); // 继续查找下一个匹配位置
            }

            qDebug() << "classVarPattern ends.";
        }

        else if(reg == classVarPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                //1类的实例名，2.->，3成员变量名
                qDebug()  << "classVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                if(reg.cap(3) == "h" || reg.cap(3) == "cpp") {
                    pos += reg.matchedLength();
                    continue;
                }
                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = getExpressionType(reg.cap(1), reg.pos(1));
                    }
                    if(className == UNSPECIFIED){
                        pos += reg.matchedLength();
                        continue;
                    }
                    QString varType = getMainWindowPtr()->findClassMemberType(className, reg.cap(3));
                    if(!basicType.contains(varType) && varType != UNSPECIFIED) classes.insert(reg.cap(3), varType);
                    Variable var(reg.cap(3), className, varType, CLASS);  //type未指定, className = 实例的类变量名
                    tmpVars.insert(var, pos);
                    if(!classInfoHash->contains(className)){
                        classInfoHash->insert(className, ClassInfo(className));
                    }

                    ClassInfo info = classInfoHash->value(className);
                    //怎么保证不重复插入
                    bool flag = false;  //用于标记是否存在同名的类变量
                    for(int i = 0; i < info.vars->size(); ++i){
                        if(info.vars->at(i).name == reg.cap(3)){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) info.vars->append(var);
                }else{
                    qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                    QString filePath = curFile;
                    int lineNumber = document()->findBlock(pos).blockNumber();
                    ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                    if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                }
                pos += reg.matchedLength(); // 继续查找下一个匹配位置
            }

            qDebug() << "classVarPattern ends.";
        }

        //先不扫描函数，只呈现已定义好的函数
        else if(reg == classMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                //1类的变量名，2.->，3成员函数名，4参数列表
                qDebug()  << "classMethod: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }

                    QString methodName = reg.cap(3);
                    QString actual_params = reg.cap(4);

                    QString paramStr = completeMethodParamType(actual_params, pos);
                    qDebug() << "classMethod:paramStr: " << paramStr;
                    QStringList params = onlyGetMethodParamType(paramStr);
                    qDebug() << "classMethod:params: " << params;
                    QString returnType = findMethodReturnType(methodName, className, params, CLASS);
                    Method classMethod(methodName, className, returnType, params, paramStr, CLASS);


                    //按理说，如果这里扫描到的函数没有在源文件中定义，应该补充相应定义
                    //可能有两种情况
                    //1. 类外调用
                    //2. 类内调用
                    ClassInfo& i = (*classInfoHash)[className];    //用引用修改值
                    if(!i.methods->contains(classMethod)){
                        qDebug() << "not contains";
                        qDebug() << "method size = " << i.methods->size();
                        i.methods->append(classMethod);
                        qDebug() << "method size = " << i.methods->size();
                        qDebug() << i.methods;
                    }
                    }else{
                        qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                        QString filePath = curFile;
                        int lineNumber = document()->findBlock(pos).blockNumber();
                        ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                        qDebug() << "curIssue: " << curIssue.getName() << " " << curIssue.getDescription() << " " << curIssue.getFilePath();
                        if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                    }
                pos += reg.matchedLength(); // 继续查找下一个匹配位置
            }
        }

        //先不扫描函数，只呈现已定义好的函数
        else if(reg == classMethodEmbededCallPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                //1类的变量名，2.->，3成员函数名，4参数列表
                qDebug()  << "classMethodEmbededCall: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }

                    QString methodName = reg.cap(3);
                    QString actual_params = reg.cap(4);
                    if (actual_params.endsWith(')')) {
                        actual_params.chop(1);  // Removes the last character (closing parenthesis)
                    }

                    QString paramStr = completeMethodParamType(actual_params, pos);
                    qDebug() << "classMethod:paramStr: " << paramStr;
                    QStringList params = onlyGetMethodParamType(paramStr);
                    qDebug() << "classMethod:params: " << params;
                    QString returnType = findMethodReturnType(methodName, className, params, CLASS);
                    Method classMethod(methodName, className, returnType, params, paramStr, CLASS);


                    //按理说，如果这里扫描到的函数没有在源文件中定义，应该补充相应定义
                    //可能有两种情况
                    //1. 类外调用
                    //2. 类内调用
                    ClassInfo& i = (*classInfoHash)[className];    //用引用修改值
                    if(!i.methods->contains(classMethod)){
                        qDebug() << "not contains";
                        qDebug() << "method size = " << i.methods->size();
                        i.methods->append(classMethod);
                        qDebug() << "method size = " << i.methods->size();
                        qDebug() << i.methods;
                    }
                    }else{
                        qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                        QString filePath = curFile;
                        int lineNumber = document()->findBlock(pos).blockNumber();
                        ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                        qDebug() << "curIssue: " << curIssue.getName() << " " << curIssue.getDescription() << " " << curIssue.getFilePath();
                        if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                    }
                pos += reg.matchedLength(); // 继续查找下一个匹配位置
            }
        }

        else if(reg == basicVarPattern){
            int i = 0;
            int start;
            int end;

            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                qDebug()  << "basicVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                //找到顶级括号的开始和结束位置
                if(i < topParenthesis.size()) {
                    start = findParenthesisStartPos(topParenthesis.at(i));
                    end = findParenthesisEndPos(topParenthesis.at(i));
                }

                //1类型，2*&，3变量名，4[]
                if(pos <= start){
                    //全局变量
                    Variable global = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), GLOBAL);
                    if(!globalVars->contains(global)) globalVars->append(global);
                    pos += reg.matchedLength(); // 继续查找下一个匹配位置
                }else if(pos > start && pos < end){  //顶级括号内，一定不是全局变量
                    Variable tmp = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), LOCAL);
                    tmpVars.insert(tmp, pos);
                    pos += reg.matchedLength(); // 继续查找下一个匹配位置
                }else if(pos >= end){
                    if(i >= topParenthesis.size() - 1){
                        Variable global = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), GLOBAL);
                        if(!globalVars->contains(global)) globalVars->append(global);
                        pos += reg.matchedLength(); // 继续查找下一个匹配位置
                    }else{
                        i++;
                    }
                }
            }
        }

        else if(reg == definedMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                qDebug()  << "definedMethods: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
                //qDebug() << "ConstMethod: " << reg.cap(1) << " " << reg.cap(2) << " " << reg.cap(3) << " " << reg.cap(4) << " " << reg.cap(5);
                int currentBlockNumber = document()->findBlock(pos).blockNumber();
                qDebug() << "current block: " << currentBlockNumber;
                QString methodCode = findMethodCodeByName(currentBlockNumber);
                if(!methodCode.isEmpty()){
                    QString methodName = reg.cap(0);
                    if (methodName.endsWith("{")) {
                        methodName.chop(1);
                        methodName = methodName.trimmed(); // Remove last character '{'
                    }
                    methodNameToCode.insert(methodName, methodCode);
                    qDebug() << "MethodNameAndCode";
                    qDebug() << "MethodName: " << methodName;
                    qDebug() << "MethodCode: " << methodCode;
                }

                //1返回类型，2*&，3类名，4函数名，5参数列表
                SCOPE scope = (reg.cap(3).isEmpty() ? GLOBAL : CLASS);  //判断类作用域是否为空，比如Class::
                //这里要把类名中的::去掉
                QString className = (reg.cap(3).isEmpty() ?  "" : reg.cap(3).left(reg.cap(3).length() - 2) );
                QStringList params = onlyGetMethodParamType(reg.cap(5));
                Method m(reg.cap(4), className, reg.cap(1) + reg.cap(2), params, reg.cap(5), scope);
                convertMethodParamToTemp(reg.cap(5), pos + reg.matchedLength());
                if(!definedMethods->contains(m)) definedMethods->append(m);
                pos += reg.matchedLength(); // 继续查找下一个匹配位置
            }
        }

        else if(reg == classCtrMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // 找到了匹配的内容
                //1类名，2类名，3参数列表，4形参，5类成员变量
                qDebug()  << "classCtrMethods: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                QStringList capturedTexts = reg.capturedTexts();
                qDebug() << "Captured texts:";
                for (const QString &text : capturedTexts) {
                    qDebug() << text;
                }

                QString paramStr = reg.cap(3);
                QStringList params = onlyGetMethodParamType(paramStr);
                qDebug() << "params: " << params;
                qDebug() << "paramStr: " << paramStr;
                Method classCtr(reg.cap(1), reg.cap(1), reg.cap(1), params, paramStr, CLASS);
                ClassInfo c(reg.cap(1));
                if(!classInfoHash->contains(reg.cap(1))) classInfoHash->insert(reg.cap(1), c);
                ClassInfo& i = (*classInfoHash)[reg.cap(1)];
                if(!i.methods->contains(classCtr)){
                    qDebug() << "not contains";
                    qDebug() << "method size = " << i.methods->size();
                    i.methods->append(classCtr);
                    qDebug() << "method size = " << i.methods->size();
                    qDebug() << i.methods;
                }

                int index = 0;   //扫描构造函数的形参和类成员变量
                QRegExp reg_param = QRegExp("([A-Za-z_][A-Za-z0-9_]*)\\(([A-Za-z_][A-Za-z0-9_]*)\\)");
                QString classVarType, classVar;
                while ((index = reg_param.indexIn(reg.cap(0), index)) != -1){
                    QString param = reg_param.cap(2);
                    classVar = reg_param.cap(1);
                    classVarType = getExpressionType(classVar);
                    if(classVarType == "var"){
                        //找到参数列表中对应的类型
                        QStringList paramList = paramStr.split(",", QString::SkipEmptyParts);
                        for(QString parameter : paramList){
                            parameter = parameter.trimmed();
                            int p = parameter.indexOf(classVar);
                            if(p != -1){
                                classVarType = parameter.remove(p, classVar.length()).trimmed();
                            }
                        }
                    }else if(classVarType == "classVar" || classVarType == "classMethod" || classVarType == "method"){
                        classVarType = getExpressionType(classVar, reg_param.pos(1));
                    }else{
                        //do nothing
                    }
                    if(classVarType.isEmpty()) classVarType = UNSPECIFIED;
                    Variable var(classVar, reg.cap(1), classVarType, CLASS);  //className = 实例的类变量名
                    ClassInfo info = classInfoHash->value(reg.cap(1));
                    //怎么保证不重复插入
                    if(!info.vars->contains(var)) info.vars->append(var);
                    index += reg_param.matchedLength();
                }

                pos += reg.matchedLength();

            }
        }
    }

    qDebug() << "methodNameToCode:";
    for (auto it = methodNameToCode.constBegin(); it != methodNameToCode.constEnd(); ++it) {
        qDebug() << "Key:" << it.key() << ", Value:" << it.value();
    }

    if(!methodNameToCode.isEmpty()){
        emit updateMethodNameToCode(methodNameToCode);
    }else{
        qDebug() << "Failed to set cscrToolMethodNameToCode.";
    }

    qDebug() << "arrange defined methods.";
    //把已定义好的函数归到相应的类下
    for(int i = 0; i < definedMethods->size(); i++){
        if(definedMethods->at(i).scope == CLASS && !definedMethods->at(i).className.isEmpty()){  //全局函数跳过
            QString className = definedMethods->at(i).className;

            if(classInfoHash->contains(className)){
                ClassInfo info = classInfoHash->value(className);
                if(!info.methods->contains(definedMethods->at(i))) info.methods->append(definedMethods->at(i));
            }else{
                ClassInfo info(className);
                info.methods->append(definedMethods->at(i));
                classInfoHash->insert(className, info);
            }
        }
    }

    qDebug() << "TempVars:";

    // 将 QMultiHash 转换为 QMap，只是为了打印看着方便
    QMap<int, Variable> map;
    QList<Variable> keys = tmpVars.uniqueKeys();
    foreach (const Variable &key, keys) {
        QList<int> values = tmpVars.values(key);
        foreach (int value, values) {
            map.insertMulti(value, key);
        }
    }

    // 对 QMap 进行排序
    QMap<int, Variable>::iterator iter;
    QMap<int, Variable> sortedMap;
    for (iter = map.begin(); iter != map.end(); ++iter) {
        sortedMap.insert(iter.key(), iter.value());
    }

    // 打印排序后的结果
    QMap<int, Variable>::const_iterator it;
    for (it = sortedMap.constBegin(); it != sortedMap.constEnd(); ++it) {
        qDebug() << "type:" << it.value().type << " name:" << it.value().name << " pos:" << it.key();
    }

//    QMultiHash<Variable, int>::const_iterator it;
//    for (it = tmpVars.constBegin(); it != tmpVars.constEnd(); ++it) {
//        qDebug() << "type:" << it.key().type << " name:" << it.key().name << " pos:" << it.value();
//    }

    qDebug() << "Classes:";
    for (auto i = classInfoHash->constBegin(); i != classInfoHash->constEnd(); ++i) {
        qDebug() << "**************************************";
        qDebug() << i.key() << ":";
        qDebug() << "Variables:";
        ClassInfo info = i.value();
        if(info.name == "") info.name = i.key();
        for(int j = 0; j < info.vars->size(); j++){
            qDebug() << info.vars->at(j).type << " " <<
                        info.vars->at(j).className << "::" <<info.vars->at(j).name;
        }

        qDebug() << "Methods:";
        for(int j = 0; j < info.methods->size(); j++){
            qDebug() << info.methods->at(j).returnType << " "
                     << info.methods->at(j).className << "::" <<info.methods->at(j).name
                     << "(" << info.methods->at(j).paramStr << ")";
        }
    }

    qDebug() << "GlobalVar:";
    for(int i = 0; i < globalVars->size(); ++i){
        qDebug() << "type: " << globalVars->at(i).type << "name: " << globalVars->at(i).name;
    }

    qDebug() << "DefinedMethod:";
    for(int i = 0; i < definedMethods->size(); ++i){
        qDebug() << definedMethods->at(i).returnType << " " << definedMethods->at(i).className << " "
                 << definedMethods->at(i).name << "(" << definedMethods->at(i).paramStr << ")";
    }


    qDebug() << "-28";


    //通知主窗口更新类文件
    emit updateClassFiles(currentFile(), *classInfoHash);
    emit showSourceFileIssue(syntaxIssueList);
}

void MdiChild::updateInformalSpecPosInFile()
{
    qDebug() << "MdiChild::updateInformalSpecPosInFile";
    qDebug() << "-88";

    QString text = document()->toPlainText(); // 获取文档中的所有文本

    int pos = 0;
    QList<InformalSpecInfo> informalSpecInfos;
//    while ((pos = informalSpecPattern.indexIn(text, pos)) != -1) {
//        // 找到了匹配的内容
//        qDebug()  << "informalSpec: " ;
//        qDebug() << "Matched text:" << informalSpecPattern.cap(0) << "at position:" << pos;  //type需要选择是否加上&或*，cap(2)
//        int curLineNumber = document()->findBlock(pos).blockNumber();
//        qDebug() << "current block: " << curLineNumber;
//        qDebug() << "section Number: " << informalSpecPattern.cap(1);

//        //1章节号，2自然语言描述
//        informalSpecInfos.append(InformalSpecInfo(informalSpecPattern.cap(1), curLineNumber));
//        pos += informalSpecPattern.matchedLength();

//    }

    QRegularExpressionMatchIterator i = informalSpecPattern.globalMatch(text);

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        qDebug() << "Match found:" << match.captured(0) << "at position:" << match.capturedStart(0);
        int curLineNumber = document()->findBlock(pos).blockNumber();
        qDebug() << "current block: " << curLineNumber;
        qDebug() << "section Number: " << match.captured(1);

        //1章节号，2自然语言描述
        informalSpecInfos.append(InformalSpecInfo(match.captured(1), curLineNumber));
    }

    emit updateInformalSpecPos(currentFile(), informalSpecInfos);
}

void MdiChild::convertMethodParamToTemp(const QString& str, const int& pos)
{
    if(str.isEmpty()) {
        return;
    }
    // 以逗号分割字符串
    QStringList paramList = str.split(",", QString::SkipEmptyParts);
    // 去除每个子字符串的前后空格并分离变量类型
    for (int i = 0; i < paramList.size(); ++i) {
        paramList[i] = paramList[i].trimmed();
        //1变量类型，2*&，3变量名
        QString className;
        if(varPattern.exactMatch(paramList[i])){
            if(classes.contains(varPattern.cap(3))){
                className = classes.value(varPattern.cap(3));
            }else{
                className = "";
            }
            Variable var(varPattern.cap(3), className, varPattern.cap(1) + varPattern.cap(2), GLOBAL);
            if(globalVars->contains(var)){
                globalVars->removeAll(var);
                var.scope = LOCAL;
                tmpVars.insert(var, pos);
            }
        }
    }
}

QList<QString> MdiChild::onlyGetMethodParamType(const QString& str)
{
    qDebug() << "onlyGetMethodParamType: str = " << str;
    // 以逗号分割字符串
    if(str.isEmpty()) {
        return QList<QString>();
    }
    QStringList paramList = str.split(",", QString::SkipEmptyParts);

    QList<QString> res;
    // 去除每个子字符串的前后空格
    for (int i = 0; i < paramList.size(); ++i) {
        //1变量类型，2*&，3变量名
        paramList[i] = paramList[i].trimmed();
        QString type = paramList[i].split(' ').first();
        res.append(type);
    }
    qDebug() << res;
    return res;
}

QString MdiChild::completeMethodParamType(const QString& str, const int& pos)
{
    qDebug() << "stringToParameter: str = " << str;
    // 以逗号分割字符串
    if(str.isEmpty()) {
        return "";
    }
    QStringList paramList = str.split(",", QString::SkipEmptyParts);

    // 去除每个子字符串的前后空格
    for (int i = 0; i < paramList.size(); ++i) {
        paramList[i] = paramList[i].trimmed();
    }

    //这里比较复杂，又涉及到常量，变量，函数调用返回值的问题

    QString result = "";

    for(int i = 0; i < paramList.size(); ++i){
        QString param = paramList.at(i);
        if(i != 0){
            result += ", ";
        }
        QString expType = getExpressionType(param, pos);
        QString varWithType;

        if(expType == ""){
            varWithType = "void " + param;
        }else if(expType == UNSPECIFIED){
            varWithType = UNSPECIFIED + " " + param;
        }else{
            varWithType = expType + " " + param;
        }
        result += varWithType;
    }
    return result;
}

QString MdiChild::getExpressionType(const QString& exp, const int& pos)
{
    qDebug() << "getExpressionTypewithPos: str = " << exp;

    QRegExp varPattern("^(\\*|&?)([A-Za-z_][A-Za-z0-9_]*)$"); // 变量的正则表达式
    QRegExp funcPattern("([A-Za-z_][A-Za-z0-9_]+)\\b\\((.*)\\)");   //函数调用或者类的正则表达式

    //这里比较复杂，又涉及到常量，变量，函数调用返回值的问题

    QString expType = getExpressionType(exp);
    if (expType == "char*" || expType == "char" || expType == "int"
            || expType == "double" || expType == "bool") {
        //do nothing
    }else if (expType == "var") {
        if(varPattern.exactMatch(exp)){
            //1*&，2变量名
            QString varName = varPattern.cap(2);
            QString varType = findVarType(varName, "", pos);
            qDebug() << "type = " << varType;
            if(varPattern.cap(1) == "*"){
                if(varType.endsWith("*")){
                    expType = varType;
                }
            }else if(varPattern.cap(1) == "&"){
                expType = varType + "*";
            }else if(varPattern.cap(1) == ""){
                expType = varType;
            }
        }
    } else if (expType == "method") {
        if(funcPattern.exactMatch(exp)) {
            //1函数名，2参数列表
            QString actual_params = funcPattern.cap(2);
            QString paramStr = completeMethodParamType(actual_params, pos);
            QStringList params = onlyGetMethodParamType(paramStr);
            QString returnType = findMethodReturnType(funcPattern.cap(1), "", params, GLOBAL);
            expType = returnType;
        }
    } else if (expType == "classVar") {
        if(classVarAssignPattern.exactMatch(exp)){   //student->name, student.name
            //1类的变量名，2.->，3成员变量名，4[]，
            QString classVar = classVarAssignPattern.cap(1);
            QString varName = classVarAssignPattern.cap(3);
            QString classType;
            if(classVar == "this"){
                classType = fileClassName != "main" && fileClassName != "" ? fileClassName : UNSPECIFIED;
            }else{
                classType = findVarType(classVar, "", pos);  //找到类名
            }
            QString varType = findVarType(varName, classType, pos);
            expType = varType;
        }
    } else if (expType == "classMethod") {
        if(classMethodPattern.exactMatch(exp)){   //student->getName(), student.getName()
            //1类的变量名，2.->，3成员函数名，4参数列表
            QString classVar = classMethodPattern.cap(1);
            QString methodName = classMethodPattern.cap(3);
            QString classType;
            if(classVar == "this"){
                classType = fileClassName != "main" && fileClassName != "" ? fileClassName : UNSPECIFIED;
            }else{
                classType = findVarType(classVar, "", pos);  //找到类名
            }
            QString actual_params = classMethodPattern.cap(4);
            QString paramStr = completeMethodParamType(actual_params, pos);
            QStringList params = onlyGetMethodParamType(paramStr);
            QString returnType = findMethodReturnType(methodName, classType, params, CLASS);
            expType = returnType;
        }
    }else if (expType.isEmpty()){
        expType = "";
    } else {
        expType = UNSPECIFIED;
    }

    return expType;
}

QString MdiChild::getExpressionType(const QString& exp)
{
    qDebug() << "getExpressionType: str = " << exp;

    QRegExp stringPattern("^\".*\"$"); // 字符串的正则表达式
    QRegExp varPattern("^(\\*|&?)([A-Za-z_][A-Za-z0-9_]*)$"); // 变量的正则表达式
    QRegExp charPattern("^\'.\'$"); // 单个字符的正则表达式
    QRegExp integerPattern("^-?\\d+$"); // 整数的正则表达式
    QRegExp decimalPattern("^-?\\d+\\.(\\d+)?$"); // 小数的正则表达式
    QStringList boolPattern = {"true", "false", "FALSE", "TRUE"};
    QRegExp funcPattern("([A-Za-z_][A-Za-z0-9_]+)\\b\\((.*)\\)");   //函数调用或者类的正则表达式


    //这里比较复杂，涉及到常量，变量，函数调用返回值的问题

    QString expType = "";
    QString param = exp;
    param = param.trimmed();
    if (stringPattern.exactMatch(param)) {
        expType = "char*";
        qDebug() << param << "是一个字符串";
    }else if (charPattern.exactMatch(param)) {
        expType = "char";
        qDebug() << param << "是一个字符";
    } else if (integerPattern.exactMatch(param)) {
        expType = "int";
        qDebug() << param << "是一个整数";
    } else if (decimalPattern.exactMatch(param)) {
        expType = "double";
        qDebug() << param << "是一个小数";
    } else if (boolPattern.contains(param)) {
        expType  = "bool";
        qDebug() << param << "是布尔值";
    } else if (varPattern.exactMatch(param)){
        //1*&，2变量名
        expType = "var";
        qDebug() << param << "是一堆字母";
    } else if (funcPattern.exactMatch(param)) {
        //1函数名，2参数列表
        expType = "method";
        qDebug() << param << "是函数调用";
    } else if (classVarAssignPattern.exactMatch(param)){   //student->name, student.name
        //1类的变量名，2.->，3成员变量名，4[]，
        expType = "classVar";
        qDebug() << param << "类成员变量调用";
    } else if (classMethodPattern.exactMatch(param)){   //student->getName(), student.getName()
        //1类的变量名，2.->，3成员函数名，4参数列表
        expType = "classMethod";
        qDebug() << param << "类成员函数调用";
    } else if (param.isEmpty()){
        expType = "";
        qDebug() << param << "为空";
    } else {
        expType = UNSPECIFIED;
        qDebug() << param << "不符合任何模式";
    }
    return expType;
}

QString MdiChild::findMethodReturnType(const QString& methodName, const QString& className,
                                       const QStringList& parameters, SCOPE scope)
{
    QString type = "";
    for(int i = 0; i < definedMethods->size(); ++i){
        Method m = definedMethods->at(i);
        if(m.scope == scope && m.name == methodName && m.className == className
                && m.parameters == parameters){  //这里已经考虑了同名函数，参数不同的情况
            type = m.returnType;
        }
    }
    if(type.isEmpty()) type = "void";
    return type;
}

QString MdiChild::findVarType(const QString& varName, const QString& className, const int& pos)
{
    QString res = "";
    qDebug() << "MdiChild::findVarType";
    if(className.isEmpty()){
        //如果className为空，表明是一个普通变量要在上下文中找到其定义时的类型
        QMultiHash<Variable, int>::const_iterator it;
        for (it = tmpVars.constBegin(); it != tmpVars.constEnd(); ++it) {
            qDebug() << "type:" << it.key().type << " name:" << it.key().name << " pos:" << it.value();
            qDebug() << "target pos" << pos;
            if(it.value() >= pos){   //如果定义位置大于要确定的变量的位置，直接跳过
                continue;
            }else{
                if(it.key().name == varName){
                    if(isInSameScope(it.value(), pos)){
                        qDebug() << "inSameScope";
                        res = it.key().type;
                    }
                }
            }
        }

        if(res.isEmpty()){
            for(int i = 0; i < globalVars->size(); i++){
                Variable var = globalVars->at(i);
                if(var.name == varName){
                    res = var.type;
                }
            }
        }
    }else{  //如果ClassName不为空，表明是从类信息中找到其定义的类型
        if(classInfoHash->contains(className)){
            ClassInfo info = classInfoHash->value(className);
            for(int i = 0; i < info.vars->size(); i++){  //在类包含的成员变量下寻找同名变量
                Variable var = info.vars->at(i);
                if(var.name == varName){
                    res = var.type;
                }
            }
        }
    }
    if(res.isEmpty()) res = UNSPECIFIED;  //无论如何，一个变量的类型不能为空
    qDebug() << "res: " << res;
    return res;
}

bool MdiChild::isInSameScope(const int& defPos, const int& accessPos)
{
    if(defPos >= accessPos) return false;  //定义位置大于访问位置，直接返回
    Parenthesis* includePtr = 0;
    int range = document()->characterCount();
    int resStart = 0, resEnd = 0;
    for(const auto ptr : parenthesis){
        int startPos = document()->findBlockByLineNumber(ptr->startLine).position() + ptr->startLine;
        int endPos = document()->findBlockByLineNumber(ptr->endLine).position() + ptr->endLine;
        if(defPos >= startPos && defPos <= endPos && (endPos - startPos) < range){  //找到包含defpos的最小括号
            includePtr = ptr;
            range = (endPos - startPos);
            resStart = startPos;
            resEnd = endPos;
        }
    }
    if(includePtr != nullptr){  //局部变量
        if(resStart <= accessPos && accessPos <= resEnd){
            return true;   //定义位置的括号包含访问位置，返回true
        }else{
            return false;
        }
    }else{  //全局变量
        return true;
    }
}

void MdiChild::autoCompleteMatch()
{
    qDebug() << "-30";
    //qDebug()  <<  "start: " << "autoCompleteMatch";
    // 获取当前光标位置
    QTextCursor cursor = textCursor();
    QTextBlock currentBlock = cursor.block();
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    if(data){
        QVector<MarkInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
        if(!infos.empty()) {
            MarkInfo *info = infos.at(0);
            if(info->matchLineNumber != -1) return;  //如果当前行括号有匹配，直接返回
        }
    }
    // 获取当前光标所在行的文本
    QString currentLineText = cursor.block().text();

    // 判断当前行是否为空行并且以">>>"结尾
    if (currentLineText.endsWith(ParenthesisStartStr)) {
        //调整光标到本行末尾
        cursor.setPosition(currentBlock.position() + currentBlock.length());
        setTextCursor(cursor);
        // 插入一个新行
        cursor.insertBlock();
        // 在新行中插入"<<<"
        cursor.insertText(ParenthesisEndStr);
    }
    //qDebug()  <<  "end: " << "autoCompleteMatch";
    qDebug() << "-30";
}

void MdiChild::matchFaultPattern(const QRegExp& faultPattern, const QTextCharFormat& format, QString faultName)
{
    QString text = document()->toPlainText(); // 获取文档中的所有文本
    int pos = 0;
    //这里只找第一个fault出现的地方
    if ((pos = faultPattern.indexIn(text, pos)) != -1) {
        // 找到了匹配的内容
        //1类名，2.->，3成员变量名，4[]，5赋值表达式
        qDebug()  << "Find the fault: " << faultPattern.cap(0) << faultPattern.cap(1) << faultPattern.cap(2);
        qDebug() << "Matched text:" << faultPattern.cap(0) << "at position:" << pos;
        highlighter->addHighlightingRule(faultPattern, format);
        highlighter->rehighlight();
        QTextBlock block = document()->findBlock(pos);
        int blockNumber = block.blockNumber();
        faultLinePaint(blockNumber);
        setFixText(faultPattern.cap(1), faultPattern.cap(2));
    }

}

void MdiChild::highlightSegments(const QList<int> &segments) {
    QList<QTextEdit::ExtraSelection> selections;

    if (segments.isEmpty() || (segments.size() == 1 && segments.at(0) == -1)){
        resetBlockColors(0, document()->blockCount(), Qt::transparent, selections);
        setExtraSelections(selections);
        return;
    }

    // Save the current cursor position
    QTextCursor originalCursor = textCursor();

    QColor colors[] = {Qt::yellow, Qt::cyan};  // Two alternating colors

    int prev = 0;
    for (int i = 0; i < segments.size(); ++i) {
        QTextBlock startBlock = document()->findBlockByNumber(prev);
        QTextBlock endBlock = (segments[i] == -1) ? document()->lastBlock() : document()->findBlockByNumber(segments[i]);

        if (!startBlock.isValid() || !endBlock.isValid()) {
            qDebug() << "block is invalid.";
            break; // Invalid block
        }
        resetBlockColors(prev, segments[i]+1, colors[i % 2], selections);

        prev = segments[i] + 1;
    }

    setExtraSelections(selections);

    // Restore the original cursor position
    setTextCursor(originalCursor);
}


