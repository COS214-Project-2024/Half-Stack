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
	

	Plant(int capacity,  std::string type, std::string location);

	virtual ~Plant() = default; // default destructor 

	virtual void generate() = 0; 

	void consumeResources() override;
};

class PowerPlant : public Plant
{

public:

	PowerPlant(int capacity, std::string location);

	void generate();

	Building* build();
};

class WaterPlant : public Plant
{

public:

	WaterPlant(int capacity, std::string location);

	void generate();

	Building* build();
};

class MaterialsPlant : public Plant
{

public:

	MaterialsPlant(int capacity, std::string location);

	void generate();

	Building* build();
};

#endif
