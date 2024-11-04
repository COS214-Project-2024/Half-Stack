#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

#include "BuildingState.h"
//#include "Citizen.h"
#include "ResourceManager.h"

class ResourceManager;
class Citizen;

/**
 * @class Building
 * @brief Represents a building within the simulation.
 * 
 * The Building class serves as a base class for various types of buildings, 
 * defining common properties such as location, capacity, and interactions with 
 * resources and state management.
 */
class Building
{

public:
	
	std::string location;
	int capacity;
	BuildingState* state;
	ResourceManager* resourceManager;  // Reference to ResourceManager

	/**
     * @brief Constructs a new Building object.
     * 
     * @param num The initial capacity of the building.
     * @param location The designated location of the building.
     */
	Building(int num, std::string location);

	/**
     * @brief Retrieves the current state of the building.
     * 
     * @return A string representing the current state of the building.
     */
	std::string getState();

	/**
     * @brief Advances the state or status of the building.
     * 
     * This function is generally used to progress the building's state in each simulation step.
     */
	void progress();

	/**
     * @brief Constructs and returns a new building.
     * 
     * @return A pointer to a new Building object. This is a pure virtual function, 
     * meaning derived classes must implement this function.
     */
	virtual Building* build() = 0;

	/**
     * @brief Consumes the resources required by the building.
     * 
     * This is a pure virtual function, requiring implementation in derived classes.
     * It defines how resources are consumed by the specific type of building.
     */
	virtual bool consumeResources() = 0;

	/**
     * @brief Destroys the Building object and cleans up resources.
     */
	virtual ~Building();

     /**
     * @brief pure virtual function to add a citizen to the building
     */
     virtual void addCitizen(Citizen* c)=0;

     /**
     * @brief gets total capacity of building
     * 
     * @return capacity of building
     */
     virtual int getCapacity();

     /**
     * @brief determines if building is at full capacity
     * 
     * @return true if no more citizens can be added, false if more citizens can be added
     */
     virtual bool isFull(){ return false;}

     /**
     * @brief return location
     * 
     * @return location
     */
     std::string getType();
};

#endif
