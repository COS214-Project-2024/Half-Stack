#include "PlantCreator.h"
#include <stdexcept>

PlantCreator::PlantCreator()
{
	
}

Plant* PowerPlantCreator::createPlant(int capacity, const std::string& location)
{
    if (capacity <= 0) 
    {
        std::cout << "Error: Capacity must be a positive integer." << std::endl;
        throw std::invalid_argument("Capacity must be positive.");
    }


    if (location.empty()) 
    {
        std::cout << "Error: Location cannot be empty." << std::endl;
        throw std::invalid_argument("Location cannot be empty.");
    }

    return new PowerPlant(capacity, location);
}

Plant* WaterPlantCreator::createPlant(int capacity, const std::string& location)
{
    if (capacity <= 0) 
    {
        std::cout << "Error: Capacity must be a positive integer." << std::endl;
        throw std::invalid_argument("Capacity must be positive.");
    }


    if (location.empty()) 
    {
        std::cout << "Error: Location cannot be empty." << std::endl;
        throw std::invalid_argument("Location cannot be empty.");
    }

    return new WaterPlant(capacity, location);
}

Plant* MaterialsPlantCreator::createPlant()
{
	return new MaterialsPlant(1, "");
}
