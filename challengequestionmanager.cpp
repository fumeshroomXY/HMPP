#include "challengequestionmanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

ChallengeQuestionManager::ChallengeQuestionManager(QObject *parent) :
    questions(defaultQuestionList)
{

}

QStringList ChallengeQuestionManager::questionsByCategory(const QString &category) const
{
    return questions.value(category);
}

void ChallengeQuestionManager::addQuestion(const QString &category, const QString &question)
{
    questions[category].append(question);
}

void ChallengeQuestionManager::removeQuestion(const QString &category, const QString &question)
{
    questions[category].removeAll(question);
}

void ChallengeQuestionManager::setQuestionsByCategory(const QString &category, const QStringList &questions)
{
    this->questions[category] = questions;
}

QStringList ChallengeQuestionManager::categories() const
{
    return questions.keys();
}

bool ChallengeQuestionManager::loadFromJson(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file for reading:" << filePath;
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON format.";
        return false;
    }

    QJsonObject rootObject = doc.object();
    questions.clear();

    for (const QString &key : rootObject.keys()) {
        QJsonArray arr = rootObject.value(key).toArray();
        QStringList list;
        for (const QJsonValue &v : arr) {
            list.append(v.toString());
        }
        questions[key] = list;
    }

    return true;
}

bool ChallengeQuestionManager::saveToJson(const QString &filePath) const
{
    QJsonObject rootObject;
        for (auto it = questions.constBegin(); it != questions.constEnd(); ++it) {
            QJsonArray arr;
            for (const QString &q : it.value()) {
                arr.append(q);
            }
            rootObject[it.key()] = arr;
        }

        QJsonDocument doc(rootObject);

        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly)) {
            qWarning() << "Cannot open file for writing:" << filePath;
            return false;
        }

        file.write(doc.toJson());
        file.close();

        return true;
}

QMap<QString, QStringList> ChallengeQuestionManager::getQuestions() const
{
    return questions;
}

void ChallengeQuestionManager::setQuestions(const QMap<QString, QStringList> &value)
{
    questions = value;
}


