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
	void Build();

	Plant(int capacity,  std::string type, std::string location);

	virtual ~Plant() = default; // default destructor 

	virtual void generate() = 0; 
};

class PowerPlant : public Plant
{

public:

	PowerPlant(int capacity, std::string type, std::string location);

	void generate();
};

class WaterPlant : public Plant
{

public:

	WaterPlant(int capacity, std::string type , std::string location);

	void generate();
};

class MaterialsPlant : public Plant
{

public:

	MaterialsPlant(int capacity, std::string type , std::string location);

	void generate();
};

#endif
