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
