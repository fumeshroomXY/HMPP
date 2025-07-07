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
    QString processedLine = line;
    int commentIndex = processedLine.indexOf("//");
    if (commentIndex != -1) {
        processedLine = processedLine.left(commentIndex);
    }

    CodeElements result;
    QStringList keywordList = {
        "case", "class", "struct", "namespace",
        "int", "float", "double", "char", "bool", "void", "public", "private", "protected",
        "new", "delete", "static", "const", "inline", "virtual", "override"
    };

    QStringList CppkeywordList = {
        "namespace", "template", "typename",
        "explicit", "mutable", "final", "friend",
        "public", "private", "protected",
        "new", "delete", "static", "const", "inline", "virtual", "override"
    };

    // C++ keyword list (add more as needed)
    QStringList loopKeywordList = {
        "for", "while"
    };

    QStringList controlKeyWordList = {
        "break", "return", "continue", "switch"
    };

    QStringList conditionKeywordList = {
        "if", "else"
    };

    QStringList exceptionHandlingKeywordList = {"try", "catch", "throw"};

    QStringList outputKeywordList = {"write", "cout", "out", "cerr", "clog"};

    QStringList inputKeywordList = {"read", "in", "cin", "getline"};

    // Assignment operators
    QStringList assignmentList = { "=", "+=", "-=", "*=", "/=", "%=" };

    // Match all tokens
    QRegularExpression tokenRegex(R"([\w_]+|\S)");
    auto tokens = tokenRegex.globalMatch(processedLine);

    QStringList tokenList;
    while (tokens.hasNext()) {
        tokenList << tokens.next().captured();
    }

    // Regular expressions for constants
    QRegularExpression numberRegex(R"(^\d+(\.\d+)?$)"); // Matches integers and floating point numbers
    QRegularExpression stringLiteralRegex(R"(^".*"$)");  // Matches string literals

    for (int i = 0; i < tokenList.size(); ++i) {
        QString tok = tokenList[i];

        // Assignment detection
        if (assignmentList.contains(tok)) {
            result.assignmentOps << tok;
            continue;
        }

        // Keyword detection
        if (loopKeywordList.contains(tok)) {
            result.loopKeywords << tok;
            continue;
        }

        if (controlKeyWordList.contains(tok)) {
            result.controlKeywords << tok;
            continue;
        }

        if (conditionKeywordList.contains(tok)) {
            result.conditionKeywords << tok;
            continue;
        }

        if (outputKeywordList.contains(tok)) {
            result.outputKeywords << tok;
            continue;
        }

        if (inputKeywordList.contains(tok)) {
            result.inputKeywords << tok;
            continue;
        }

        if (exceptionHandlingKeywordList.contains(tok)) {
            result.exceptionHandlingKeywords << tok;
            continue;
        }

        if (CppkeywordList.contains(tok)) {
            result.uniqueKeywords << tok;
            continue;
        }

        // Function detection (look ahead for "(")
        if (i + 1 < tokenList.size() && tokenList[i + 1] == "(" && !keywordList.contains(tok)) {
            if(!result.functions.contains(tok)) result.functions << tok;
            continue;
        }

        if(QRegularExpression(R"([a-zA-Z_][a-zA-Z0-9_]*)").match(tok).hasMatch() && !keywordList.contains(tok)){
            // Class detection: class X or new X
            if ((i > 0 && tokenList[i - 1] == "class") ||
                (i > 0 && tokenList[i - 1] == "new")) {
                 if(!result.classes.contains(tok)) result.classes << tok;
                continue;
            }
            // Variable detection;
            else{
                 if(!result.variables.contains(tok)) result.variables << tok;
                continue;
            }
        }

//        // Variable detection: primitiveType varName [= ...];
//        if (i > 0 && keywordList.contains(tokenList[i - 1]) &&
//            QRegularExpression(R"([a-zA-Z_][a-zA-Z0-9_]*)").match(tok).hasMatch()) {
//            result.variables << tok;
//        }

        // Constant detection: numeric constants or string literals
        if (numberRegex.match(tok).hasMatch()) {
             if(!result.constants.contains(tok)) result.constants << tok;  // Add number as a constant
            continue;
        } else if (stringLiteralRegex.match(tok).hasMatch()) {
             if(!result.constants.contains(tok)) result.constants << tok;  // Add string literal as a constant
            continue;
        }
    }

    return result;
}
