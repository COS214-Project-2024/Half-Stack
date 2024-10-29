#include "Plant.h"
#include <iostream>

Plant::Plant(int capacity, std::string type, std::string location) 
{
    this->type = type;
    this->capacity = capacity;
    this->location = location;
    this->occupancy = 0;  //defaults to 0 when created
    // citizen member variable will automatically be empty when an instance of the Plant class  is created.
}

PowerPlant::PowerPlant(int capacity, std::string location) : Plant(capacity, "Power", location) 
{
    std::cout << "A Power factory has been created at " << location 
              << " with a max capacity of " << capacity << std::endl;
}


WaterPlant::WaterPlant(int capacity, std::string location) : Plant(capacity, "Water", location)
{
    std::cout << "A Water factory has been created at " << location 
              << " with a max capacity of " << capacity << std::endl;
}

MaterialsPlant::MaterialsPlant(int capacity, std::string location) : Plant(capacity, "Materials", location)  
{
    std::cout << "A Materials factory has been created at " << location 
              << " with a max capacity of " << capacity << std::endl;
}


void WaterPlant::generate()
{
	 std::cout << "More water has been generated by the Water Plant" << std::endl;
}

void PowerPlant::generate()
{
	  std::cout << "More power has been generated by the Power Plant" << std::endl;
}

void MaterialsPlant::generate()
{
	 std::cout << "More materials has been generated by the Materials Plant" << std::endl;
}

void Plant::Build()
{

}
