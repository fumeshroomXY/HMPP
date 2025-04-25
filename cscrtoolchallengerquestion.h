#ifndef CSCRTOOLCHALLENGERQUESTION_H
#define CSCRTOOLCHALLENGERQUESTION_H

/**
 * @brief about the challenge questions when reviewing code
 */

struct ExpressionPatternFlags {
    bool hasUppercaseWord = false;
    bool hasLowercaseWord = false;
    bool containsIfElse = false;
    bool containsWhileFor = false;
    bool containsTryCatch = false;
    bool containsEqualsExpression = false;
    bool isOther = false;
};

struct CodeElements {
    QStringList functions;
    QStringList variables;
    QStringList classes;
    QStringList loopKeywords;
    QStringList conditionKeywords;
    QStringList exceptionHandlingKeywords;
    QStringList constants;
    QStringList assignmentOps;
};

const QStringList classNameQuestions = {"What is the purpose of this class?",
                                       "Why is it necessary for your system?"};
const QStringList methodNameQuestions = {"What does this method do?",
                                       "Can you describe how this method is fulfilled by sequential subfunctions?",
                                        "Why are all parameters of this method necessary?",
                                        "Is the type of return value of this method appropriate?",
                                        "Does this method fulfill the requirements correctly?"};
const QStringList varDeclarationQuestions = {"What data does this variable represent?",
                                       "Is the type used to declare this variable appropriate?",
                                            "Is there any problem without this variable?",
                                            "Is the initialization of this variable appropriate?"};
const QStringList constantQuestions = {"What does this constant mean?",
                                       "Is it used correctly?"};
const QStringList assignmentStatementQuestions = {"Is the variable of the assignment appropriate?",
                                       "What does the expression of the assignment represent?",
                                                 "Are all the variables, function invocations, and operators used in the expression appropriate?"};
const QStringList ifElseQuestions = {"What is the purpose of this conditional statement?",
                                       "What does the condition used in this statement mean when it is true?",
                                    "What does the condition used in this statement mean when it is false?",
                                    "Is there any mistake in the condition?"};
const QStringList whileLoopQuestions = {"What does this loop statement accomplish?",
                                       "What does the loop condition mean when it is true?",
                                       "What does the loop’s termination condition mean?",
                                       "Is there any mistake in the loop condition?"};
const QStringList forLoopQuestions = {"What is the purpose of the loop statement?",
                                       "Is the loop variable initialized correctly?",
                                     "Is the loop termination condition correct?",
                                     "Is the update expression correct?"};
const QStringList inputStatementQuestions = {"What data does this statement provide to the system?",
                                       "Is there any mistake in this statement?"};
const QStringList outputStatementQuestions = {"What data does this statement output outside the system?",
                                       "Is there any mistake in this statement?"};
const QStringList controlStatementQuestions = {"Why do you need this statement?",
                                       "Is every variable and constant correct in this statement?"};
const QStringList exceptionHandlingStatementQuestions = {"What exception does the try block throw?",
                                       "How is the exception handled by the catch block?"};
const QStringList syntacticalExpressionQuestions = {"What is its purpose?",
                                       "Why is it necessary?",
                                                   "Is there any mistake in using it?"};

#endif // CSCRTOOLCHALLENGERQUESTION_H
