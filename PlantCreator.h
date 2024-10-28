#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

class PlantCreator
{

public:
	virtual Plant* createPlant() = 0;

	PlantCreator();
};

class PowerPlantCreator : public PlantCreator
{


public:
	Plant* createPlant();
};

class WaterPlantCreator : public PlantCreator
{


public:
	Plant* createPlant();
};

class MaterialsPlantCreator : public PlantCreator
{


public:
	Plant* createPlant();
};

#endif
