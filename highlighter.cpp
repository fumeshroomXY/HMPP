#include "highlighter.h"
#include <QDebug>
#include <QTextDocument>

const QString startStr = "{";
const QString endStr = "}";

TextBlockData::TextBlockData()
{
    // Nothing to do
}

QVector<ParenthesisInfo *> TextBlockData::parentheses()
{
    return m_parentheses;
}

void TextBlockData::insert(ParenthesisInfo *info)
{
    int i = 0;
    while (i < m_parentheses.size() &&
        info->position > m_parentheses.at(i)->position)
        ++i;

    m_parentheses.insert(i, info);
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
    int faultIndex = faultRegExp.indexIn(text);
    if(faultIndex >= 0){
        QTextBlock block = currentBlock();
        QString var0 = faultRegExp.cap(1);
        QString var1 = faultRegExp.cap(2);
        int blockNumber = block.blockNumber();


        QString fixedCode = "if(%1 == 0)";
        fixedCode = fixedCode.arg(var1);
        qDebug() << fixedCode;
        QTextCursor cursor = document()->find(fixedCode, 0);  //

        if(cursor.isNull()){
            emit findFault(blockNumber);
            emit faultInfo(var0, var1);
            int length = faultRegExp.matchedLength();
            setFormat(faultIndex, length, faultLineFormat);
            faultIndex = faultRegExp.indexIn(text, faultIndex + length);
        }
    }

    //匹配双尖括号
    TextBlockData *data = new TextBlockData;

    int leftPos = text.indexOf(startStr);
    while (leftPos != -1) {
        ParenthesisInfo *info = new ParenthesisInfo;
        info->character = startStr;
        info->position = leftPos;

        data->insert(info);
        leftPos = text.indexOf(startStr, leftPos + startStr.size());
    }

    int rightPos = text.indexOf(endStr);
    while (rightPos != -1) {
        ParenthesisInfo *info = new ParenthesisInfo;
        info->character = endStr;
        info->position = rightPos;

        data->insert(info);

        rightPos = text.indexOf(endStr, rightPos + endStr.size());
    }

    setCurrentBlockUserData(data);

}
//! [11]
//!
