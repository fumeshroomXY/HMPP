#ifndef GUIDEWIZARD_H
#define GUIDEWIZARD_H

#include <QWizard>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QComboBox;
QT_END_NAMESPACE

/**
 * @brief the guide interface of the tool
 *
 * including open exisiting projects, create new projects, project name, project path, specification path
 *
 */

class GuideWizard : public QWizard
{
    Q_OBJECT
public:
    enum { Page_Intro, Page_CreateNewProject, Page_OpenExistingProject,
               Page_Conclusion };
    GuideWizard(QWidget *parent = 0);

    bool createNewFlag;

signals:
    void wizardFinished(bool createNewFlag, const QString &fileName, const QString &filePath, const QString &targetLang);

protected:
    void done(int result) override;

private slots:
    void showHelp();

};

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;

private:
    QLabel *topLabel;
    QRadioButton *createNewProjectButton;
    QRadioButton *openExistingProjectButton;
};


class CreateProjectPage : public QWizardPage
{
    Q_OBJECT

public:
    CreateProjectPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;

    bool validatePage() override;

    bool isComplete() const override;

private:
    QLabel *projectNameLabel;
    QLabel *projectPathLabel;
    QLabel *projectSpecPathLabel;
    QLabel *targetLanguageLabel;
    QPushButton* openDirectoryButton;
    QPushButton* openSpecButton;
    QLineEdit *projectNameLineEdit;
    QLineEdit *projectPathLineEdit;
    QLineEdit *projectSpecPathEdit;
    QComboBox *targetLanguageBox;

private slots:
    void getProjectDirectory();
    void getSpecDirectory();
};

class OpenProjectPage : public QWizardPage
{
    Q_OBJECT

public:
    OpenProjectPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;

    bool validatePage() override;

private:
    QLabel *projectPathLabel;
    QLineEdit *projectPathLineEdit;
    QLineEdit *projectNameLineEdit;
    QLabel *projectSpecPathLabel;
    QLineEdit *projectSpecPathEdit;
    QLineEdit *targetLanguageLineEdit;
    QPushButton *openFileButton;
    QPushButton *openSpecButton;

private slots:
    void getProjectDirectory();
    void getSpecDirectory();
};

class ConclusionPage : public QWizardPage
{
    Q_OBJECT

public:
    ConclusionPage(QWidget *parent = 0);

    int nextId() const Q_DECL_OVERRIDE;

    void initializePage() override;


private:
    QLabel *label;
    QLabel *projectName;
    QLabel *projectPath;
    QLabel *specPath;
    QLabel *targetLanguage;
};


#endif // GUIDEWIZARD_H
