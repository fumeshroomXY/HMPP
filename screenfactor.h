#ifndef SCREENFACTOR_H
#define SCREENFACTOR_H

#include <QObject>

class ScreenFactor : public QObject
{
    Q_OBJECT
public:
    explicit ScreenFactor(QObject *parent = 0);

    double getScreenFactor();

private:
    double screenFactor = 0;

signals:

public slots:
};

#endif // SCREENFACTOR_H
