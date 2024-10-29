#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

class Residential : public Building
{

private:
	std::vector<Citizen*> residents;

public:

	Residential(int num,  std::string loc);

	void addCitizen(Citizen* c);

	void removeCitizen(Citizen* c);

	void consumeResources();
};

class Estate : public Residential
{

private:
	std::vector<Residential*> buildings;

public:

	Estate(int num,  std::string loc);

	void addBuilding(Residential* b);

	void removeBuilding(Residential* b);

	Building* build();
};

#endif