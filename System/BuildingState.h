#include <string>
#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

/**
 * @class BuildingState
 * @brief Abstract base class for various states of a building.
 * 
 * Defines the interface for building states, including retrieving the
 * status and updating to the next state.
 */
class BuildingState
{

public:
	/**
     * @brief Retrieves the status of the current building state.
     * 
     * @return A string representing the status of the building state.
     */
	virtual std::string getStatus() = 0;

	/**
     * @brief Updates to the next state in the building's lifecycle.
     * 
     * @return A pointer to the next BuildingState in the lifecycle.
     */
	virtual BuildingState* update() = 0;

	/**
     * @brief Destructor for building state.
     */
	virtual ~BuildingState() {};
};


/**
 * @class Planning
 * @brief Represents the planning state of a building.
 * 
 * In the Planning state, the building is in its initial setup phase.
 */
class Planning : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};


/**
 * @class Construction
 * @brief Represents the construction state of a building.
 * 
 * In the Construction state, the building is actively being built.
 */
class Construction : public BuildingState
{

public:

	std::string getStatus();
	BuildingState* update();
};


/**
 * @class Operational
 * @brief Represents the operational state of a building.
 * 
 * In the Operational state, the building is fully functional and active.
 */
class Operational : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};


/**
 * @class Renovation
 * @brief Represents the renovation state of a building.
 * 
 * In the Renovation state, the building is undergoing updates or repairs.
 */
class Renovation : public BuildingState
{
	
public:

	std::string getStatus();
	BuildingState* update();
};

#endif
