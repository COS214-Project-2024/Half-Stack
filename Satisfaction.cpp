#include "Satisfaction.h"

std::string Satisfaction::getStatus()
{
    return this->status;
}

Satisfied::Satisfied()
{
    this->status = "Satisfied";
}

Satisfaction *Satisfied::raiseStatus()
{
    std::cout << "Already at highest satisfaction level." << std::endl;
    return this;
}

Satisfaction* Satisfied::lowerStatus()
{
    return new Neutral();
}

Neutral::Neutral()
{
    this->status = "Neutral";
}

Satisfaction *Neutral::raiseStatus()
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

Unsatisfied::Unsatisfied()
{
    this->status = "Unsatisfied";
}

Satisfaction* Unsatisfied::lowerStatus()
{
    std::cout << "Already at lowest satisfaction level." << std::endl;
    return this;
}
