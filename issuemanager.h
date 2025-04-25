#ifndef ISSUEMANAGER_H
#define ISSUEMANAGER_H

#include <QObject>
#include <memory>
#include "issue.h"

/**
 * @brief the issue manager
 */
class IssueManager : public QObject
{
    Q_OBJECT
public:
    explicit IssueManager(QObject *parent = 0, QString proFileName = "");

    void appendUndefinedIssue(const QList<ClassUndefinedSyntaxIssue>& list);

    void appendUnspecifiedIssue(const QList<ClassMemberUnspecifiedIssue>& list);

    QList<std::shared_ptr<ClassUndefinedSyntaxIssue> > getUndefinedIssueList() const;

    QList<std::shared_ptr<ClassMemberUnspecifiedIssue> > getUnspecifiedIssueList() const;

    void clearUndefinedIssueList();

    void clearUnspecifiedIssueList();

private:
    QString proFileName;

    QList<std::shared_ptr<ClassUndefinedSyntaxIssue>> undefinedIssueList;

    QList<std::shared_ptr<ClassMemberUnspecifiedIssue>> unspecifiedIssueList;


signals:

public slots:
};

#endif // ISSUEMANAGER_H
