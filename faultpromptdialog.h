#ifndef FAULTPROMPTDIALOG_H
#define FAULTPROMPTDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class FaultPromptDialog;
}

class CustomButton : public QPushButton {
    Q_OBJECT

public:
    explicit CustomButton(QWidget *parent = nullptr) : QPushButton(parent) {}

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

signals:
    void enterSignal();
    void leaveSignal();
};

class FaultPromptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FaultPromptDialog(QWidget *parent);
    ~FaultPromptDialog();

private slots:
    void showRuleDescript();
    void fixButtonClicked();
    void fixButtonEntered();
    void fixButtonReleased();
    void fixButtonLeft();
    void unfixButtonClicked();
private:
    Ui::FaultPromptDialog *ui;

signals:
    void clickedSignal();
    void enteredSignal();
    void releasedSignal();
    void leftSignal();
    void unfixSignal();
};

#endif // FAULTPROMPTDIALOG_H
