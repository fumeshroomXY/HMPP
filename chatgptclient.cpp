#include "chatgptclient.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ChatgptClient::ChatgptClient(QWidget *parent)
    : QWidget(parent), networkManager(new QNetworkAccessManager(this)) {

    connect(networkManager, &QNetworkAccessManager::finished, this, &ChatgptClient::onReplyFinished);
}



void ChatgptClient::onReplyFinished(QNetworkReply* reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(response_data);
        QJsonObject jsonObj = responseDoc.object();  // 获取根对象
        QJsonArray choicesArray = jsonObj["choices"].toArray();  // 获取 "choices" 数组
        QJsonObject firstChoice = choicesArray[0].toObject();  // 取第一个元素
        QString chatGptReply = firstChoice["message"].toObject()["content"].toString();  // 获取"message"的"content"字段
        chatgptReply = "ChatGPT: " + chatGptReply;
    } else {
        chatgptReply = "Error: " + reply->errorString();
    }
    reply->deleteLater();
}

void ChatgptClient::sendUserMessage(const QString &value)
{
    userInput = value;
    QString userQuestion = userInput;

    QNetworkRequest request(QUrl("https://api.openai.com/v1/chat/completions"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + apiKey.toUtf8());

    QJsonObject json;
    json["model"] = "gpt-3.5-turbo";
    json["messages"] = QJsonArray::fromStringList({ "role", "user", "content", userQuestion });

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());
    connect(reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), [reply](QNetworkReply::NetworkError code) {
        qWarning() << "Network error occurred:" << code << reply->errorString();
    });
}

QString ChatgptClient::getChatgptReply() const
{
    return chatgptReply;
}
