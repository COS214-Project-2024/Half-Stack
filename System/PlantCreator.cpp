#include "PlantCreator.h"
#include <stdexcept>

/**
 * @brief Constructor for PlantCreator.
 *
 * Initializes a new instance of the PlantCreator class.
 */
PlantCreator::PlantCreator()
{
	
}

/**
 * @brief Creates a PowerPlant object with the specified capacity and location.
 * 
 * This method checks that the capacity is a positive integer and that the
 * location is non-empty. Throws an exception if these conditions are not met.
 * 
 * @param capacity The capacity of the power plant.
 * @param location The location of the power plant.
 * @return Pointer to the newly created PowerPlant object.
 * @throws std::invalid_argument If capacity is <= 0 or location is empty.
 */
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


/**
 * @brief Creates a WaterPlant object with the specified capacity and location.
 * 
 * This method checks that the capacity is a positive integer and that the
 * location is non-empty. Throws an exception if these conditions are not met.
 * 
 * @param capacity The capacity of the water plant.
 * @param location The location of the water plant.
 * @return Pointer to the newly created WaterPlant object.
 * @throws std::invalid_argument If capacity is <= 0 or location is empty.
 */
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
