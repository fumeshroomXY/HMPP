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
    const QString apiKey = "";

signals:
    void replyIsReady(QString reply);

};

#endif // CHATGPTCLIENT_H
