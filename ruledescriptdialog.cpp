#include "ruledescriptdialog.h"
#include "ui_ruledescriptdialog.h"

RuleDescriptDialog::RuleDescriptDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RuleDescriptDialog)
{
    ui->setupUi(this);
}

RuleDescriptDialog::~RuleDescriptDialog()
{
    delete ui;
}
