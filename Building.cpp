#include "Building.h"

Building::Building(int num, std::string loc)
{
	this->capacity = num;
	this->location = loc;
	this->state = new Operational();
}

Building::~Building()
{
	if (state != NULL)
	{
		delete state;
	}

	if (this->resourceManager != NULL)
	{
		delete resourceManager;
	}
}

std::string Building::getState()
{
	return state->getStatus();
}

void Building::progress()
{
	delete state;
	state = state->update();
}