#ifndef PLANT_H
#define PLANT_H

#include "Industrial.h"

class Plant : public Industrial
{

public:
	std::string type;

	void Build();

	Plant(int num, std::string l);

	virtual void generate() = 0;
};

class PowerPlant : public Plant
{

public:

	PowerPlant(int num, std::string l);

	void generate();
};

class WaterPlant : public Plant
{

public:

	WaterPlant(int num, std::string l);

	void generate();
};

class MaterialsPlant : public Plant
{

public:

	MaterialsPlant(int num, std::string l);

	void generate();
};

#endif