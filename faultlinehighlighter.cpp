#include "faultlinehighlighter.h"
#include <QDebug>

FaultLineHighlighter::FaultLineHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
//    keywordFormat.setForeground(Qt::darkBlue);
//    keywordFormat.setFontWeight(QFont::Bold);
//    QStringList keywordPatterns;
//    keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
//                    << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
//                    << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
//                    << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
//                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
//                    << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
//                    << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
//                    << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
//                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
//                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\breturn\\b"
//                    << "\\bnew\\b" << "\\bdelete\\b" << "\\bfor\\b"
//                    << "\\bwhile\\b" << "\\binclude\\b";
//    foreach (const QString &pattern, keywordPatterns) {
//        rule.pattern = QRegExp(pattern);
//        rule.format = keywordFormat;
//        highlightingRules.append(rule);
////! [0] //! [1]
//    }
////! [1]

    faultLineFormat.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    faultLineFormat.setUnderlineColor(Qt::red);
    rule.pattern = QRegExp("[a-zA-Z_][a-zA-Z0-9_]*\\s*/\\s*[a-zA-Z_][a-zA-Z0-9_]*");
    rule.format = faultLineFormat;
    highlightingRules.append(rule);
}

void FaultLineHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            emit findFault();
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}

