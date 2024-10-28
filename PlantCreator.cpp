#include "PlantCreator.h"

PlantCreator::PlantCreator()
{
	
}

Plant* PowerPlantCreator::createPlant()
{
	return new PowerPlant(1, "");
}

Plant* WaterPlantCreator::createPlant()
{
	return new WaterPlant(1, "");
}

Plant* MaterialsPlantCreator::createPlant()
{
	return new MaterialsPlant(1, "");
}