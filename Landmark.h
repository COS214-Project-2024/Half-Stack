#ifndef LANDMARK_H
#define LANDMARK_H

#include <vector>
#include <string>

#include "Building.h"

/**
 * @class Landmark
 * @brief The Landmark class represents a landmark building that employs citizens 
 * and consumes resources.
 */
class Landmark : public Building
{

private:
	///< A vector of pointers to the citizens employed by this Landmark.
	std::vector<Citizen*> employees;

public:
	/**
     * @brief Constructs a Landmark building with the specified parameters.
     * 
     * @param num The number associated with the building (e.g., ID).
     * @param loc The location of the building.
     */
	Landmark(int num, std::string loc);

	/**
     * @brief Adds a Citizen to the Landmark building's workforce.
     * 
     * @param c Pointer to the Citizen to be added.
     */
	void addCitizen(Citizen* c);

	/**
     * @brief Removes a Citizen from the Landmark building's workforce.
     * 
     * Searches for the specified Citizen and removes them if found.
     * 
     * @param c Pointer to the Citizen to be removed.
     */
	void removeCitizen(Citizen* c);

	/**
     * @brief Consumes resources required for the operation of the Landmark building.
     * 
     * Decreases the resource levels and prints a message indicating whether 
     * resources are available or if more are needed.
     */
	void consumeResources();
};

#endif