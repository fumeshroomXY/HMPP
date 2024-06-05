#ifndef ISSUE_H
#define ISSUE_H
#include <QString>


class Issue
{
public:
    Issue(){
        name = "";
        description = "";
    }
    Issue(QString _name = "", QString _description = "") : name(_name), description(_description) {}
    virtual void issueSolveFunc(){}

    QString getName() const {return name; }
    void setName(const QString &name) {name = name; }

private:
    QString name;
    QString description;

};


class ClassEncapsulateIssue : public Issue
{
public:
    ClassEncapsulateIssue(){
        filePath = "";
        issueLineNumber = -1;
    }
    ClassEncapsulateIssue(QString _name, QString _description, QString _filePath = "", int lineNumber = -1)
        : name(_name), description(_description), filePath(_filePath), issueLineNumber(lineNumber)
    {
    }

    void issueSolveFunc() override;

private:
    QString filePath;
    int issueLineNumber;

};


#endif // ISSUE_H
