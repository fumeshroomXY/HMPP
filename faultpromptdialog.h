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
    explicit CustomButton(QWidget *parent = nullptr) : QPushButton(parent){faultLine = -1;}
    int getFaultLine(){return faultLine;}
    void setFaultLine(int lineNumber) {faultLine = lineNumber;}

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    int faultLine;

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

public slots:
    void okButtonClicked();
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
    void okclicked();
};

#endif // FAULTPROMPTDIALOG_H
