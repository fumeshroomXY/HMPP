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
                                        "Is the class name appropriate?",
                                       "Why is the class designed to possess the current structure?"
                                       };
const QStringList methodNameQuestions = {"What does this method do?",
                                       "Are all parameters of this method necessary?",
                                        "Are all parameters of this method enough?",
                                        "What is the purpose of this method invocation?",
                                        "Are all arguments provided correctly?"
                                        };
const QStringList varDeclarationQuestions = {"What data does this variable represent?",
                                       "Is the type used to declare this variable appropriate?",
                                            "Is the initialization of this variable appropriate?"
                                            };
const QStringList constantQuestions = {"What does this constant mean?",
                                       "Is it used correctly?"
                                      };
const QStringList assignmentStatementQuestions = {"What is the purpose of this assignment?",
                                                 "Are all the variables, function invocations, and operators used in the expression appropriate?"
                                                 };
const QStringList decisionExpressionQuestions = {"What role does this decision expression play?",
                                                 "Is this decision an unexpected contradiction?",
                                                 "Is this decision an unexpected tautology?",
                                                 };
const QStringList ifElseQuestions = {"What is the purpose of this conditional statement?",
                                       "What to do if the condition is true?",
                                    "What to do if the condition is false?"
                                    };
const QStringList whileLoopQuestions = {"What does this loop statement accomplish?",
                                       "Is there any mistake in the loop condition?",
                                       "How are the loop variables updated?"
                                       };
const QStringList forLoopQuestions = {"What is the purpose of the loop statement?",
                                       "Is the loop variable initialized correctly?",
                                     "Is the loop termination condition correct?",
                                     "Is the update expression correct?"};
const QStringList inputStatementQuestions = {"What data does this statement provide to the system?",
                                       "Is it possible to produce any exception?"
                                            };
const QStringList outputStatementQuestions = {"What data does this statement output to the outside of the system?",
                                       "Is it possible to produce any exception?"
                                             };
const QStringList controlStatementQuestions = {"Why do you need this statement?",
                                       "Is every variable and constant correct in this statement?"
                                              };
const QStringList exceptionHandlingStatementQuestions = {"What exception does the try block throw?",
                                                        "How is the exception handled by the catch block?"
                                                        };
const QStringList syntacticalExpressionQuestions = {"What is its purpose?",
                                                    "Why is it necessary?",
                                                   "Is there any mistake in using it?"
                                                   };

#endif // CSCRTOOLCHALLENGERQUESTION_H
