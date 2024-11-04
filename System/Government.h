#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "UtilitiesDepartment.h"
#include "PublicServicesDepartment.h"
#include "LawDepartment.h"
#include "CityGrowthDepartment.h"
#include "ResourceManager.h"
#include <vector>

class Government : public Department
{

private:
	// std::vector<Department*> departments;
	std::string name;
	static Government *uniqueInstance;
	std::vector<Citizen *> citizens;

	ResidentialDepartment *resDep;
	TransportDepartment *transportDep;
	UtilitiesDepartment *utilityDep;
	PublicServicesDepartment *psDep;
	LawDepartment *lawDep;
	CityGrowthDepartment *cgDep;
	ResourceManager *resourceManager;

protected:
	/** @brief Constructs the Government object.
	 *
	 * @param name
	 * This param is the users name, they own their city so the government should be theirs
	 * Sets the different Departments needed in this city with the singleton instances that each class provides.
	 * A message is outputted stating that the user runs this city.
	 * The departments can now observe changes, accompany for resources, budgets and more
	 */
	Government(std::string name);

public:
	/**
	 * @brief Sets the Government singleton instance to ensure that only one instance is created
	 *
	 * @return Government*
	 * Returns the instance. Now we can use the Government functionality through this instance
	 */
	static Government *instance(std::string name);

	/**
	 * @brief Gets the Residential Department instance
	 *
	 * @return ResidentialDepartment*
	 * The Residential Department instance that the class holds
	 */
	ResidentialDepartment *getResidentialDepartment();

	/**
	 * @brief Gets the Transport Department instance
	 *
	 * @return TransportDepartment*
	 * The Transport Department instance that the class holds
	 */
	TransportDepartment *getTransportDepartment();

	/**
	 * @brief Gets the Utilities Department instance
	 *
	 * @return UtilitiesDepartment*
	 * The Utilities Department instance that the class holds
	 */
	UtilitiesDepartment *getUtilitiesDepartment();

	/**
	 * @brief Gets the Public Services Department instance
	 *
	 * @return PublicServicesDepartment*
	 * The Public Services Department instance that the class holds
	 */
	PublicServicesDepartment *getPublicServicesDepartment();

	/**
	 * @brief Gets the Law Department instance
	 *
	 * @return LawDepartment*
	 * The Law Department instance that the class holds
	 */
	LawDepartment *getLawDepartment();

	/**
	 * @brief Gets the City Growth Department instance
	 *
	 * @return CityGrowthDepartment*
	 * The City Growth Department instance that the class holds
	 */
	CityGrowthDepartment *getCityGrowthDepartment();

	/**
	 * @brief Gets the Resource Manager instance
	 *
	 * @return ResourceManager*
	 * The Resource Manager instance that the class holds
	 */
	ResourceManager *getResourceManager();

	/**
	 * @brief Destructs and deallocates any dynamic memory created by the Government class
	 *
	 * Clears and deletes all citizens in the Citizen vector
	 * Deletes the instance, effectively cleaning up memory
	 */
	~Government();

	/**
	 * @brief This function adds a new ctitizen to the Government accoriding to certain conditions
	 *
	 * We first check is the number of homeless citizens exceeds a limit of 20.
	 * If there are too many homless citizens, the new citizen will not be added and the object will be deleted
	 * Checks if the citizen does not already exist within the Government
	 * If the homeless count is not 20 and its a new citizen, the citizen is added and additional updates are then triggered to the Residential and City Growth departments
	 *
	 * @param c Pointer to the object that holds the new citizen to be added
	 *
	 * If the number of homeless people exceed 20:
	 * - an error message is displayed, c is deleted and we exit
	 * If the citizen is already registered:
	 * - message is displayed to the user, exits
	 * If the citizen is successfully added:
	 * - Citizen is added to the list
	 * - Resource Department is called to accompany this citizen
	 * - City Growth department is called to update the numbers
	 *
	 * @note The functions accompanies for memory leaks by deleting the Citizen object if unsuccessful addition occured
	 */
	void addCitizen(Citizen *c);

	/**
	 * @brief Checks whether or not the citizen already exists within the list of citizens
	 *
	 * iterates through thr vector and checks whether the citizen already exists
	 *
	 * @param c Pointer to the citizen object we want to test existance
	 *
	 * @return Boolean value of either true or false
	 * True if the citizen does exist
	 * False if the citizen does not exist
	 *
	 */
	bool hasCitizen(Citizen *c);

	/**
	 * @brief Calculates the total number of citizens currently in the list
	 *
	 * @return int
	 * The cumulative number of citizens within the list
	 */
	int getTotalCitizens();

	/**
	 * @brief Gets the list of citizens currently registered in the system
	 *
	 * @return vector<Citizen*> 
	 * 
	 * The vector that holds the citizens registered
	 */
	std::vector<Citizen *> getCitizens() const;

	/**
	 * @brief Calculates the total number of citizens that are unemployed that are currently in the list
	 *
	 * @return int
	 * The cumulative number of unemployed citizens within the list
	 */
	int getTotalUnemployed();

	/**
	 * @brief Calculates the total number of employed citizens currently in the list
	 *
	 * @return int
	 * The cumulative number of employed citizens within the list
	 */
	int getTotalEmployed();

	/**
	 * @brief Calculates the total number of homeless citizens currently in the list
	 *
	 * @return int
	 * The cumulative number of homeless citizens within the list
	 */
	int getHomeless();

	/**
	 * @brief Calculates the total number of citizens who's satisfactions are neutral that arecurrently in the list
	 *
	 * @return int
	 * The cumulative number of neutral citizens within the list
	 */
	int getTotalNeutral();

	/**
	 * @brief Calculates the total number of citizens who's satisfactions are satisfied that arecurrently in the list
	 *
	 * @return int
	 * The cumulative number of satisfied citizens within the list
	 */
	int getTotalSatisfied();

	/**
	 * @brief Calculates the total number of citizens who's satisfactions are unsatisfied that arecurrently in the list
	 *
	 * @return int
	 * The cumulative number of unsatisfied citizens within the list
	 */
	int getTotalUnsatisfied();

	/**
	 * @brief Displays the current numbers of the various types of citizens, resource numbers and building types that currently exists within the system
	 *
	 * A general overview of the numbers and statistics of your city
	 */
	void getCityStats();
};

#endif
