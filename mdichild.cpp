#include <QtWidgets>
#include <QPlainTextEdit>

#include "mdichild.h"
#include "faultpromptdialog.h"

MdiChild::MdiChild(QWidget *parent): QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);   //子窗口关闭时销毁这个对象
    isUntitled = true;

    lineNumberArea = new LineNumberArea(this);
    faultPrompt = new FaultPromptDialog(this);
    button = new CustomButton(this);
    button->setVisible(false);

    connect(document(), SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    //connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(faultLinePaint()));
    //connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, &QTextEdit::cursorPositionChanged, this, highlightCurrentLine);

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
}

void MdiChild::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;    //新建的文档没有被保存过
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
    int lineHeight = getLineHeight();
    int space = 2 * lineHeight + fontMetrics().width(QLatin1Char('9')) * digits;   //可以指定其他width

    return space;
}

void MdiChild::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);  //左边留下行号的空间，可以延长
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

    updateLineNumberAreaWidth(0);
    //----------
    int dy = verticalScrollBar()->sliderPosition();
    if (dy > -1) {
        lineNumberArea->scroll(0, dy);   //dx = 0, dy = dy, 如果scrollbar滚动了的话，linenumberarea也要跟着滚动
    }

    // Adjust slider to alway see the number of the currently being edited line...
    // Not sure what the part does.
    int firstBlockId = getFirstVisibleBlockId();
    if (firstBlockId == 0 || textCursor().block().blockNumber() == firstBlockId - 1)
//        qDebug() << "firstBlockId :" << firstBlockId;
//        qDebug() << "textCursor:" << textCursor().block().blockNumber();
        verticalScrollBar()->setSliderPosition(dy - document()->documentMargin());

//    // Snap to first line (TODO...)
//    if (first_block_id > 0)
//    {
//        int slider_pos = this->verticalScrollBar()->sliderPosition();
//        int prev_block_height = (int) this->document()->documentLayout()->blockBoundingRect(this->document()->findBlockByNumber(first_block_id-1)).height();
//        if (dy <= this->document()->documentMargin() + prev_block_height)
//            this->verticalScrollBar()->setSliderPosition(slider_pos - (this->document()->documentMargin() + prev_block_height));
//    }

}

//void MdiChild::updateLineNumberArea(const QRect &rect, int dy)
//{
//    if (dy)
//        lineNumberArea->scroll(0, dy);
//    else
//        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

//    if (rect.contains(viewport()->rect()))
//        updateLineNumberAreaWidth(0);
//}

void MdiChild::resizeEvent(QResizeEvent *e)
{
    QTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
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

//void MdiChild::lineNumberAreaPaintEvent(QPaintEvent *event)
//{
//    QPainter painter(lineNumberArea);
//    painter.fillRect(event->rect(), Qt::lightGray);

////![extraAreaPaintEvent_0]

////![extraAreaPaintEvent_1]
//    QTextBlock block = document()->firstBlock();
//    int blockNumber = block.blockNumber();
//    int top = (int) block.layout()->boundingRect().top();
//    //int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
//    int bottom = (int) block.layout()->boundingRect().bottom();

//    qDebug() << "top:" << top;
//    qDebug() << "bottom:" << bottom;
//    //int bottom = top + (int) QPlainTextEdit::blockBoundingRect(block).height();
////![extraAreaPaintEvent_1]

////![extraAreaPaintEvent_2]
//    while (block.isValid() && top <= event->rect().bottom()) {
//        qDebug() << "-------" ;
//        if (block.isVisible() && bottom >= event->rect().top()) {
//            qDebug() << "-------" ;
//            QString number = QString::number(blockNumber + 1);
//            painter.setPen(Qt::black);
//            qDebug() << "-------" ;
//            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
//                             Qt::AlignRight, number);
//        }
//        qDebug() << "-------" ;
//        block = block.next();
//        if(block.isValid() == false) return;
//        top = bottom;
//        bottom = top + (int)block.layout()->boundingRect().height();
//        qDebug() << "top:" << top;
//        qDebug() << "bottom:" << bottom;
//        //bottom = top + (int) blockBoundingRect(block).height();
//        ++blockNumber;
//    }
//}

void MdiChild::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    verticalScrollBar()->setSliderPosition(verticalScrollBar()->sliderPosition());

    QPainter painter(lineNumberArea);   //将lineNumberArea作为paint device
    painter.fillRect(event->rect(), Qt::lightGray);   //整个边界背景设置为浅灰
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
    int lineHeight = getLineHeight(); //每行的高度
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);   //blockNumber 从0开始，所以要+1
            painter.setPen(QColor(120, 120, 120));
            painter.setPen(col_0);
            //painter.setPen((textCursor().blockNumber() == blockNumber) ? col_1 : col_0);
            painter.drawText(-lineHeight, top,   //why starts from -5, 增加了数字的右边距
                             lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + lineHeight;
        ++blockNumber;
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

