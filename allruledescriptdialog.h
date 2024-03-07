#ifndef ALLRULEDESCRIPTDIALOG_H
#define ALLRULEDESCRIPTDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

namespace Ui {
class AllRuleDescriptDialog;
}

class AllRuleDescriptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AllRuleDescriptDialog(QWidget *parent = 0);
    ~AllRuleDescriptDialog();

private slots:
    void showRuleDescript(QTreeWidgetItem *, int);
    void showRuleDescript(QTableWidgetItem *);
private:
    Ui::AllRuleDescriptDialog *ui;
};

#endif // ALLRULEDESCRIPTDIALOG_H
