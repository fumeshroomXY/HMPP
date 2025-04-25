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

    BugObject(){}

    BugObject(int line, const QString& name, const QString& nature, const QString& description)
         : bugLine(line), bugName(name), bugNature(nature), bugDescription(description) {}

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
        return obj;
    }

    static BugObject fromJson(const QJsonObject &obj) {
        return {
            obj["bugLine"].toInt(),
            obj["bugName"].toString(),
            obj["bugNature"].toString(),
            obj["bugDescription"].toString()
        };
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
