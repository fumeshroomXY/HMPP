#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QString>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

//! [0]
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;

        bool operator==(const HighlightingRule& other) const {
            return pattern == other.pattern && format == other.format;
        }
    };
    QVector<HighlightingRule> highlightingRules;


    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    //伪码需求的开始和结束符
    QRegExp requireStartExpression;
    QRegExp requireEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

    //伪码需求的格式
    QTextCharFormat singleLineRequireFormat;

    QTextCharFormat faultLineFormat;
    QRegExp faultRegExp = QRegExp("([a-zA-Z_][a-zA-Z0-9_]*)\\s*/\\s*([a-zA-Z_][a-zA-Z0-9_]*)");
    HighlightingRule faultHighlightRule;

signals:
    void findFault(int blockNumber);
    void faultInfo(QString variable1, QString variable2);
public slots:

};
//! [0]

#endif // HIGHLIGHTER_H
