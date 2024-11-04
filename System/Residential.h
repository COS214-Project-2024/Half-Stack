#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

class Citizen;

/**
 * @class Residential
 * @brief The Residential class represents a residential building that can house citizens.
 */
class Residential : public Building
{
private:
	///< Vector of pointers to the citizens residing in the building.
	std::vector<Citizen*> residents;
     int water;
     int energy;
     int mats;

public:
	/**
     * @brief Constructs a Residential object with a specified number and location.
     * 
     * @param num The capacity or number of residents that the residential building can hold.
     * @param loc The location of the residential building.
     */
	Residential(int num,  std::string loc);

	/**
     * @brief Adds a citizen to the list of residents.
     * 
     * @param c Pointer to the citizen to be added.
     */
	void addCitizen(Citizen* c);

	/**
     * @brief Removes a citizen from the list of residents.
     * 
     * @param c Pointer to the citizen to be removed.
     */
	void removeCitizen(Citizen* c);

	/**
     * @brief Consumes resources required for the Residential building based on the number of employees.
     * 
     * This function attempts to decrease the resource levels in the ResourceManager instance based on the 
     * number of employees in the building. If the resources are successfully decreased, it iterates over 
     * the list of employees and updates their resource status and satisfaction levels if they lack resources.
     * 
     * @return true if resources were successfully consumed; false if resources are insufficient.
     * 
     * The function decreases water and energy resources based on a factor of 10 per employee. 
     * If resources are available, it sets the `NoResources` flag to true for each employee lacking resources 
     * and raises their satisfaction status.
     * 
     * If the resources are insufficient, the function returns false, and alternative methods to acquire resources 
     * (such as production or purchasing) could be implemented as additional logic.
     */
	bool consumeResources();

    /**
     * @brief Gets the list of residents in the building.
     * @return A vector containing pointers to the residents.
     */
     std::vector<Citizen*> getResidents();

     /**
     * @brief Gets the number of residents in a building.
     * 
     * @return number of residents in building
     */
    int getNumResidents();

     /**
     * @brief determines if the building is at max capacity with regards to the amount of residents
     * 
     * @return if builing can house more citizens or not
     */
    bool isFull();

     /**
     * @brief increaese water if amenity is added
     */
    void increaseWaterConsumption(int num);

     /**
     * @brief increaese power if amenity is added
     */
     void increasePowerConsumption(int num);

     /**
     * @brief virtual destructor for Residential
     */
     virtual ~Residential(){};
};


/**
 * @class Estate
 * @brief The Estate class represents a collection of residential buildings, acting as a larger residential entity.
 */
class Estate : public Residential
{

private:
	///< Vector of pointers to residential buildings within the estate.
	std::vector<Residential*> buildings;

public:
	/**
     * @brief Constructs an Estate object with a specified number and location.
     * 
     * @param num The capacity or number of residents that the estate can hold.
     * @param loc The location of the estate.
     */
	Estate(int num,  std::string loc);

	/**
     * @brief Adds a residential building to the estate.
     * 
     * @param b Pointer to the residential building to be added.
     */
	void addBuilding(Residential* b);

	/**
     * @brief Removes a residential building from the estate.
     * 
     * @param b Pointer to the residential building to be removed.
     */
	void removeBuilding(Residential* b);

	/**
     * @brief Builds a new Estate if resources are sufficient.
     * 
     * @return Building* Pointer to the newly created Estate if successful, or nullptr if resources are insufficient.
     */
	Building* build();

     /**
     * @brief destructor for estate
     */
     ~Estate();
};

#endif
