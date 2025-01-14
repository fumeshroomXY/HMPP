#include "managepropertysetdialog.h"
#include "ui_managepropertysetdialog.h"
#include "ruledescriptdialog.h"
#include "screenfactor.h"

ManagePropertySetDialog::ManagePropertySetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagePropertySetDialog)
{
    ui->setupUi(this);

    connect(ui->ruleTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(showRuleDescript(QTreeWidgetItem*,int)));
}

ManagePropertySetDialog::~ManagePropertySetDialog()
{
    delete ui;
}

void ManagePropertySetDialog::showRuleDescript(QTreeWidgetItem*, int)
{
    RuleDescriptDialog *ruleDescript = new RuleDescriptDialog(this);
    ScreenFactor factor;
    auto screenFactor = factor.getScreenFactor();
    ruleDescript->resize(ruleDescript->width() * screenFactor, ruleDescript->height() * screenFactor);
    ruleDescript->show();
}
