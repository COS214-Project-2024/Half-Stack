#include "BuildingState.h"

std::string Planning::getStatus()
{
	return "PLANNING";
}

BuildingState* Planning::update()
{
	return new Construction();
}

std::string Construction::getStatus()
{
	return "CONSTRUCTION";
}

BuildingState* Construction::update()
{
	return new Operational();
}

std::string Operational::getStatus()
{
	return "OPERATIONAL";
}

BuildingState* Operational::update()
{
	return new Renovation();
}

std::string Renovation::getStatus()
{
	return "RENOVATION";
}

BuildingState* Renovation::update()
{
	return new Operational();
}