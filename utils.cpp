#include "utils.h"
#include <QRegularExpression>



QString Utils::sanitizeFileName(const QString &fileName)
{
    QString sanitized = fileName;

    // Remove invalid characters for file names
    sanitized.replace(QRegExp("[<>():\"/\\|?*]"), "_");  // Windows reserved characters
    sanitized.replace(" ", "_");  // Replace spaces with underscores

    return sanitized;

}

QString Utils::getLeftSubstring(const QString &str, const QString &targetSeperator) {
    int index = str.indexOf(targetSeperator);  // Find the position of '('
    return (index != -1) ? str.left(index) : str;  // Extract substring if '(' exists
}

CodeElements Utils::extractCppElements(const QString &line) {
    CodeElements result;

    QStringList keywordList = {
        "if", "else", "for", "while", "switch", "case", "return", "class", "struct", "namespace",
        "int", "float", "double", "char", "bool", "void", "public", "private", "protected",
        "new", "delete", "try", "catch", "static", "const", "inline", "virtual", "override"
    };

    // C++ keyword list (add more as needed)
    QStringList loopKeywordList = {
        "for", "while"
    };

    QStringList conditionKeywordList = {
        "if", "else"
    };

    QStringList exceptionHandlingKeywordList = {"try", "catch"};

    // Assignment operators
    QStringList assignmentList = { "=", "+=", "-=", "*=", "/=", "%=" };

    // Match all tokens
    QRegularExpression tokenRegex(R"([\w_]+|\S)");
    auto tokens = tokenRegex.globalMatch(line);

    QStringList tokenList;
    while (tokens.hasNext()) {
        tokenList << tokens.next().captured();
    }

    // Regular expressions for constants
    QRegularExpression numberRegex(R"(^\d+(\.\d+)?$)"); // Matches integers and floating point numbers
    QRegularExpression stringLiteralRegex(R"(^".*"$)");  // Matches string literals

    for (int i = 0; i < tokenList.size(); ++i) {
        QString tok = tokenList[i];

        // Function detection (look ahead for "(")
        if (i + 1 < tokenList.size() && tokenList[i + 1] == "(") {
            result.functions << tok;
        }

        // Assignment detection
        if (assignmentList.contains(tok)) {
            result.assignmentOps << tok;
        }

        // Keyword detection
        if (loopKeywordList.contains(tok)) {
            result.loopKeywords << tok;
        }

        if (conditionKeywordList.contains(tok)) {
            result.conditionKeywords << tok;
        }

        if (exceptionHandlingKeywordList.contains(tok)) {
            result.exceptionHandlingKeywords << tok;
        }

        // Class detection: class X or new X
        if ((i > 0 && tokenList[i - 1] == "class") ||
            (i > 0 && tokenList[i - 1] == "new")) {
            result.classes << tok;
        }

        // Variable detection: primitiveType varName [= ...];
        if (i > 0 && keywordList.contains(tokenList[i - 1]) &&
            QRegularExpression(R"([a-zA-Z_][a-zA-Z0-9_]*)").match(tok).hasMatch()) {
            result.variables << tok;
        }

        // Constant detection: numeric constants or string literals
        if (numberRegex.match(tok).hasMatch()) {
            result.constants << tok;  // Add number as a constant
        } else if (stringLiteralRegex.match(tok).hasMatch()) {
            result.constants << tok;  // Add string literal as a constant
        }
    }

    return result;
}
