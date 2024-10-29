#include "Plant.h"

Plant::Plant(int num, std::string l) : Industrial(num, l)
{
	
}

PowerPlant::PowerPlant(int num, std::string l) : Plant(num, l)
{
	
}

void PowerPlant::generate()
{
	std::cout << "The power plant is generating power." << std::endl;
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
	std::cout << "The water plant is generating water." << std::endl;
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
	std::cout << "The materials plant is generating materials." << std::endl;
}

Building* MaterialsPlant::build()
{
    return new MaterialsPlant(capacity, location);
}
