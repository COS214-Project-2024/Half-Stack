#include "Plant.h"
#include "ResourceManager.h"
#include <iostream>

/**
 * @brief Constructs a Plant with the specified capacity, type, and location.
 *
 * Initializes occupancy to 0 and reduces resource levels based on the plant type.
 * 
 * @param capacity The capacity of the plant.
 * @param type The type of plant.
 * @param location The location of the plant.
 */
Plant::Plant(int capacity, std::string type, std::string location) : Industrial(capacity, location)
{
    this->type = type;
    this->capacity = capacity;
    this->location = location;
    this->occupancy = 0;

    ResourceManager* rm = ResourceManager::instance();
    if (type == "Power") 
    {
        if (rm->decreaseResourceLevels(0, 0, 75, 75, 30)==true)
        {
            if (rm->decreaseBudget(200)==true)
            {
            }else {
                rm->increaseResourceLevels(0, 0, 75, 75, 30);
            }
        }
    } 
    else if (type == "Water") 
    {
        if (rm->decreaseResourceLevels(0, 0, 50, 50, 20)==true)
        {
            if (rm->decreaseBudget(100)==true)
            {
            }else {
                rm->increaseResourceLevels(0, 0, 50, 50, 20);
            }
        }
    } 
}

std::string Plant::getType()
{
    return type;
}

/**
 * @brief Constructs a PowerPlant with the specified capacity and location.
 * 
 * Outputs a message indicating creation details.
 * 
 * @param capacity The capacity of the Power Plant.
 * @param location The location of the Power Plant.
 */
PowerPlant::PowerPlant(int capacity, std::string location) : Plant(capacity, "Power", location) 
{
    /*std::cout << "A Power factory has been created at " << location
              << " with a max capacity of " << capacity << std::endl;*/
}

/**
 * @brief Constructs a WaterPlant with the specified capacity and location.
 * 
 * Outputs a message indicating creation details.
 * 
 * @param capacity The capacity of the Water Plant.
 * @param location The location of the Water Plant.
 */
WaterPlant::WaterPlant(int capacity, std::string location) : Plant(capacity, "Water", location)
{
    /*std::cout << "A Water factory has been created at " << location
              << " with a max capacity of " << capacity << std::endl;*/
}



/**
 * @brief Generates additional water resources for the WaterPlant.
 */
void WaterPlant::generate()
{
    ResourceManager* rm = ResourceManager::instance();
    rm->increaseResourceLevels(500,0,0,0,0);
    std::cout << "More water has been generated by the Water Plant" << std::endl;
}

/**
 * @brief Generates additional power resources for the PowerPlant.
 */
void PowerPlant::generate()
{
    ResourceManager* rm = ResourceManager::instance();
    rm->increaseResourceLevels(0,500,0,0,0);
    std::cout << "More power has been generated by the Power Plant" << std::endl;
}


/**
 * @brief Builds and returns a new WaterPlant.
 * 
 * @return Pointer to a new WaterPlant object.
 */
Building* WaterPlant::build()
{
    return new WaterPlant(capacity, location);
}

/**
 * @brief Builds and returns a new PowerPlant.
 * 
 * @return Pointer to a new PowerPlant object.
 */
Building* PowerPlant::build()
{
    return new PowerPlant(capacity, location);
}
