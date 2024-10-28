#include "Employment.h"

std::string Employed::getStatus()
{
    return "";
}

Employment *Employed::toggleStatus()
{
    return new Unemployed();
}

std::string Unemployed::getStatus()
{
    return "";
}

Employment *Unemployed::toggleStatus()
{
    return new Employed();
}
