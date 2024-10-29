#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

#include "BuildingState.h"
#include "Citizen.h"
#include "ResourceManager.h"

class Citizen;

class Building
{

public:

	std::string location;
	int capacity;
	BuildingState* state;
	ResourceManager* resourceManager;  // Reference to ResourceManager

	Building(int num, std::string location);

	std::string getState();
	void progress();

	virtual Building* build() = 0;

	virtual void consumeResources() = 0;

	~Building();
};

#endif