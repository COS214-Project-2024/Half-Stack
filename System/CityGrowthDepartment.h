#ifndef CITYGROWTHDEPARTMENT_H
#define CITYGROWTHDEPARTMENT_H
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "PublicServicesDepartment.h"
#include "UtilitiesDepartment.h"
#include "ResourceManager.h"
//#include "Government.h"
#include "Building.h"
#include <vector>

class Government;

/**
 * @class CityGrowthDepartment
 * @brief Manages the growth and expansion of the city, including housing, population, jobs, transport, and utilities.
 */
class CityGrowthDepartment : public Department
{

private:

	int population; /**< Current population of the city. */
	static CityGrowthDepartment* uniqueInstance;  /**< Pointer to the CityGrowth Department. */

	ResidentialDepartment* resDepartment; /**< Pointer to the Residential Department. */
	TransportDepartment* TransportDep; /**< Pointer to the Transport Department. */
	UtilitiesDepartment* utilityDep; /**< Pointer to the Utilities Department. */
	PublicServicesDepartment* psDep; /**< Pointer to the Public Services Department. */
	ResourceManager* resourceManager; /**< Pointer to the Resource Manager. */
    Government* gov; /**< Pointer to the Government instance. */

public:
	/**
     * @brief Increases housing capacity based on the specified building type.
     * @param b Character representing the building type ('A' for Apartment, 'H' for House, 'T' for TownHouse, 'E' for Estate).
     * @return if housing was actually added to the residential department
	 */
	bool increaseHousing(char b);

	/**
     * @brief Increases the population by adding a vector of new citizens.
     * @param citizens Vector of Citizen pointers to be added to the population.
     */
	void increasePopulation(std::vector<Citizen*> citizens);

	/**
     * @brief Increases the population by a fixed amount (10 citizens).
     */
	void increasePopulation();

	/**
     * @brief Increases the number of available jobs by constructing new buildings.
     */
	void increaseJobs();

	/**
     * @brief Expands the transport infrastructure by adding new transport facilities.
     */
	void increaseTransport();

	/**
     * @brief Retrieves the current population of the city.
     * @return The current population as an integer.
     */
	int getPopulation();

	/**
	* @brief increases population by 1
	*/
	void updatePopulation();

	 /**
     * @brief Singleton method to get or create the unique instance of CityGrowthDepartment.
     * @param gov Pointer to the Government instance.
     * @return Pointer to the unique CityGrowthDepartment instance.
     */
	static CityGrowthDepartment* instance(Government* gov);

	/**
	* @brief destructor for CityGrowthDepartment
	*/
	~CityGrowthDepartment();

protected:
	 /**
     * @brief Constructor for CityGrowthDepartment.
     * @param gov Pointer to the Government instance.
     */
	CityGrowthDepartment(Government* gov);
};

#endif
