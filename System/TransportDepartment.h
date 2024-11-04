#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include "Transportation.h"
#include "Department.h"
#include "TransportCommand.h"

class TransportDepartment : public Department
{

private:
	std::vector<std::pair<Transportation *, std::pair<TransportCommand *, TransportCommand *>>> transports;
	static TransportDepartment *uniqueInstance;

protected:
	/**
	 * @brief Default constructor. Only needed for instance creation
	 */
	TransportDepartment();

public:
	/**
	 * @brief Sets the Transport department singleton instance to ensure that only one instance is created
	 * @return Returns the instance. Now we can use the Transport Department functionality through this instance
	 */
	static TransportDepartment *instance();

	/**
 * @brief Adds a new transport business to the vector of transports, if it meets resource and budget requirements
 *
 * This checks if the transport facility does not already exists in the system and if the necessary resource and budget are availible based on the type of transport(Airport, Road, Railway). It handles the resource deductions, budget checks(to see if it is feasible), and rollbacks if the transport cannot be added. If successful, the commands for openTransport and closeTransport are assigned. After all checks have passed, add the transport to the list.
 *
 * @param newTransport Pointer to a Transportation object which represents the transport to be added.
 *
 * 	-If the `newTransport` is an Airport:
 *		-Checks we're not exceeding the maximum number of airports allowed for this city.
		-Attempts to deduct the needed resources and budget specs needed for adding a transport. Rolls back if the addition was unsuccessful.
 *	-If the `newTransport` is an Road or a Railway:
		-Attempts to deduct the needed resources and budget specs needed for adding a transport. Rolls back if the addition was unsuccessful.

 *If we had a successful addition, `newTransport` is paired with open and close business commands and is now stored in the list

 @note If we have any fails, `newTransport` is deleted to prevent memeory leaks.
*/
	void addTransport(Transportation *newTransport);

	/**
	 * @brief Removes a law from the list of transports.
	 *
	 * First we must see if the transport exists before removing it.
	 * If it does not exist, display a message to the user indicating that the transport does not exist
	 * Otherwise, remove the transport
	 * We first delete the commands(open and close business), ensuring we will not have memeory leaks.
	 * Thereafter, we remove the transport
	 *
	 * @param l The transport that the user sends in
	 */
	void removeTransport(Transportation *newTransport);

	/**
	 * @brief Calls the command(openTransport) for every transport inside the list of transports
	 *
	 * Iterates through the vector and calls the execute function stored in the command
	 */
	void openTransport();

	/**
	 * @brief Calls the command(closeTransport) for every transport inside the list of transports
	 *
	 * Iterates through the vector and calls the execute function that calls the command
	 */
	void closeTransport();

	/**
	 * @brief Gets the amount of airports currently set within the city
	 *
	 * @return The amount of airports currently in this city
	 */
	int getTotalAirports();

	/**
	 * @brief Gets the amount of roads currently set within the city
	 *
	 * @return The amount of raods currently in this city
	 */
	int getTotalRoads();

	/**
	 * @brief Gets the amount of railways currently set within the city
	 *
	 * @return The amount of railways currently in this city
	 */
	int getTotalRailways();

	/**
	 * @brief Cleans up any dynamically allocated memory. Cleans up the allocated commands per the transport businesses. Sets the unique instance, effectively cleaning up the memeory
	 */
	~TransportDepartment();
};

#endif
