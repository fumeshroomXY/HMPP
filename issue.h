#ifndef ISSUE_H
#define ISSUE_H
#include <QString>
#include <QImage>
#include <QDebug>


class Issue
{
public:
    Issue(){
        name = "";
        description = "";
    }
    Issue(const QString& _name, const QString& _description) : name(_name), description(_description) {}
    virtual void issueSolveFunc(){}

    virtual ~Issue() {
        // Virtual destructor
    }

    QString getName() const {return name; }
    void setName(const QString & _name) {name = _name; }

    QString getDescription() const;
    void setDescription(const QString &value);

protected:
    QString name;
    QString description;

};


class ClassEncapsulateSyntaxIssue : public Issue
{
public:
    ClassEncapsulateSyntaxIssue(){
        filePath = "";
        issueLineNumber = -1;
        position = 0;
        image = QImage(":/images/toolbar_images/question.png");
    }
    ClassEncapsulateSyntaxIssue(const QString& _name, const QString& _description,
                                const QString& _filePath, int lineNumber, int position = 0)
        : Issue(_name, _description), filePath(_filePath), issueLineNumber(lineNumber), position(position){
        image = QImage(":/images/toolbar_images/question.png");
    }

    ClassEncapsulateSyntaxIssue(const QString& _filePath, int lineNumber, int position = 0)
        : filePath(_filePath), issueLineNumber(lineNumber), position(position){
        image = QImage(":/images/toolbar_images/question.png");
    }

    virtual ~ClassEncapsulateSyntaxIssue() {
        // Virtual destructor
    }

    virtual void issueSolveFunc(){}

    virtual bool operator == (const ClassEncapsulateSyntaxIssue& other) const{
        qDebug() << "ClassEncapsulateSyntaxIssue == ";
        return other.name == name && other.description == description
                && other.filePath == filePath && other.issueLineNumber == issueLineNumber
                && position == other.position;
    }

    QString getFilePath() const;
    void setFilePath(const QString &value);

    int getIssueLineNumber() const;
    void setIssueLineNumber(int value);

    QImage getImage() const;
    void setImage(const QImage &value);

    int getPosition() const;
    void setPosition(int value);

protected:
    QString filePath;
    int issueLineNumber;
    QImage image;
    int position;

};

class ClassUndefinedSyntaxIssue : public ClassEncapsulateSyntaxIssue
{
public:
    ClassUndefinedSyntaxIssue(){
        name = "ClassUndefinedIssue";
        description = "Class is instantiated without being defined";
    }

    ClassUndefinedSyntaxIssue(const QString& className, const QString& _filePath, int lineNumber, int position = 0)
        : ClassEncapsulateSyntaxIssue(_filePath, lineNumber, position){
        name = "ClassUndefinedIssue";
        description = "Class variable [" + className + "] is instantiated without being defined";
    }

    void issueSolveFunc() override;

    bool operator == (const ClassUndefinedSyntaxIssue& other) const{
        // Use dynamic_cast to check the type of 'other'
        qDebug() << "ClassUndefinedSyntaxIssue == ";
        return other.name == name && other.description == description
                    && other.filePath == filePath;

    }


private:

};

class ClassMemberUnspecifiedIssue : public ClassEncapsulateSyntaxIssue
{
public:
    ClassMemberUnspecifiedIssue(){
        name = "ClassMemberUnspecifiedIssue";
        description = "Type of class member is unspecified";
    }

    ClassMemberUnspecifiedIssue(const QString& _className, const QString& _filePath, int lineNumber, int position = 0)
        : ClassEncapsulateSyntaxIssue(_filePath, lineNumber, position), className(_className){
        name = "ClassMemberUnspecifiedIssue";
        description = "Type of class member is unspecified";
    }

    void issueSolveFunc() override;

    bool operator == (const ClassMemberUnspecifiedIssue& other) const{
        // Use dynamic_cast to check the type of 'other'
        qDebug() << "ClassUndefinedSyntaxIssue == ";
        return other.name == name && other.description == description
                    && other.filePath == filePath && className == other.className
                && issueLineNumber == other.issueLineNumber && position == other.position;

    }
    ~ClassMemberUnspecifiedIssue(){}

private:
    QString className;
};


#endif // ISSUE_H
