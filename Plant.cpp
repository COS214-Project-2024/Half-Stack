#include "Plant.h"

Plant::Plant(int num, std::string l) : Industrial(num, l)
{
	
}

PowerPlant::PowerPlant(int num, std::string l) : Plant(num, l)
{
	
}

void PowerPlant::generate()
{
	
}

Building* PowerPlant::build()
{
    return new PowerPlant(capacity, location);
}

WaterPlant::WaterPlant(int num, std::string l) : Plant(num, l)
{
	
}

void WaterPlant::generate()
{
	
}

Building* WaterPlant::build()
{
    return new WaterPlant(capacity, location);
}

MaterialsPlant::MaterialsPlant(int num, std::string l) : Plant(num, l)
{
	
}

void MaterialsPlant::generate()
{
	
}

Building* MaterialsPlant::build()
{
    return new MaterialsPlant(capacity, location);
}
