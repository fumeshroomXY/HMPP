#ifndef CHATGPTCLIENT_H
#define CHATGPTCLIENT_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>

const QString fixCodePrompt = "You are a coding assistant that helps fix bugs in code. Please examine the following code and identify any potential bugs, errors, or improvements. For each issue, please return the details in the following JSON format:"
                              "{"
                              "bugLine: <line_number>,"
                              "bugName: <short_bug_name>,"
                              "bugNature: <type_of_bug (e.g., syntax, logic, performance, etc.)>"
                              "bugDescription: <detailed_description_of_the_bug>}"
                              "Please list all potential bugs in the code and provide suggestions for how to fix them."
                              "Please provide the output as a JSON array of bug objects."
                              "Here is the code I want you to analyze:";
/**
 * @brief the chaggpt client class
 * use the class to send and receive messages from ChatGPT
 */

class ChatgptClient : public QWidget
{
    Q_OBJECT
public:
    explicit ChatgptClient(QWidget *parent = 0);

    QString getChatgptReply() const;

    void sendUserMessage(const QString &value);

private slots:
    void onReplyFinished(QNetworkReply* reply);

private:
    QString chatgptReply;
    QString userInput;
    QNetworkAccessManager* networkManager;

    //由于加密原因，从本地文件读取apikey
    const QString apiKey = "";

signals:
    void replyIsReady(QString reply);

};

#endif // CHATGPTCLIENT_H
