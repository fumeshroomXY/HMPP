#include "faultlinehighlighter.h"
#include <QDebug>

FaultLineHighlighter::FaultLineHighlighter(QTextDocument *parent, QRegExp pattern,
                                           QTextCharFormat format, QString faultName)
    : QSyntaxHighlighter(parent)
{
    faultHighlightRule.format = format;
    faultHighlightRule.pattern = pattern;
    faultHighlightRule.faultName = faultName;
    highlightedLines = QList<int>();

}

void FaultLineHighlighter::highlightBlock(const QString &text)
{
//    QRegularExpressionMatchIterator matchIterator = faultHighlightRule.pattern.globalMatch(text);
//    while (matchIterator.hasNext()) {
//    QRegularExpressionMatch match = matchIterator.next();
//    setFormat(match.capturedStart(), match.capturedLength(), faultHighlightRule.format);
//    highlightedLines.append(currentBlock().blockNumber());
//    }
}

