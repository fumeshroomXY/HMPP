#ifndef FAULTLINEHIGHLIGHTER_H
#define FAULTLINEHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class FaultLineHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    FaultLineHighlighter(QTextDocument *parent = 0);

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
    QTextCharFormat faultLineFormat;
    QRegExp faultRegExp = QRegExp("[a-zA-Z_][a-zA-Z0-9_]*\\s*/\\s*[a-zA-Z_][a-zA-Z0-9_]*");

signals:
    void findFault();
public slots:

};


#endif // FAULTLINEHIGHLIGHTER_H
