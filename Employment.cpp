#include "Employment.h"

std::string Employed::getStatus()
{
    return "Employed";
}

Employment *Employed::toggleStatus()
{
    return new Unemployed();
}

std::string Unemployed::getStatus()
{
    return "Unemployed";
}

Employment *Unemployed::toggleStatus()
{
    return new Employed();
}
