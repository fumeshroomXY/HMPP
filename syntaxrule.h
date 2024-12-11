#ifndef SYNTAXRULE_H
#define SYNTAXRULE_H


#include <QString>
#include <QList>
#include <QRegExp>
#include <QRegularExpression>


//定义C++的基础数据类型
extern const QStringList basicType;

//
extern const QRegExp basicVarPattern;
extern const QString basicVarStr;

//定义全局变量的规则
extern const QString globalVarStr;
extern const QRegExp globalVarPattern;

//定义变量在类的声明体中的规则
extern const QString classVarInHeaderStr;
extern const QRegExp classVarInHeaderPattern;

//定义基础和复合变量的命名规则
extern const QRegExp varPattern;
extern const QString varStr;

//定义函数的命名规则
extern const QRegExp definedMethodPattern;
extern const QString definedMethodStr;

//定义函数在类的声明体中的规则
extern const QString classMethodInHeaderStr;
extern const QRegExp classMethodInHeaderPattern;

//定义类的命名规则
extern const QString classStr;
extern const QRegExp classPattern;

//定义类调用成员变量的规则
extern const QString classVarStr;
extern const QRegExp classVarPattern;

//定义类调用成员变量并赋值的规则
extern const QString classVarAssignStr;
extern const QRegExp classVarAssignPattern;

//定义类调用成员函数的规则
extern const QString classMethodStr;
extern const QRegExp classMethodPattern;

//定义类调用成员函数时，函数参数嵌套调用成员函数的规则
extern const QString classMethodEmbededCallStr;
extern const QRegExp classMethodEmbededCallPattern;

//定义类的构造函数规则
extern const QString classConstructStr1;   //比如 Student* stu("name", age)
extern const QRegExp classConstructPattern1;

extern const QString classConstructStr2;   //比如 Student stu("name", age)
extern const QRegExp classConstructPattern2;

//定义类的构造函数完整函数体的规则
extern const QString classCtrMethodStr;
extern const QRegExp classCtrMethodPattern;

//自然语言描述的规格匹配规则
//extern const QRegExp informalSpecPattern;
extern const QRegularExpression informalSpecPattern;

//自然语言规格书的章节号匹配规则
extern const QRegularExpression informalSpecSectionPattern;

//定义C++包含头文件的语句规则
extern const QString includeHeaderStr;
extern const QRegExp includeHeaderPattern;

//规则集
extern const QList<QRegExp> syntaxRuleList;

//未指定的类型或类名
extern const QString UNSPECIFIED;

//除0异常
extern const QRegExp divisionByZeroPattern;

// 驼峰命名法
// lower用作函数命名
// upper用作类命名
QString toLowerCamelCase(const QString& target);
QString toUpperCamelCase(const QString& target);


#endif // SYNTAXRULE_H

