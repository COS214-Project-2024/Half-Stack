#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <string>
#include <vector>

#include "Building.h"
#include "Citizen.h"

/**
 * @class Commercial
 * @brief The Commercial class represents a commercial building,
 *        which is a type of Building that can have employees and
 *        consume resources.
 */
class Commercial : public Building
{

private:
	///< A vector of pointers to the employees in the commercial building.
	std::vector<Citizen*> employees;

public:
	/**
     * @brief Constructs a new Commercial object.
     * 
     * @param num The initial capacity of the Commercial building.
     * @param loc The location of the Commercial building.
     */
	Commercial(int num, std::string loc);

	/**
     * @brief Adds a Citizen to the employees of the Commercial building.
     * 
     * @param c Pointer to the Citizen to be added.
     */
	void addCitizen(Citizen* c);

	/**
     * @brief Removes a Citizen from the employees of the Commercial building.
     * 
     * @param c Pointer to the Citizen to be removed.
     */
	void removeCitizen(Citizen* c);

	/**
     * @brief Consumes resources required for the operation of the Commercial building.
     * 
     * If sufficient resources are available, the building will consume them;
     * otherwise, a message will indicate that more resources are needed.
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

     /**
     * @brief destructor
     */
     ~Commercial();
};

#endif
