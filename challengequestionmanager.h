#ifndef CHALLENGEQUESTIONMANAGER_H
#define CHALLENGEQUESTIONMANAGER_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include "cscrtoolchallengerquestion.h"

class ChallengeQuestionManager
{
public:
    explicit ChallengeQuestionManager(QObject *parent = 0);

    // Access questions by category
    QStringList questionsByCategory(const QString &category) const;

    // Modify questions
    void addQuestion(const QString &category, const QString &question);
    void removeQuestion(const QString &category, const QString &question);
    void setQuestionsByCategory(const QString &category, const QStringList &questions);

    // Get all categories
    QStringList categories() const;

    // Load/save JSON
    bool loadFromJson(const QString &filePath);
    bool saveToJson(const QString &filePath) const;

    QMap<QString, QStringList> getQuestions() const;
    void setQuestions(const QMap<QString, QStringList> &value);

signals:

public slots:

private:
    QMap<QString, QStringList> questions;
};

#endif // CHALLENGEQUESTIONMANAGER_H
