#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>

#include "Building.h"

/**
 * @class City
 * @brief The city is implemented as a composite of various buildings.
 */
class City : public Building
{
	private:
	
		std::vector<Building*> buildings;

	public:

		/**	
		 * @brief Constructs a new City object.
		 * @param num The initial capacity of the house.
		 * @param loc The designated location of the house.
		 */
		City(int num, std::string l);

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
		 * @brief Fetched the building at the specified index.
		 * @param index Index of the desired building in the vector.
		 * @return Pointer to the building.
		 */
		Building* getBuilding(int index);

		/**
		 * @brief Builds an empty city.
		 * @return A pointer to the newly created City object.
		 */
		Building* build();

		/**	
		 * @brief Calls consume resources on all buildings in the city.
		 */
		void consumeResources();
};

#endif
