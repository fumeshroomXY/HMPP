#ifndef CHALLENGEQUESTIONMANAGERDIALOG_H
#define CHALLENGEQUESTIONMANAGERDIALOG_H

#include <QDialog>
#include "ui_challengequestionmanagerdialog.h"
#include "ChallengeQuestionManager.h"

class ChallengeQuestionManagerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ChallengeQuestionManagerDialog(QWidget *parent = nullptr, const QString &questionListName = "Default Question List");

    ChallengeQuestionManager getQuestionManager() const;
    void setQuestionManager(const ChallengeQuestionManager &value);

private slots:
    void onCategoryChanged(int index);
    void onAddQuestion();
    void onRemoveQuestion();

    void onSaveClicked();
    void onLoadClicked();

    void onApplyClicked();
    void onCloseClicked();
private:
    Ui::ChallengeQuestionManagerDialog ui;
    ChallengeQuestionManager questionManager;

    void refreshQuestionsList();

signals:
    void applyRequested(const ChallengeQuestionManager &manager, const QString questionListName);
};

#endif // CHALLENGEQUESTIONMANAGERDIALOG_H
