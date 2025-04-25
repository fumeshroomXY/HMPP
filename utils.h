#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QList>
#include "cscrtoolchallengerquestion.h"

/**
 * @brief the comment template
 *
 *
 *
 */

class Utils
{
public:
    Utils() = delete;

    static QString sanitizeFileName(const QString &fileName);
    static QString getLeftSubstring(const QString &str, const QString &targetSeperator);
    static CodeElements extractCppElements(const QString &line);
};

#endif // UTILS_H
