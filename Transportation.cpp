#include "Transportation.h"

Transportation::Transportation()
{

}

void Transportation::open()
{
	isOpen = true;
}

void Transportation::close()
{
    isOpen = false;
}

bool Transportation::getStatus()
{
    return isOpen;
}

Airport::Airport()
{

}

Road::Road()
{

}

Railway::Railway()
{

}

Trail::Trail()
{

}

void Trail::open()
{
    clear();
}

void Trail::close()
{
    block();
}

bool Trail::getStatus()
{
    return getPathStatus();
}

Pathway::Pathway()
{

}

void Pathway::clear()
{
    path = true;
}

void Pathway::block()
{
    path = false;
}

bool Pathway::getPathStatus()
{
    return path;
}
