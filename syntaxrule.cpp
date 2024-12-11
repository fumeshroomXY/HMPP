#include <syntaxrule.h>


//如何让程序不匹配引号或者注释里的东西


const QStringList basicType = {"\\bint\\b", "\\bbool\\b", "\\bchar\\b",
                                     "\\bfloat\\b", "\\bdouble\\b", "\\bvoid\\b", "\\bstd::string\\b"};

//定义普通类型的临时变量
//连续定义的无法识别，比如int a = 0, b = 0;
//带作用域的无法识别，比如std::string a;
//第一行匹配基础类型
//第二行匹配*&
//第三行匹配变量名
//第四行匹配[]
//1类型，2*&，3变量名，4[]
const QString basicVarStr = "\\b(" + basicType.join("|") + ")"
                                                          "(\\*|&?)[^\\S\n]+"
                                                          "([A-Za-z_][A-Za-z0-9_]*)\\b"
                                                          "(\\[?\\]?)[^\\S\n]*[;\\):=,](?!:)";

const QRegExp basicVarPattern = QRegExp(basicVarStr);


const QString classVarInHeaderStr = "\\b([A-Za-z_][A-Za-z0-9_]*)"
                                    "(\\*|&?)[^\\S\n]+%1\\b"
                                    "(\\[?\\]?)[^\\S\n]*;";

const QRegExp classVarInHeaderPattern = QRegExp(classVarInHeaderStr);

//定义全局变量
//1类型，2*&，3变量名，4[]
const QString globalVarStr = "\\b([A-Za-z_][A-Za-z0-9_]*)"
                             "(\\*|&?)[^\\S\n]+"
                             "([A-Za-z_][A-Za-z0-9_]*)"
                             "(\\[?\\]?)[^\\S\n]*[=;]";

const QRegExp globalVarPattern = QRegExp(globalVarStr);

//定义基础和复合变量一起扫描的情况
const QString varStr = "\\b([A-Za-z_][A-Za-z0-9_]*)[^\\S\n]*"
                       "(\\*|&?)[^\\S\n]*([A-Za-z_][A-Za-z0-9_]*)";

const QRegExp varPattern = QRegExp(varStr);

//定义类成员函数或全局函数
//第一行匹配返回类型，*或&
//第二行匹配类名::或不匹配
//第三行匹配函数名
//第四行匹配(),和其中的参数列表，然后匹配{
//1返回类型，2*&，3类名，4函数名，5参数列表
const QString definedMethodStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\*|&?)[^\\S\n]+"
                                 "([A-Z][A-Za-z0-9_]*::)?"
                                 "([A-Za-z_][A-Za-z0-9_]+)\\b"
                                 "\\(([^\\)]*)\\)\\s*\\{";

const QRegExp definedMethodPattern = QRegExp(definedMethodStr);

const QString classMethodInHeaderStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\*|&?)[^\\S\n]+%1\\b"
                                 "\\(([^()]*)\\);";

const QRegExp classMethodInHeaderPattern = QRegExp(classMethodInHeaderStr);


//1类名，2类名，3参数列表，4形参，5类成员变量
const QString classCtrMethodStr = "\\b([A-Z][A-Za-z0-9_]*)::([A-Z][A-Za-z0-9_]*)\\b"
                                  "\\(([^\\)]*)\\)\\s*:\\s*"
                                  "(([A-Za-z_][A-Za-z0-9_]*)\\(([A-Za-z_][A-Za-z0-9_]*)\\),*\\s*)*"
                                  "\\s*\\{";

const QRegExp classCtrMethodPattern = QRegExp(classCtrMethodStr);


//有个问题，类的构造函数定义  Student stu("name") 无法识别
//QTextDocument* parent = nullptr, *位置偏差的无法识别
//const HighlightingRule& rule, 加const, 或&, 无法识别
//QVector<HighlightingRule> highlightingRules;  这样的无法识别
//1类名，2*&，3变量名
const QString classStr = "\\b([A-Z][A-Za-z0-9]*)(\\*|&?)[^\\S\n]+([A-Za-z_][A-Za-z0-9_]*)\\b[^\\S\n]*[;\\(\\):=,]";

const QRegExp classPattern = QRegExp(classStr);

//1类名，2.->，3成员变量名
const QString classVarStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\.|->)"
                            "([A-Za-z_][A-Za-z0-9_]*)\\b(?!\\()";

const QRegExp classVarPattern = QRegExp(classVarStr);


// 无法匹配rule.pattern.globalMatch()中后面的pattern
//1类名，2.->，3成员变量名，4[]，5赋值表达式
const QString classVarAssignStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\.|->)"
                            "([A-Za-z_][A-Za-z0-9_]*)\\b(\\[?\\]?)"
                            "[^\\S\n]*=[^\\S\n]*([^;]*);";

const QRegExp classVarAssignPattern = QRegExp(classVarAssignStr);



//1类的变量名，2.->，3成员函数名，4参数列表
const QString classMethodStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\.|->)([A-Za-z_][A-Za-z0-9_]+)\\(([^()]*)\\)";

const QRegExp classMethodPattern = QRegExp(classMethodStr);

//1类的变量名，2.->，3成员函数名，4参数列表（嵌套调用）
const QString classMethodEmbededCallStr = "\\b([A-Za-z_][A-Za-z0-9_]*)(\\.|->)([A-Za-z_][A-Za-z0-9_]+)\\(([^;]*);";
const QRegExp classMethodEmbededCallPattern = QRegExp(classMethodEmbededCallStr);

// 类似 Student* stu = new Student("name", age)
// 1类的变量名，2*，3变量名，4类名，5参数列表
const QString classConstructStr1 = "\\b([A-Z][A-Za-z0-9]*)(\\*)"
                                   "[^\\S\n]+([A-Za-z_][A-Za-z0-9_]*)[^\\S\n]*"
                                   "[=][^\\S\n]*\\bnew\\b[^\\S\n]+([A-Z][A-Za-z0-9]*)"
                                   "\\(([^()]*)\\)";

const QRegExp classConstructPattern1 = QRegExp(classConstructStr1);

//类似 Student stu("name", age)
//1类名，2变量名，3参数列表
const QString classConstructStr2 = "\\b([A-Z][A-Za-z0-9]*)[^\\S\n]+"
                                   "([A-Za-z_][A-Za-z0-9_]*)\\(([^()]*)\\)";
const QRegExp classConstructPattern2 = QRegExp(classConstructStr2);

//1章节号，2自然语言描述
//const QRegExp informalSpecPattern = QRegExp("/\\*\\s*(\\d+\\.\\d+)\\s+(.*)\\*/");
//const QRegExp informalSpecPattern = QRegExp("/\\*\\s*(\\d+(?:\\.\\d+){0,3}).*?\\*/");
const QRegularExpression informalSpecPattern("\\/\\*\\s*(\\d+(?:\\.\\d+){0,3}).*?\\*\\/",
                                             QRegularExpression::DotMatchesEverythingOption);

const QRegularExpression informalSpecSectionPattern("((?:\\d+\\.){1,3}\\d*)\\s+", QRegularExpression::DotMatchesEverythingOption);


//规则集中的规则必须按顺序定义
const QList<QRegExp> syntaxRuleList = {basicVarPattern, definedMethodPattern, classCtrMethodPattern, classVarPattern,
                                       classPattern, classVarAssignPattern, classMethodPattern, classMethodEmbededCallPattern};

const QString UNSPECIFIED = "UNSPECIFIED";

const QRegExp divisionByZeroPattern = QRegExp("([a-zA-Z_][a-zA-Z0-9_]*)\\s*/\\s*([a-zA-Z_][a-zA-Z0-9_]*)");

QString toLowerCamelCase(const QString &target)
{
    QStringList words = target.split(" ", QString::SkipEmptyParts);
    if (words.isEmpty()) return "";

    // Make the first word lowercase
    QString lowerCamel = words[0].toLower();

    // Capitalize the first letter of the remaining words
    for (int i = 1; i < words.size(); ++i) {
        lowerCamel += words[i].left(1).toUpper() + words[i].mid(1).toLower();
    }
    return lowerCamel;
}

QString toUpperCamelCase(const QString &target)
{
    QStringList words = target.split(" ", QString::SkipEmptyParts);
    if (words.isEmpty()) return "";

    QString upperCamel;
    // Capitalize the first letter of every word
    for (const QString &word : words) {
        upperCamel += word.left(1).toUpper() + word.mid(1).toLower();
    }
    return upperCamel;
}
