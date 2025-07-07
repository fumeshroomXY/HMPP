#include "challengequestionmanagerdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>


ChallengeQuestionManagerDialog::ChallengeQuestionManagerDialog(QWidget *parent, const QString &questionListName) : QDialog(parent)
{
    ui.setupUi(this);
    // Optionally load saved questions here
    // m_questionManager.loadFromJson("questions.json");

    // Populate category combo box
    ui.lineEditQuestionList->setText(questionListName);
    ui.comboBoxCategory->addItems(questionManager.categories());

    connect(ui.comboBoxCategory, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onCategoryChanged(int)));

    connect(ui.buttonAddQuestion, &QPushButton::clicked,
            this, &ChallengeQuestionManagerDialog::onAddQuestion);

    connect(ui.buttonRemoveQuestion, &QPushButton::clicked,
            this, &ChallengeQuestionManagerDialog::onRemoveQuestion);

    connect(ui.buttonLoad, &QPushButton::clicked, this, &ChallengeQuestionManagerDialog::onLoadClicked);
    connect(ui.buttonSave, &QPushButton::clicked, this, &ChallengeQuestionManagerDialog::onSaveClicked);

    connect(ui.buttonApply, &QPushButton::clicked, this, &ChallengeQuestionManagerDialog::onApplyClicked);
    connect(ui.buttonClose, &QPushButton::clicked, this, &ChallengeQuestionManagerDialog::onCloseClicked);

    // Show questions for first category by default
    if (!questionManager.categories().isEmpty()) {
        ui.comboBoxCategory->setCurrentIndex(0);
        refreshQuestionsList();
    }
}

void ChallengeQuestionManagerDialog::onCategoryChanged(int index)
{
    refreshQuestionsList();
}

void ChallengeQuestionManagerDialog::onAddQuestion()
{
    QString category = ui.comboBoxCategory->currentText();
    bool ok;
    QString newQuestion = QInputDialog::getText(this, "Add Question",
                                                "Enter your question:", QLineEdit::Normal,
                                                QString(), &ok);
    if (ok && !newQuestion.isEmpty()) {
        questionManager.addQuestion(category, newQuestion);
        ui.listWidgetQuestion->addItem(newQuestion);
    }
}

void ChallengeQuestionManagerDialog::onRemoveQuestion()
{
    QListWidgetItem *item = ui.listWidgetQuestion->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Remove Question", "Please select a question to remove.");
        return;
    }
    QString category = ui.comboBoxCategory->currentText();
    QString question = item->text();

    questionManager.removeQuestion(category, question);
    delete item;
}

void ChallengeQuestionManagerDialog::refreshQuestionsList()
{
    ui.listWidgetQuestion->clear();
    QString category = ui.comboBoxCategory->currentText();
    QStringList questions = questionManager.questionsByCategory(category);
    ui.listWidgetQuestion->addItems(questions);
}

void ChallengeQuestionManagerDialog::onLoadClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
        tr("Open Challenge Question List File"), QString(), tr("JSON Files (*.json);;All Files (*)"));
    if (filePath.isEmpty())
        return;

    if (questionManager.loadFromJson(filePath)) {
        QFileInfo fi(filePath);
        QString baseName = fi.baseName(); // file name without extension
        ui.lineEditQuestionList->setText(baseName);

        // Update UI categories & questions list
        ui.comboBoxCategory->clear();
        ui.comboBoxCategory->addItems(questionManager.categories());
        if (!questionManager.categories().isEmpty()) {
            ui.comboBoxCategory->setCurrentIndex(0);
            refreshQuestionsList();
        }
        QMessageBox::information(this, tr("Load"), tr("Question List loaded successfully."));
    } else {
        QMessageBox::warning(this, tr("Load"), tr("Failed to load questions from file."));
    }
}

void ChallengeQuestionManagerDialog::onApplyClicked()
{
    emit applyRequested(questionManager, ui.lineEditQuestionList->text());

    // Optionally close dialog after apply
    accept();  // or close();
}

void ChallengeQuestionManagerDialog::onCloseClicked()
{
    reject();  // or close();
}

ChallengeQuestionManager ChallengeQuestionManagerDialog::getQuestionManager() const
{
    return questionManager;
}

void ChallengeQuestionManagerDialog::setQuestionManager(const ChallengeQuestionManager &value)
{
    questionManager = value;
    refreshQuestionsList();
}

void ChallengeQuestionManagerDialog::onSaveClicked()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    tr("Save Challenge Question List File"), QString(), tr("JSON Files (*.json);;All Files (*)"));
    if (filePath.isEmpty())
        return;

    if (!filePath.endsWith(".json", Qt::CaseInsensitive))
        filePath += ".json";

    if (questionManager.saveToJson(filePath)) {
        QMessageBox::information(this, tr("Save"), tr("Question List saved successfully."));
    } else {
        QMessageBox::warning(this, tr("Save"), tr("Failed to save questions to file."));
    }
}


