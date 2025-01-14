#include "highlighter.h"
#include <QDebug>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>

const QString ParenthesisStartStr = "{";
const QString ParenthesisEndStr = "}";

const QString RequireNoteStartStr = "/* todo:";
const QString RequireNoteEndStr = "*/";

TextBlockData::TextBlockData()
{
    // Nothing to do
}

QVector<MarkInfo *> TextBlockData::parentheses()
{
    return m_parentheses;
}

QVector<MarkInfo *> TextBlockData::todoNotes()
{
    return m_todoNotes;
}

QVector<MarkInfo *> TextBlockData::getInfos(QString targetStr)
{
    if(targetStr == ParenthesisStartStr){
        return parentheses();
    }else if(targetStr == RequireNoteStartStr){
        return todoNotes();
    }else{
        return QVector<MarkInfo*>();
    }
}

void TextBlockData::insertParenthesisInfo(MarkInfo *info)
{
    int i = 0;
    while (i < m_parentheses.size() &&
        info->position > m_parentheses.at(i)->position)
        ++i;

    m_parentheses.insert(i, info);
}

void TextBlockData::insertToDoNoteInfo(MarkInfo *info)
{
    int i = 0;
    while (i < m_todoNotes.size() &&
        info->position > m_todoNotes.at(i)->position)
        ++i;

    m_todoNotes.insert(i, info);
}


//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\breturn\\b"
                    << "\\bnew\\b" << "\\bdelete\\b" << "\\bfor\\b"
                    << "\\bwhile\\b" << "\\binclude\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
//! [0] //! [1]
    }
//! [1]

//! [2]
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);
//! [2]

//! [3]
    singleLineCommentFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkGreen);
//! [3]
    //单行伪码需求
    singleLineRequireFormat.setForeground(Qt::red);
    rule.pattern = QRegExp("(>>>[^\n]*)|(<<<)");
    rule.format = singleLineRequireFormat;
    highlightingRules.append(rule);



//! [4]
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
//! [4]

//! [5]
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);
//! [5]

//! [6]
    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");

    //伪码需求的正则表达式
    //requireStartExpression = QRegExp(">>>");

    faultLineFormat.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    faultLineFormat.setUnderlineColor(Qt::red);

    faultHighlightRule.pattern = faultRegExp;
    faultHighlightRule.format = faultLineFormat;

}

void Highlighter::addHighlightingRule(const QRegExp &pattern, const QTextCharFormat &format)
{
    HighlightingRule rule;
    rule.pattern = pattern;
    rule.format = format;
    if(highlightingRules.contains(rule)) return;   //已经包含了就直接返回，不添加
    highlightingRules.append(rule);
}

void Highlighter::deleteHighlightingRule(const QRegExp &pattern, const QTextCharFormat &format)
{
    HighlightingRule rule;
    rule.pattern = pattern;
    rule.format = format;
    highlightingRules.removeOne(rule);
}

//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)  //After a QSyntaxHighlighter object is created,
                                                        //its highlightBlock() function will be called automatically
                                                            //highlighting the given text block.
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
//! [7] //! [8]
    setCurrentBlockState(0);
//! [8]

//! [9]
    int startIndex = 0;
    // 没有/* 或 */ 对应状态0
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

//! [9] //! [10]
    while (startIndex >= 0) {
//! [10] //! [11]
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }


    //查询并高亮除0错误
    //当前文档名为演示文档时，才检查错误
//    int faultIndex = faultRegExp.indexIn(text);
//    if(faultIndex >= 0){

//        QTextBlock block = currentBlock();
//        QString var0 = faultRegExp.cap(1);
//        QString var1 = faultRegExp.cap(2);
//        int blockNumber = block.blockNumber();


//        QString fixedCode = "if(%1 == 0)";
//        fixedCode = fixedCode.arg(var1);
//        qDebug() << fixedCode;
//        QTextCursor cursor = document()->find(fixedCode, 0);  //

//        if(cursor.isNull()){
//            emit findFault(blockNumber);
//            emit faultInfo(var0, var1);
//            int length = faultRegExp.matchedLength();
//            setFormat(faultIndex, length, faultLineFormat);
//            faultIndex = faultRegExp.indexIn(text, faultIndex + length);
//        }
//    }

    //匹配双尖括号
    TextBlockData *data = new TextBlockData;

    int leftPos = text.indexOf(ParenthesisStartStr);
    while (leftPos != -1) {
        MarkInfo *info = new MarkInfo;
        info->character = ParenthesisStartStr;
        info->position = leftPos;

        data->insertParenthesisInfo(info);
        leftPos = text.indexOf(ParenthesisStartStr, leftPos + ParenthesisStartStr.size());
    }

    leftPos = text.indexOf(RequireNoteStartStr);
    while(leftPos != -1){
        MarkInfo *info = new MarkInfo;
        info->character = RequireNoteStartStr;
        info->position = leftPos;

        data->insertToDoNoteInfo(info);
        leftPos = text.indexOf(RequireNoteStartStr, leftPos + RequireNoteStartStr.size());
    }

    int rightPos = text.indexOf(ParenthesisEndStr);
    while (rightPos != -1) {
        MarkInfo *info = new MarkInfo;
        info->character = ParenthesisEndStr;
        info->position = rightPos;

        data->insertParenthesisInfo(info);

        rightPos = text.indexOf(ParenthesisEndStr, rightPos + ParenthesisEndStr.size());
    }

    rightPos = text.indexOf(RequireNoteEndStr);
    while (rightPos != -1) {
        MarkInfo *info = new MarkInfo;
        info->character = RequireNoteEndStr;
        info->position = rightPos;

        data->insertToDoNoteInfo(info);

        rightPos = text.indexOf(RequireNoteEndStr, rightPos + RequireNoteEndStr.size());
    }

    setCurrentBlockUserData(data);

}
//! [11]
//!
