#ifndef PLANT_H
#define PLANT_H

#include "Industrial.h"
#include "Citizen.h"
#include <vector>
#include <memory>


/**
 * @brief Abstract base class representing a generic plant.
 *
 * Plant is an industrial building that requires citizens to be assigned as employees.
 * It has a specific type (e.g., Power, Water, Materials), capacity, occupancy, and location.
 */
class Plant : public Industrial
{
public:
	std::string type;
	int capacity;
	int occupancy;
	std::string location;

	//smart pointers for automatic memory management
	std::vector<std::unique_ptr<Citizen>> citizens; 
	std::vector<std::unique_ptr<Citizen>> employees;
public:
	
	 /**
     * @brief Constructs a Plant with specified capacity, type, and location.
     * 
     * @param capacity The maximum capacity of the plant.
     * @param type The type of plant.
     * @param location The location where the plant is built.
     */
	Plant(int capacity,  std::string type, std::string location);

	/**
     * @brief Default virtual destructor.
     */
	virtual ~Plant() = default; 

	 /**
     * @brief Pure virtual function to generate resources specific to the plant type.
     */
	virtual void generate() = 0; 

     std::string getType();
};


/**
 * @brief Class representing a Power Plant.
 *
 * PowerPlant generates electricity and consumes resources.
 */
class PowerPlant : public Plant
{

public:
	 /**
     * @brief Constructs a PowerPlant with the specified capacity and location.
     * 
     * @param capacity The maximum capacity of the Power Plant.
     * @param location The location where the Power Plant is built.
     */
	PowerPlant(int capacity, std::string location);

	 /**
     * @brief Generates power resources.
     */
	void generate();

	 /**
     * @brief Builds and returns a new PowerPlant.
     * 
     * @return Pointer to a new PowerPlant object.
     */
	Building* build();
};


/**
 * @brief Class representing a Water Plant.
 *
 * WaterPlant generates water and consumes resources.
 */
class WaterPlant : public Plant
{

public:
	 /**
     * @brief Constructs a WaterPlant with the specified capacity and location.
     * 
     * @param capacity The maximum capacity of the Water Plant.
     * @param location The location where the Water Plant is built.
     */
	WaterPlant(int capacity, std::string location);

	 /**
     * @brief Generates water resources.
     */
	void generate();

	 /**
     * @brief Builds and returns a new WaterPlant.
     * 
     * @return Pointer to a new WaterPlant object.
     */
	Building* build();
};


#endif
