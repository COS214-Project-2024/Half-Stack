#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

/**
 * @class Residential
 * @brief The Residential class represents a residential building that can house citizens.
 */
class Residential : public Building
{

private:
	///< Vector of pointers to the citizens residing in the building.
	std::vector<Citizen*> residents;

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
     * @brief Consumes resources necessary for the residential building's operation.
     */
	void consumeResources();
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
};

#endif