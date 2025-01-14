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
    FaultLineHighlighter(QTextDocument *parent, QRegExp pattern, QTextCharFormat format, QString faultName);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct FaultHighlightRule
    {
        QRegExp pattern;
        QTextCharFormat format;
        QString faultName;

        bool operator==(const FaultHighlightRule& other) const {
            return pattern == other.pattern && format == other.format && faultName == other.faultName;
        }
    };
    FaultHighlightRule faultHighlightRule;
    QList<int> highlightedLines;


signals:
    void findFault();
public slots:

};


#endif // FAULTLINEHIGHLIGHTER_H
