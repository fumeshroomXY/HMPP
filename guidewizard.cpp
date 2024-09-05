#include "guidewizard.h"
#include <QtWidgets>

GuideWizard::GuideWizard(QWidget *parent)
    : QWizard(parent)
{
    setPage(Page_Intro, new IntroPage);
    setPage(Page_CreateNewProject, new CreateProjectPage);
    setPage(Page_OpenExistingProject, new OpenProjectPage);
    setPage(Page_Conclusion, new ConclusionPage);

    setStartId(Page_Intro);

#ifndef Q_OS_MAC

    setWizardStyle(ModernStyle);
#endif

    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/toolbar_images/hmpp.png"));

    setWindowTitle(tr("HMPP Tool Guide"));
}

void GuideWizard::done(int result)
{
    if (result == QDialog::Accepted) {
        createNewFlag = hasVisitedPage(Page_CreateNewProject);
    }
    QWizard::done(result);
}

void GuideWizard::showHelp()
{
    static QString lastHelpMessage;

    QString message;

    switch (currentId()) {
    case Page_Intro:
        message = tr("The decision you make here will affect which page you "
                     "get to see next.");
        break;
    case Page_CreateNewProject:
        message = tr("Create a new project and develop it in HMPP tool.");
        break;
    case Page_OpenExistingProject:
        message = tr("Open an existing project and continue developing it"
                     "in HMPP tool.");
        break;
    case Page_Conclusion:
        message = tr("The HMPP tool is developed by XiaYing in the Dependable"
                     "System in Hiroshima University.");
        break;
    default:
        message = tr("This help is likely not to be of any help.");
    }

    if (lastHelpMessage == message)
        message = tr("Sorry, I already gave what help I could. "
                     "Maybe you should try asking a human?");

    QMessageBox::information(this, tr("HMPP Guide Help"), message);

    lastHelpMessage = message;
}


IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Introduction"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/toolbar_images/watermark.png"));

    topLabel = new QLabel(tr("This wizard will guide you to create your own "
                             "new project or open an existing project "
                             "in the HMPP tool."));
    topLabel->setWordWrap(true);

    createNewProjectButton = new QRadioButton(tr("&Create a new project"));
    openExistingProjectButton = new QRadioButton(tr("&Open an existing project"));
    createNewProjectButton->setChecked(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topLabel);
    layout->addWidget(createNewProjectButton);
    layout->addWidget(openExistingProjectButton);
    setLayout(layout);
}

int IntroPage::nextId() const
{
    if (createNewProjectButton->isChecked()) {
        return GuideWizard::Page_CreateNewProject;
    } else {
        return GuideWizard::Page_OpenExistingProject;
    }
}


CreateProjectPage::CreateProjectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Create a new project"));
    projectNameLabel = new QLabel(tr("Project &Name:"));
    projectNameLineEdit = new QLineEdit;
    projectNameLabel->setBuddy(projectNameLineEdit);

    projectPathLabel = new QLabel(tr("Project &Directory:"));
    projectPathLineEdit = new QLineEdit;
    projectPathLineEdit->setReadOnly(true);
    projectPathLabel->setBuddy(projectPathLineEdit);

    projectSpecPathLabel = new QLabel(tr("S&pecification Directory:"));
    projectSpecPathEdit = new QLineEdit;
    projectSpecPathEdit->setReadOnly(true);
    projectSpecPathLabel->setBuddy(projectSpecPathEdit);

    QPixmap pixmap(":/images/toolbar_images/folder.png");
    QPixmap scaledPixmap = pixmap.scaled(16, 16, Qt::KeepAspectRatio); // Adjust the size as needed

    // Set the icon on the button
    QIcon icon(scaledPixmap);
    openDirectoryButton = new QPushButton;
    openDirectoryButton->setIcon(icon);
    openDirectoryButton->resize(16, 16);

    connect(openDirectoryButton, &QPushButton::clicked, this, &CreateProjectPage::getProjectDirectory);

    openSpecButton = new QPushButton;
    openSpecButton->setIcon(icon);
    openSpecButton->resize(16, 16);
    connect(openSpecButton, &QPushButton::clicked, this, &CreateProjectPage::getSpecDirectory);

    targetLanguageLabel = new QLabel(tr("Target &Language:"));
    targetLanguageBox = new QComboBox;
    targetLanguageBox->addItem("C++");
    targetLanguageBox->addItem("Java");
    targetLanguageBox->addItem("C#");

    registerField("project name*", projectNameLineEdit);
    registerField("project path*", projectPathLineEdit);
    registerField("specification path", projectSpecPathEdit);
    //registerField("target language*", targetLanguageBox);
    registerField("target language*", targetLanguageBox, "currentText", SIGNAL(currentIndexChanged(int)));


    QGridLayout* layout = new QGridLayout;
    layout->addWidget(projectNameLabel, 0, 0);
    layout->addWidget(projectNameLineEdit, 0, 1);
    layout->addWidget(projectPathLabel, 1, 0);
    layout->addWidget(projectPathLineEdit, 1, 1);
    layout->addWidget(openDirectoryButton, 1, 2);

    layout->addWidget(projectSpecPathLabel, 2, 0);
    layout->addWidget(projectSpecPathEdit, 2, 1);
    layout->addWidget(openSpecButton, 2, 2);
    layout->addWidget(targetLanguageLabel, 3, 0);
    layout->addWidget(targetLanguageBox, 3, 1);
    setLayout(layout);

}

int CreateProjectPage::nextId() const
{
    return GuideWizard::Page_Conclusion;
}

bool CreateProjectPage::validatePage()
{
    if (projectNameLineEdit->text().isEmpty()) {
        qDebug() << "projectName is empty.";
        QMessageBox::warning(this, "Input Error", "Please enter your project name before proceeding.");
        return false; // Prevent going to the next page
    }

    if (projectPathLineEdit->text().isEmpty()) {
        qDebug() << "projectPath is empty";
        QMessageBox::warning(this, "Input Error", "Please select your project directory before proceeding.");
        return false; // Prevent going to the next page
    }
    return true; // Allow going to the next page
}

bool CreateProjectPage::isComplete() const
{
    return targetLanguageBox->currentIndex() >= 0 && !projectNameLineEdit->text().isEmpty()
            && !projectPathLineEdit->text().isEmpty();
}

void CreateProjectPage::getProjectDirectory()
{
    const QString proDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::currentPath(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!proDir.isEmpty()){
        projectPathLineEdit->setText(proDir);
    }

}

void CreateProjectPage::getSpecDirectory()
{
    const QString filePath = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if(!filePath.isEmpty()){
        projectSpecPathEdit->setText(filePath);
    }
}


OpenProjectPage::OpenProjectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Open an existing project"));
    projectPathLabel = new QLabel(tr("Project &Path:"));
    projectPathLineEdit = new QLineEdit;
    projectPathLineEdit->setReadOnly(true);
    projectPathLabel->setBuddy(projectPathLineEdit);

    projectNameLineEdit = new QLineEdit;

    projectSpecPathLabel = new QLabel(tr("S&pecification Path:"));
    projectSpecPathEdit = new QLineEdit;
    projectSpecPathEdit->setReadOnly(true);
    projectSpecPathLabel->setBuddy(projectSpecPathEdit);
    targetLanguageLineEdit = new QLineEdit;

    QPixmap pixmap(":/images/toolbar_images/folder.png");
    QPixmap scaledPixmap = pixmap.scaled(16, 16, Qt::KeepAspectRatio); // Adjust the size as needed

    // Set the icon on the button
    QIcon icon(scaledPixmap);
    openFileButton = new QPushButton;
    openFileButton->setIcon(icon);
    openFileButton->resize(16, 16);

//    registerField("project name*", projectNameLineEdit, "text", SIGNAL(textChanged(QString)));
//    registerField("project path*", projectPathLineEdit, "text", SIGNAL(textChanged(QString)));
//    registerField("target language*", targetLanguageLineEdit, "text", SIGNAL(textChanged(QString)));

    targetLanguageLineEdit->setText("C++");

    connect(openFileButton, &QPushButton::clicked, this, &OpenProjectPage::getProjectDirectory);

    openSpecButton = new QPushButton;
    openSpecButton->setIcon(icon);
    openSpecButton->resize(16, 16);
    connect(openSpecButton, &QPushButton::clicked, this, &OpenProjectPage::getSpecDirectory);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(projectPathLabel, 0, 0);
    layout->addWidget(projectPathLineEdit, 0, 1);
    layout->addWidget(openFileButton, 0, 2);
    layout->addWidget(projectSpecPathLabel, 1, 0);
    layout->addWidget(projectSpecPathEdit, 1, 1);
    layout->addWidget(openSpecButton, 1, 2);
    setLayout(layout);
}

int OpenProjectPage::nextId() const
{
    return GuideWizard::Page_Conclusion;
}

bool OpenProjectPage::validatePage()
{
    if (projectPathLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select your project file before proceeding.");
        return false; // Prevent going to the next page
    }
    return true;
}

void OpenProjectPage::getProjectDirectory()
{
    const QString filePath = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if (!filePath.isEmpty()){
        QFileInfo fileInfo(filePath);
        QString directoryPath = fileInfo.absolutePath();
        QString fileName = fileInfo.fileName();

        qDebug() << "path:" << directoryPath;
        qDebug() << "file:" << fileName;

        projectPathLineEdit->setText(directoryPath);
        projectNameLineEdit->setText(fileName);
        targetLanguageLineEdit->setText("C++");

        setField("project name", projectNameLineEdit->text());
        setField("project path", projectPathLineEdit->text());
        setField("target language", targetLanguageLineEdit->text());
    }
}

void OpenProjectPage::getSpecDirectory()
{
    const QString filePath = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if (!filePath.isEmpty()){
        projectSpecPathEdit->setText(filePath);

        setField("specification path", projectSpecPathEdit->text());
    }
}

ConclusionPage::ConclusionPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Welcome to HMPP tool"));
    setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/toolbar_images/watermark.png"));

    label = new QLabel(tr("You are going to working on the following project:"));
    projectName = new QLabel;
    projectPath = new QLabel;
    targetLanguage = new QLabel;
    specPath = new QLabel;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(projectName);
    layout->addWidget(projectPath);
    layout->addWidget(specPath);
    layout->addWidget(targetLanguage);
    setLayout(layout);
}


int ConclusionPage::nextId() const
{
    return -1;
}

void ConclusionPage::initializePage()
{
    QString proName = field("project name").toString();
    qDebug() << "proName:" << proName;
    QString proPath = field("project path").toString();
    qDebug() << "proPath:" << proPath;
    QString targetLang = field("target language").toString();
    qDebug() << "target Lang:" << targetLang;

    projectName->setText("Project Name: " + field("project name").toString());
    projectPath->setText("Project Directory: " + field("project path").toString());
    targetLanguage->setText("Target Language: " + field("target language").toString());
    specPath->setText("Specification Directory: " + field("specification path").toString());
}
