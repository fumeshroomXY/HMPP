#ifndef MANAGEPROPERTYSETDIALOG_H
#define MANAGEPROPERTYSETDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>

namespace Ui {
class ManagePropertySetDialog;
}

class ManagePropertySetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagePropertySetDialog(QWidget *parent = 0);
    ~ManagePropertySetDialog();

private slots:
    void showRuleDescript(QTreeWidgetItem *, int);
private:
    Ui::ManagePropertySetDialog *ui;
};

#endif // MANAGEPROPERTYSETDIALOG_H
