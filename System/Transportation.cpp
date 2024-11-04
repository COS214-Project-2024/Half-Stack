#include "Transportation.h"
#include "TransportDepartment.h"
//int Airport::counter=0;

Transportation::Transportation(std::string t)
{
    type=t;
}

std::string Transportation::getType()
{
    return type;
}

Airport::Airport(): Transportation("Airport")
{
    
}

Road::Road(): Transportation("Road")
{

}

Railway::Railway(): Transportation("Railway")
{

}

Trail::Trail(): Transportation("Trail")
{

}

Pathway::Pathway()
{

}

/**
 * @brief Opens the transport to be used by citizens.
 * (Target of Adapter)
 */
void Transportation::open()
{
	isOpen = true;
}

/**
 * @brief Closes the transport from being used by citizens.
 * (Target of Adapter)
 */
void Transportation::close()
{
    isOpen = false;
}

/**
 * @brief Whether the transport is open or closed.
 * (Target of Adapter)
 * @return Status of the respective transportation mode.
 */
bool Transportation::getStatus()
{
    return isOpen;
}

/**
 * @brief Opens the trail to be used by citizens.
 * (Adapter of Adapter)
 */
void Trail::open()
{
    clear();
}

/**
 * @brief Closes the trail from being used by citizens.
 * (Adapter of Adapter)
 */
void Trail::close()
{
    block();
}

/**
 * @brief Whether the trail is open or closed.
 * (Adapter of Adapter)
 * @return Status of the trail mode.
 */
bool Trail::getStatus()
{
    return getPathStatus();
}

/**
 * @brief Clears the pathway to be accessed.
 * (Adaptee of Adapter)
 */
void Pathway::clear()
{
    path = true;
}

/**
 * @brief Blocks the pathway from being accessed.
 * (Adaptee of Adapter)
 */
void Pathway::block()
{
    path = false;
}

/**
 * @brief Whether the pathway is cleared or blocked.
 * (Adaptee of Adapter)
 * @return Status of the pathway.
 */
bool Pathway::getPathStatus()
{
    return path;
}
