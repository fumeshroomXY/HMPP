#include "issue.h"

issue::issue()
{

}

QString Issue::getName() const
{
    return name;
}

void Issue::setName(const QString &value)
{
    name = value;
}
