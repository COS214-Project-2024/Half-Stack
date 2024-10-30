#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Building.h"
#include <vector>

/**
 * @class Department
 * @brief The Department class manages a collection of Building objects.
 */
class Department
{

private:
	///< A vector of pointers to the buildings managed by this Department.
	std::vector<Building *> buildings;

public:
	/**
	 * @brief Adds a Building to the Department's collection.
	 *
	 * @param building Pointer to the Building to be added.
	 */
	void addBuilding(Building *building);

	/**
	 * @brief Removes a Building from the Department's collection.
	 *
	 * Searches for the specified Building and removes it from the collection.
	 *
	 * @param building Pointer to the Building to be removed.
	 */
	void removeBuilding(Building *building);

	/**
	 * @brief Updates the Department's buildings.
	 *
	 * Iterates through all buildings and calls their consumeResources() method.
	 */
	void update();
};

#endif
