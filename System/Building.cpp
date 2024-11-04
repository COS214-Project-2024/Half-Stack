#include "Building.h"

/**
 * @brief Constructs a new Building object.
 * 
 * Initializes the building with the specified capacity and location, 
 * and sets the initial state to `Operational`.
 * 
 * @param num The initial capacity of the building.
 * @param loc The designated location of the building.
 */
Building::Building(int num, std::string l)
{
	this->capacity = num;
	this->location = l;
	this->state = new Operational();
	resourceManager = ResourceManager::instance();
}

/**
 * @brief Destroys the Building object and cleans up allocated resources.
 * 
 * If `state` and `resourceManager` pointers are not null, deletes them 
 * to release memory.
 */
Building::~Building()
{
	if (state != NULL)
	{
		delete state;
	}
}

/**
 * @brief Retrieves the current state of the building as a string.
 * 
 * @return A string representing the current status of the building.
 */
std::string Building::getState()
{
	return state->getStatus();
}

/**
 * @brief Advances the state of the building.
 * 
 * Deletes the current state and updates to the next state by calling `update()` 
 * on the existing state.
 */
void Building::progress()
{
	delete state;
	state = state->update();
}

/**
* @brief gets total capacity of building
* 
* @return capacity of building
*/
int Building::getCapacity()
{
	return capacity;
}

/**
* @brief return location
* 
* @return location
*/
std::string Building::getType()
{
	return location;
}
