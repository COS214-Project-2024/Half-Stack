#include <string>
#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState
{

public:

	virtual std::string getStatus() = 0;
	virtual BuildingState* update() = 0;
};

class Planning : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};

class Construction : public BuildingState
{

public:

	std::string getStatus();
	BuildingState* update();
};

class Operational : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};

class Renovation : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};

#endif