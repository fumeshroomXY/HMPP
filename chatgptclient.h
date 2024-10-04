#ifndef CHATGPTCLIENT_H
#define CHATGPTCLIENT_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>


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
    const QString apiKey = "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"; // 替换为你的API密钥
};

#endif // CHATGPTCLIENT_H
