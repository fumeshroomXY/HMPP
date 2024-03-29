#include <QtWidgets>
#include <QPlainTextEdit>

#include "mdichild.h"
#include "faultpromptdialog.h"
#include "highlighter.h"

MdiChild::MdiChild(QWidget *parent): QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);   //子窗口关闭时销毁这个对象
    isUntitled = true;

    lineNumberArea = new LineNumberArea(this);
    foldingWidget = new FoldingWidget(this);
    faultPrompt = new FaultPromptDialog(this);
    button = new CustomButton(this);
    button->setVisible(false);

    connect(document(), SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(faultLinePaint()));
    //connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));

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
//    connect(faultPrompt, &FaultPromptDialog::releasedSignal, this, &MdiChild::clearPreview);
//    connect(faultPrompt, &FaultPromptDialog::leftSignal, this, &MdiChild::clearPreview);

    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightMatch()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(autoCompleteMatch()));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateMatch()));
}

void MdiChild::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;    //新建的文档没有被保存过
    //新建文件，curFile存的不是文件的完整路径，所以不推荐直接新建文件，最好是先新建项目
    curFile = tr("document%1.txt").arg(sequenceNumber++);  //当前文件命名
    setWindowTitle(curFile + "[*]");

    connect(document(), &QTextDocument::contentsChanged,
            this, &MdiChild::documentWasModified);
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) { //只读方式打开文件，出错则提示
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
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

    return true;
}

bool MdiChild::save()
{

    //当关闭为保存文件时，程序会崩溃
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();   //以纯文本文件写入
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()  //提取文件名，从文件路径中提取文件名
{
    return strippedName(curFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {    //如果文档未被更改过，或更改了但取消关闭，或放弃保存
        event->ignore();
    }
}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());  //QTextDocument类的isModified函数
    //使用QTextEdit类的document函数获取它的QTextDocument类
}

bool MdiChild::maybeSave()   //是否需要保存
{
    if (!document()->isModified())  //如果文档未被更改过
        return true;
    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Save warning"),
                                   tr("'%1' has been modified.\n"
                                      "Do you want to save your changes?")
                                   .arg(userFriendlyCurrentFile()),
                                   QMessageBox::Save | QMessageBox::Discard
                                   | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();    //可以去除路径中的符号链接，"."和".."等符号
    isUntitled = false;   //文件已经被保存过了
    document()->setModified(false);   //文档没有被更改过
    setWindowModified(false);   //窗口不显示被更改标志
    setWindowTitle(userFriendlyCurrentFile() + "[*]");  //设置窗口标题，userFriendlyCurrentFile返回文件名
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

int MdiChild::lineNumberAreaWidth()
{
    int digits = 1;   //行号的位数
    int max = qMax(1, document()->blockCount());  //当前文档的行数
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    int lineHeight = foldingWidgetWidth();
    int space = lineHeight + fontMetrics().width(QLatin1Char('9')) * digits;   //可以指定其他width

    return space;
}

int MdiChild::foldingWidgetWidth()
{
    QTextBlock block = document()->firstBlock();
    return (int)document()->documentLayout()->blockBoundingRect(block).height();
}

void MdiChild::foldingWidgetHighlight(QPoint pos)
{
    //复制mousePressEvent的内容，获取开始和结束行号
    QRect rect =  contentsRect();

    //下面的y和height要调整，y取较大值，height取小值
    foldingWidget->update(lineNumberArea->width() + 1, rect.y(), foldingWidget->width() - 2, rect.height());
}

void MdiChild::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    //qDebug()  <<  "start: " << "updateLineNumberAreaWidth";

    setViewportMargins(lineNumberAreaWidth() + foldingWidgetWidth(), 0, 0, 0);  //左边留下行号和折叠标记的空间，可以延长
    //qDebug()  <<  "end: " << "updateLineNumberAreaWidth";
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
    foldingWidget->update(lineNumberArea->width(), rect.y(), foldingWidget->width(), rect.height());

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
}


void MdiChild::resizeEvent(QResizeEvent *e)
{
    QTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    int width = lineNumberAreaWidth();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), width, cr.height()));
    foldingWidget->setGeometry(QRect(cr.left() + width, cr.top(), foldingWidgetWidth(), cr.height()));
}

int MdiChild::getFirstVisibleBlockId()
{
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

    return 0;
}

void MdiChild::highlightCurrentLine()
{
//    QTextBlock block = document()->findBlockByNumber(12);
//    block.setUserState(2);

//    QTextBlock currentBlock = textCursor().block();
//    qDebug() << "currentBlockState: " << currentBlock.userState();


    QList<QTextEdit::ExtraSelection> extraSelections;
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
}


void MdiChild::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    QPainter painter(lineNumberArea);   //将lineNumberArea作为paint device
    painter.fillRect(event->rect(), QColor(240, 240, 240));   //整个边界背景设置为浅灰
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
    //int lineHeight = (int)document()->documentLayout()->blockBoundingRect(block).height(); //每行的高度
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
}

void MdiChild::foldingWidgetPaintEvent(QPaintEvent *event)
{
    if(requireNotes.isEmpty()) return;   //需求注释为空直接返回
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
        if (block.isVisible() && rect.top() >= event->rect().top() && rect.bottom() <= event->rect().bottom()) {

            painter.drawText(-2, rect.top(),   //why starts from -5, 增加了数字的右边距
                             foldingWidget->width(), fontMetrics().height(),
                             Qt::AlignRight, ">");
            it++;
        }else{
            break;
        }
    }
}

void MdiChild::foldingWidgetMousePressEvent(QMouseEvent *event)
{
    if(requireNotes.isEmpty()) return;   //需求注释为空直接返回
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
}

void MdiChild::faultLinePaint(int blockNumber)
{
    faultLineNumber = blockNumber;
    QTextBlock block = document()->findBlockByNumber(blockNumber);
    QRectF blockBox = document()->documentLayout()->blockBoundingRect(block);

    QIcon icon = QIcon(":/images/toolbar_images/error.png");
    //QPushButton *faultButton = new QPushButton(this);
    button->setIcon(icon);
    int iconSize = blockBox.height();
    //button->resize(iconSize, iconSize);
    if(block.isValid() && block.isVisible()){
        button->setGeometry(lineNumberArea->width(), blockBox.top(), iconSize, iconSize);
        button->setVisible(true);
    }
//    setFocus();
    connect(button, &QPushButton::clicked, this, &MdiChild::showFaultPromptDialog);

//    connect(button, &CustomButton::clicked, this, &MdiChild::fixButtonClicked);
//    connect(button, &CustomButton::enterSignal, this, &MdiChild::fixButtonHovered);
//    connect(button, &CustomButton::released, this, &MdiChild::clearPreview);
//    connect(button, &CustomButton::leaveSignal, this, &MdiChild::clearPreview);
}

void MdiChild::showFaultPromptDialog()
{
    if(faultPrompt->isVisible() == true){
        faultPrompt->setVisible(false);
        return;
    }
    if(button->isVisible() == false){
        return;
    }
    int currentCursor = textCursor().block().blockNumber();

    QTextBlock block = document()->findBlockByNumber(currentCursor);
    QRectF blockBox = document()->documentLayout()->blockBoundingRect(block);
    int height = faultPrompt->height();
    QRect buttonRect = button->geometry();
//    faultPrompt->setGeometry(buttonRect.x() + buttonRect.width(), buttonRect.y() - height,   //这是相对坐标，但是不知道为什么有问题
//                             blockBox.width() / 2, height);
    QPoint pos = mapToGlobal(buttonRect.topLeft());     //这是绝对坐标
    faultPrompt->setGeometry(pos.x(), blockBox.top() - height,
                            blockBox.width() / 2, height);



//        faultPrompt->setGeometry(lineNumberArea->width(), blockBox.top() - height,
//                                 blockBox.width() / 2, height);
    faultPrompt->show();
    emit showProblemTab(faultLineNumber);
    setFocus();
    //insertPreview = true;
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
        button->setVisible(false);
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
    //qDebug()  <<  "start: " << "highlightMatch";
    //bool match = false;
    QList<QTextEdit::ExtraSelection> selections;
    setExtraSelections(selections);

    //get userdata of the current line where cursor locates
    TextBlockData *data = static_cast<TextBlockData *>(textCursor().block().userData());

    if (data) {
        QVector<ParenthesisInfo *> infos = data->parentheses();
        //Returns the index of the block's first character within the document.
        int pos = textCursor().block().position();
        for (int i = 0; i < infos.size(); ++i) {
            ParenthesisInfo *info = infos.at(i);
            //position of cursor at the current line
            int curPos = textCursor().position() - textCursor().block().position();
            //if cursor is exactly between the first and second char of ">>>", find the match"<<<"
            if(info->matchLineNumber != -1){
                //找到匹配串的位置并高亮
                QTextBlock block = document()->findBlockByLineNumber(info->matchLineNumber);
                QTextCursor cursor(block);
                cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, info->matchPosition);
                int matchPos = cursor.position();


                //光标在>>>之间就会高亮
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
}

void MdiChild::updateMatch()
{
    //qDebug() << "start:" << "updateMatch";
    QTextBlock currentBlock = document()->begin();
    while(currentBlock.isValid()){
        TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
        if (data) {
            QVector<ParenthesisInfo *> infos = data->parentheses();
            //Returns the index of the block's first character within the document.
            for (int i = 0; i < infos.size(); ++i) {
                ParenthesisInfo *info = infos.at(i);
                //position of cursor at the current line
                if (info->character == startStr) {
                    matchLeftParenthesis(currentBlock, i + startStr.size(), 0, info->matchLineNumber, info->matchPosition);
                        //打印匹配到的括号的行号和相对位置
                        //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                } else if (info->character == endStr) {
                    matchRightParenthesis(currentBlock, i - endStr.size(), 0, info->matchLineNumber, info->matchPosition);
                        //qDebug() << "matchLine:" << info->matchLineNumber << "  matchPosition:" << info->matchPosition;
                }
            }
        }
        currentBlock = currentBlock.next();
    }
    requireNotes.clear();
    updateRequireNotes(-1, document()->lineCount(), nullptr);
    //qDebug() << "end:" << "updateMatch";
}

void MdiChild::updateRequireNotes(int startLine, int endLine, RequireNote* node)
{
    //从第一行开始找，存在匹配符，则得到上下行号的范围，在此范围内的一定是该节点的子节点
    for(int i = startLine + 1; i < endLine; ){
        QTextBlock currentBlock = document()->findBlockByLineNumber(i);
        TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
        if(data){
            QVector<ParenthesisInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
            if(infos.empty()) {
                i++;
                continue;
            };
            ParenthesisInfo *info = infos.at(0);
            if(info->matchLineNumber == -1 || info->character == endStr){  //未匹配到或是结束括号则直接跳过
                //qDebug() << "this" ;
                i++;
                continue;
            }
            //endLine = info->matchLineNumber;
            QString content = currentBlock.text();
            content = content.mid(content.indexOf(startStr) + startStr.length());  //找到括号后描述的需求说明

            RequireNote* newNode = new RequireNote(content, i, info->matchLineNumber, curFile);
            //if(newNode->startLine > node->startLine && newNode->endLine < node->endLine){
            if(node){
                node->children.append(newNode);
            }else{
                newNode->isRoot = true;  //根节点，顶级需求

            }
            requireNotes.append(newNode);
            updateRequireNotes(i, info->matchLineNumber, newNode);
            i = info->matchLineNumber;
            //}
        }else{
            i++;
        }
    }
}


bool MdiChild::matchLeftParenthesis(QTextBlock currentBlock, int i, int numLeftParentheses, int &matchLineNumber, int &matchPosition)
{
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<ParenthesisInfo *> infos = data->parentheses();

    int docPos = currentBlock.position();
    for (; i < infos.size(); ++i) {
        ParenthesisInfo *info = infos.at(i);

        if (info->character == startStr) {
            ++numLeftParentheses;
            continue;
        }

        if (info->character == endStr && numLeftParentheses == 0) {
            createParenthesisSelection(docPos + info->position);
            matchLineNumber = currentBlock.blockNumber();
            matchPosition = info->position;
            return true;
        } else
            --numLeftParentheses;
    }

    currentBlock = currentBlock.next();
    if (currentBlock.isValid())
        return matchLeftParenthesis(currentBlock, 0, numLeftParentheses, matchLineNumber, matchPosition);

    return false;
}

bool MdiChild::matchRightParenthesis(QTextBlock currentBlock, int i, int numRightParentheses, int &matchLineNumber, int &matchPosition)
{
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    QVector<ParenthesisInfo *> parentheses = data->parentheses();

    int docPos = currentBlock.position();
    for (; i > -1 && parentheses.size() > 0; --i) {
        ParenthesisInfo *info = parentheses.at(i);
        if (info->character == endStr) {
            ++numRightParentheses;
            continue;
        }
        if (info->character == startStr && numRightParentheses == 0) {
            createParenthesisSelection(docPos + info->position);
            matchLineNumber = currentBlock.blockNumber();
            matchPosition = info->position;
            return true;
        } else
            --numRightParentheses;
    }

    currentBlock = currentBlock.previous();

    if (currentBlock.isValid()){
        data = static_cast<TextBlockData *>(currentBlock.userData());
        parentheses = data->parentheses();
        return matchRightParenthesis(currentBlock, parentheses.size() - 1, numRightParentheses, matchLineNumber, matchPosition);
    }

    return false;
}

void MdiChild::createParenthesisSelection(int pos)
{
    QList<QTextEdit::ExtraSelection> selections = extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    format.setBackground(Qt::green);
    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, startStr.size());
    selection.cursor = cursor;

    selections.append(selection);

    setExtraSelections(selections);
}

void MdiChild::changeRequirementToNote(int lineNumber)
{
    QTextBlock currentBlock = document()->findBlockByLineNumber(lineNumber);
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    int end;
    if(data){
        QVector<ParenthesisInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
        if(infos.empty()) {
            return;
        };
        ParenthesisInfo *info = infos.at(0);
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
            int index = text.indexOf(startStr);
            if(index != -1){
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, startStr.length());
                cursor.insertText("//");
            }

            block = document()->findBlockByLineNumber(req->endLine);  //将<<<替换为
            cursor.setPosition(block.position());
            text = block.text();
            index = text.indexOf(endStr);
            if(index != -1){
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, endStr.length());
                cursor.insertText("");

            }
        }
    }

}

void MdiChild::goToLine(int lineNumber)
{
    QTextCursor cursor(document());
    QTextBlock block = document()->findBlockByLineNumber(lineNumber);
    cursor.setPosition(block.position());
    QString text = block.text();
    int index = text.indexOf(startStr);
    if(index != -1){
        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, index);
    }
    setTextCursor(cursor);
    ensureCursorVisible(); // 确保光标可见
}

void MdiChild::autoCompleteMatch()
{
    //qDebug()  <<  "start: " << "autoCompleteMatch";
    // 获取当前光标位置
    QTextCursor cursor = textCursor();
    QTextBlock currentBlock = cursor.block();
    TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
    if(data){
        QVector<ParenthesisInfo *> infos = data->parentheses();  //这里先考虑每行只可以有一个匹配符的情况
        if(!infos.empty()) {
            ParenthesisInfo *info = infos.at(0);
            if(info->character == startStr && info->matchLineNumber != -1) return;  //如果当前行>>>有匹配，直接返回
        }
    }
    // 获取当前光标所在行的文本
    QString currentLineText = cursor.block().text();

    // 判断当前行是否为空行并且以">>>"结尾
    if (currentLineText.endsWith(startStr)) {
        //调整光标到本行末尾
        cursor.setPosition(currentBlock.position() + currentBlock.length());
        setTextCursor(cursor);
        // 插入一个新行
        cursor.insertBlock();
        // 在新行中插入"<<<"
        cursor.insertText(endStr);
    }
    //qDebug()  <<  "end: " << "autoCompleteMatch";
}

