#ifndef RULEDESCRIPTDIALOG_H
#define RULEDESCRIPTDIALOG_H

#include <QDialog>

namespace Ui {
class RuleDescriptDialog;
}

class RuleDescriptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RuleDescriptDialog(QWidget *parent = 0);
    ~RuleDescriptDialog();

private:
    Ui::RuleDescriptDialog *ui;
};

#endif // RULEDESCRIPTDIALOG_H
