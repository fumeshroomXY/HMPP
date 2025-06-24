#ifndef CSCRTOOLBUGSET_H
#define CSCRTOOLBUGSET_H

#include <QString>
#include <QList>
#include <QJsonObject>

const QStringList bugNatureList = {"Default Bug", "Functional Bug", "Performance Bug", "UI/UX Bug", "Security Bug",
                                  "Compatibility Bug", "Concurrency Bug", "AI Suggestion"};
/**
 * @brief the review bug class
 */

struct BugObject{
    int bugLine;
    QString bugName;
    QString bugNature;
    QString bugDescription;
    QString reviewerQuestion;
    QString bugSolution;

    BugObject(){}

    BugObject(int line, const QString& name, const QString& nature, const QString& description, const QString& question, const QString& solution)
         : bugLine(line), bugName(name), bugNature(nature), bugDescription(description), reviewerQuestion(question), bugSolution(solution) {}

    // Overload the < operator for sorting based on bugLine and bugName
    bool operator<(const BugObject& other) const {
        if (bugLine == other.bugLine) {
            return bugName < other.bugName;
        }
        return bugLine < other.bugLine;
    }

    // Convert BugObject to JSON
    QJsonObject toJson() const {
        QJsonObject obj;
        obj["bugLine"] = bugLine;
        obj["bugName"] = bugName;
        obj["bugNature"] = bugNature;
        obj["bugDescription"] = bugDescription;
        obj["reviewerQuestion"] = reviewerQuestion;
        obj["bugSolution"] = bugSolution;
        return obj;
    }

    static BugObject fromJson(const QJsonObject &obj) {
        BugObject bug;
        bug.bugLine = obj["bugLine"].toInt();
        bug.bugName = obj["bugName"].toString();
        bug.bugNature = obj["bugNature"].toString();
        bug.bugDescription = obj["bugDescription"].toString();
        bug.reviewerQuestion = obj["reviewerQuestion"].toString();
        bug.bugSolution = obj["bugSolution"].toString();
        return bug;
    }
};

/**
 * @brief manage the bugs
 */

class CscrToolBugSet
{
public:
    CscrToolBugSet();

    CscrToolBugSet(QString fileName);

    bool append(QString fileName, const BugObject& obj);

    QList<BugObject> getBugObjectsAtCurrentLine(QString fileName, int lineNumber);

    QString getBugFileName() const;
    void setBugFileName(const QString &value);

    QList<BugObject> getBugObjectList() const;
    void setBugObjectList(const QList<BugObject> &value);

    BugObject getCurrentBugObject();

    void setCurrentIndex(int value);

    int getCurrentIndex() const;

private:
    QString bugFileName;

    QList<BugObject> bugObjectList;
    int currentIndex = 0;

};

#endif // CSCRTOOLBUGSET_H
