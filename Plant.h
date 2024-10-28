#ifndef PLANT_H
#define PLANT_H

#include "Industrial.h"

class Plant : public Industrial
{

public:
	std::string type;

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
