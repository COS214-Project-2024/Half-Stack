#include "Satisfaction.h"

std::string Satisfaction::getStatus()
{
    return "";
}

Satisfaction* Satisfied::raiseStatus()
{
    return new Satisfied();
}

Satisfaction* Satisfied::lowerStatus()
{
    return new Neutral();
}

Satisfaction* Neutral::raiseStatus()
{
    return new Satisfied();
}

Satisfaction* Neutral::lowerStatus()
{
    return new Unsatisfied();
}

Satisfaction* Unsatisfied::raiseStatus()
{
    return new Neutral();
}

Satisfaction* Unsatisfied::lowerStatus()
{
    return new Unsatisfied();
}