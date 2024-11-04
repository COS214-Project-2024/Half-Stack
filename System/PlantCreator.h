#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"
#include <memory>

/**
  * @class PlantCreator
  * @brief Abstract factory class responsible for creating Plant objects.
  *
  * The PlantCreator class declares the factory method for creating Plant objects,
  * which is implemented by derived classes for specific types of plants.
  */
class PlantCreator
{

private:
	Plant* plant;

public:
 	/**
     * @brief Pure virtual function to create a Plant object.
     * 
     * This function must be implemented by derived classes to create
     * specific types of plants.
     * 
     * @param capacity The capacity of the plant.
     * @param location The location of the plant.
     * @return Pointer to a newly created Plant object.
     */
	virtual Plant* createPlant(int capacity,  const std::string& location) = 0;
	/**
     * @brief Constructor for PlantCreator.
     */
	PlantCreator();
};


/**
 * @class PowerPlantCreator
 * @brief Concrete factory class for creating PowerPlant objects.
 */
class PowerPlantCreator : public PlantCreator
{


public:
	/**
     * @brief Creates a PowerPlant object.
     * 
     * @param capacity The capacity of the power plant.
     * @param location The location of the power plant.
     * @return Pointer to a newly created PowerPlant object.
     * @throws std::invalid_argument If capacity is <= 0 or location is empty.
     */
	  Plant* createPlant(int capacity,  const std::string& location) override;

};

/**
 * @class WaterPlantCreator
 * @brief Concrete factory class for creating WaterPlant objects.
 */
class WaterPlantCreator : public PlantCreator
{


public:
	/**
     * @brief Creates a WaterPlant object.
     * 
     * @param capacity The capacity of the water plant.
     * @param location The location of the water plant.
     * @return Pointer to a newly created WaterPlant object.
     * @throws std::invalid_argument If capacity is <= 0 or location is empty.
     */
	 Plant* createPlant(int capacity,  const std::string& location) override;
};


#endif
