#include "City.h"

/**	
 * @brief Constructs a new City object.
 * @param num The initial capacity of the house.
 * @param loc The designated location of the house.
 */
City::City(int num, std::string l) : Building(num, l)
{

}

/**
 * @brief Adds a building to the vector of department buildings.
 * @param b Pointer to the building.
 */
void City::addBuilding(Building* b)
{
	buildings.push_back(b);
}

/**
 * @brief Removes a building from the vector of department buildings.
 * @param b Pointer to the building.
 */
void City::removeBuilding(Building* b)
{
	for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        if (*i == b)
        {
            i = buildings.erase(i);
            return;
        }
    }
}

/**
 * @brief Fetched the building at the specified index.
 * @param index Index of the desired building in the vector.
 * @return Pointer to the building.
 */
Building* City::getBuilding(int index)
{
	int found = 0;
	for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
		if (found == index)
		{
			return *i;
		}
		else
		{
			found++;
		}
    }
	return NULL;
}

/**
 * @brief Builds an empty city.
 * @return A pointer to the newly created City object.
 */
Building* City::build()
{
	return new City(capacity, location);
}

/**	
 * @brief Calls consume resources on all buildings in the city.
 */
void City::consumeResources()
{
	for (std::vector<Building*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        (*i)->consumeResources();
    }
}