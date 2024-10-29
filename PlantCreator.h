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
	  Plant* createPlant(int capacity,  const std::string& location) override;

};

class WaterPlantCreator : public PlantCreator
{


public:
	 Plant* createPlant(int capacity,  const std::string& location) override;
};

class MaterialsPlantCreator : public PlantCreator
{


public:
	Plant* createPlant(int capacity,  const std::string& location) override;
};


#endif
