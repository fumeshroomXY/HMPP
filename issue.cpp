#include "issue.h"


void ClassUndefinedSyntaxIssue::issueSolveFunc()
{

}

QString Issue::getDescription() const
{
    return description;
}

void Issue::setDescription(const QString &value)
{
    description = value;
}

QString ClassEncapsulateSyntaxIssue::getFilePath() const
{
    return filePath;
}

void ClassEncapsulateSyntaxIssue::setFilePath(const QString &value)
{
    filePath = value;
}

int ClassEncapsulateSyntaxIssue::getIssueLineNumber() const
{
    return issueLineNumber;
}

void ClassEncapsulateSyntaxIssue::setIssueLineNumber(int value)
{
    issueLineNumber = value;
}

QImage ClassEncapsulateSyntaxIssue::getImage() const
{
    return image;
}

void ClassEncapsulateSyntaxIssue::setImage(const QImage &value)
{
    image = value;
}

int ClassEncapsulateSyntaxIssue::getPosition() const
{
    return position;
}

void ClassEncapsulateSyntaxIssue::setPosition(int value)
{
    position = value;
}

void ClassMemberUnspecifiedIssue::issueSolveFunc()
{

}
