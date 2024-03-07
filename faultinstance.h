#ifndef FAULTINSTANCE_H
#define FAULTINSTANCE_H

#include <QObject>
#include <QString>

class FaultInstance : public QObject
{
    Q_OBJECT
public:
    explicit FaultInstance(QObject *parent = 0);

signals:

public slots:

private:
    QString faultName;
    int faultCode;
    enum faultType{
        NullPointerException,
        IndexOutOfBoundsException,
        NumberFormatException
    };
    enum severity{
        Critical,
        Warning,
        Error
    };
    QString faultDescript;
};

#endif // FAULTINSTANCE_H
