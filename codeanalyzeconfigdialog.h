#ifndef CODEANALYZECONFIGDIALOG_H
#define CODEANALYZECONFIGDIALOG_H

#include <QDialog>
#include <QApplication>
#include <QTreeWidgetItem>
#include <QStandardItem>

namespace Ui {
class CodeAnalyzeConfigDialog;
}
class MainWindow;

class CodeAnalyzeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CodeAnalyzeConfigDialog(QWidget *parent = 0);
    ~CodeAnalyzeConfigDialog();

private slots:
    void managePropertySet();
    void showRuleDescript(QTreeWidgetItem *, int);
    void startAnalysis();
private:
    Ui::CodeAnalyzeConfigDialog *ui;
    MainWindow *m_parent;

protected:
    QStandardItemModel* Model;
    QStandardItem* Item1;
    QStandardItem* Item2;

    std::vector<QStandardItem*> Items;
};

#endif // CODEANALYZECONFIGDIALOG_H
