#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QString>
#include <QVector>

QT_BEGIN_NAMESPACE
class QTextDocument;
class QString;
QT_END_NAMESPACE

//匹配符可以根据需求更改
extern const QString ParenthesisStartStr;
extern const QString ParenthesisEndStr;

extern const QString RequireNoteStartStr;
extern const QString RequireNoteEndStr;


struct MarkInfo
{
    QString character;
    int position;    //存的是指定字符在这一行文本中的相对位置
    int matchLineNumber = -1;
    int matchPosition = -1;
};


class TextBlockData : public QTextBlockUserData
{
public:
    TextBlockData();

    QVector<MarkInfo *> parentheses();
    QVector<MarkInfo *> todoNotes();
    QVector<MarkInfo *> getInfos(QString targetStr);
    void insertParenthesisInfo(MarkInfo *info);
    void insertToDoNoteInfo(MarkInfo *info);

private:
    QVector<MarkInfo *> m_parentheses;  //用于存匹配大括号的信息{}
    QVector<MarkInfo *> m_todoNotes;  //用于存需求注释的信息/*todo: */
};

//! [0]
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    void addHighlightingRule(const QRegExp &pattern, const QTextCharFormat &format);

    void deleteHighlightingRule(const QRegExp &pattern, const QTextCharFormat &format);

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
