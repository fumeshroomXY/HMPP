#ifndef SELECTNEWCLASSDIALOG_H
#define SELECTNEWCLASSDIALOG_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
class SelectNewClassDialog;
}

class SelectNewClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNewClassDialog(const QStringList& newItems, const QStringList& preItems, QWidget *parent = 0);
    ~SelectNewClassDialog();

    //获取用户勾选的项
    QStringList checkedItems() const;

    //获取用户未勾选的项
    QStringList uncheckedItems() const;

private:
    Ui::SelectNewClassDialog *ui;
};

#endif // SELECTNEWCLASSDIALOG_H
