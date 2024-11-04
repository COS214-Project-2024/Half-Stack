#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

/**
 * @class Industrial
 * @brief The Industrial class represents an industrial building that employs citizens 
 * and consumes resources.
 */
class Industrial : public Building
{

private:
	///< A vector of pointers to the citizens employed by this Industrial building.
	std::vector<Citizen*> employees;

public:
	/**
     * @brief Constructs an Industrial building with the specified parameters.
     * 
     * @param num The number associated with the building (e.g., ID).
     * @param loc The location of the building.
     */
	Industrial(int num,  std::string loc);

	/**
     * @brief Adds a Citizen to the Industrial building's workforce.
     * 
     * @param c Pointer to the Citizen to be added.
     */
	void addCitizen(Citizen* c);

	/**
     * @brief Removes a Citizen from the Industrial building's workforce.
     * 
     * Searches for the specified Citizen and removes them if found.
     * 
     * @param c Pointer to the Citizen to be removed.
     */
	void removeCitizen(Citizen* c);

	/**
     * @brief Consumes resources required for the operation of the Industrial building.
     * 
     * Decreases the resource levels and prints a message indicating whether 
     * resources are available or if more are needed.
     */
	bool consumeResources();

	/**
     * @brief determines amount of employees in building
     * @return the amount of employees in the building
     */
     int getNumEmployees();

      /**
     * @brief determines if building is at full capacity
     * 
     * @return true if no more citizens can be added, false if more citizens can be added
     */
     bool isFull();

};

#endif
