#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Building.h"
#include <vector>
#include <iostream>

class Building;
/**
 * @class Department
 * @brief The department interface implements the basic functionality for all departments.
 */
class Department
{
	private:

		std::vector<Building*> buildings;

	public:

		/**
		 * @brief Constructor for the Department class.
		 */
		Department();

		/**
		 * @brief Adds a building to the vector of department buildings.
		 * @param b Pointer to the building.
		 */
		void addBuilding(Building* b);

		/**
		 * @brief Removes a building from the vector of department buildings.
		 * @param b Pointer to the building.
		 */
		void removeBuilding(Building* b);

     /**
      * @brief Updates the department's buildings.
      * Iterates through all buildings and calls their consumeResources() method.
      */
		void update();
};

#endif