#ifndef PLANT_H
#define PLANT_H

#include "Industrial.h"
#include "Citizen.h"
#include <vector>
#include <memory>

class Plant : public Industrial
{
private:
	std::string type;
	int capacity;
	int occupancy;
	std::string location;

	//smart pointers for automatic memory management
	std::vector<std::unique_ptr<Citizen>> citizens; 
	std::vector<std::unique_ptr<Citizen>> employees;
public:
	

	Plant(int num, std::string l);

	virtual void generate() = 0;
};

class PowerPlant : public Plant
{

public:

	PowerPlant(int num, std::string l);

	void generate();

	Building* build();
};

class WaterPlant : public Plant
{

public:

	WaterPlant(int num, std::string l);

	void generate();

	Building* build();
};

class MaterialsPlant : public Plant
{

public:

	MaterialsPlant(int num, std::string l);

	void generate();

	Building* build();
};

#endif
