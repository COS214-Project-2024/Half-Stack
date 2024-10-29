#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

class PlantCreator
{

private:
	Plant* plant;

public:
	virtual Plant* createPlant(int capacity,  const std::string& location) = 0;

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
