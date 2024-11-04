#include "BuildingState.h"

/**
 * @brief Gets the status of the Planning state.
 * 
 * @return A string representing the Planning state status.
 */
std::string Planning::getStatus()
{
	return "PLANNING";
}

/**
 * @brief Transitions from Planning to Construction state.
 * 
 * @return A pointer to a new Construction state.
 */
BuildingState* Planning::update()
{
	return new Construction();
}

/**
 * @brief Gets the status of the Construction state.
 * 
 * @return A string representing the Construction state status.
 */
std::string Construction::getStatus()
{
	return "CONSTRUCTION";
}

/**
 * @brief Transitions from Construction to Operational state.
 * 
 * @return A pointer to a new Operational state.
 */
BuildingState* Construction::update()
{
	return new Operational();
}

/**
 * @brief Gets the status of the Operational state.
 * 
 * @return A string representing the Operational state status.
 */
std::string Operational::getStatus()
{
	return "OPERATIONAL";
}

/**
 * @brief Transitions from Operational to Renovation state.
 * 
 * @return A pointer to a new Renovation state.
 */
BuildingState* Operational::update()
{
	return new Renovation();
}

/**
 * @brief Gets the status of the Renovation state.
 * 
 * @return A string representing the Renovation state status.
 */
std::string Renovation::getStatus()
{
	return "RENOVATION";
}

/**
 * @brief Transitions from Renovation back to Operational state.
 * 
 * @return A pointer to a new Operational state.
 */
BuildingState* Renovation::update()
{
	return new Operational();
}