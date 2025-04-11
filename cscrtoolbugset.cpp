#include "cscrtoolbugset.h"
#include <QDebug>


CscrToolBugSet::CscrToolBugSet()
{
    bugFileName = "";
    bugObjectList = QList<BugObject>();
    currentIndex = 0;
}

CscrToolBugSet::CscrToolBugSet(QString fileName)
{
    bugFileName = fileName;
    bugObjectList = QList<BugObject>();
    currentIndex = 0;
}

bool CscrToolBugSet::append(QString fileName, const BugObject& obj)
{
    if (fileName != bugFileName) {
        qDebug() << "fileName not matches. " << bugFileName << " is not equal to " << fileName;
        return false;
    }

    auto it = std::lower_bound(bugObjectList.begin(), bugObjectList.end(), obj);
    auto insertedIt = bugObjectList.insert(it, obj);
    int index = std::distance(bugObjectList.begin(), insertedIt);
    setCurrentIndex(index);
    return true;
}

QList<BugObject> CscrToolBugSet::getBugObjectsAtCurrentLine(QString fileName, int lineNumber)
{
    if (fileName != bugFileName) {
        qDebug() << "fileName not matches. " << bugFileName << " is not equal to " << fileName;
        return QList<BugObject>();
    }

    QList<BugObject> result;
    for (const BugObject& bug : bugObjectList) {
        if (bug.bugLine == lineNumber) {
            result.append(bug);
        }
    }
    return result;
}

QString CscrToolBugSet::getBugFileName() const
{
    return bugFileName;
}

void CscrToolBugSet::setBugFileName(const QString &value)
{
    bugFileName = value;
}

QList<BugObject> CscrToolBugSet::getBugObjectList() const
{
    return bugObjectList;
}

void CscrToolBugSet::setBugObjectList(const QList<BugObject> &value)
{
    bugObjectList = value;
    currentIndex = 0;
}

BugObject CscrToolBugSet::getCurrentBugObject()
{
    if (currentIndex >= 0 && currentIndex < bugObjectList.size()) {
        return bugObjectList.at(currentIndex);
    } else {
        // Handle the case where currentIndex is out of bounds
        qDebug() << "getCurrentBugObject: currentIndex is out of range!";
        return BugObject(); // Assuming BugObject has a default constructor
    }
}

void CscrToolBugSet::setCurrentIndex(int value)
{
    if (value >= 0 && value < bugObjectList.size()) {
        currentIndex = value;
    }
}

int CscrToolBugSet::getCurrentIndex() const
{
    return currentIndex;
}



