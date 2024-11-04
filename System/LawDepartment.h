#ifndef LAWDEPARTMENT_H
#define LAWDEPARTMENT_H

#include <iostream>
#include "Department.h"
#include "Building.h"

class LawDepartment : public Department
{
private:
	std::vector<std::string> laws;
	static LawDepartment *uniqueInstance;

protected:
	LawDepartment() { /*std::cout << "New Law department created" << std::endl;*/ };

public:
	/**
	 * @brief Sets the law department singleton instance to ensure that only one instance is created
	 * @return Returns the instance. Now we can use the LawDepartment functionality through this instance
	 */
	static LawDepartment *instance();

	/**
	 * @brief Adds a new law to the vector of laws.
	 *
	 * First we must see if the law does not already exist before adding it.
	 * If it does already exist, display a message to the user indicating that the law already exists
	 * Otherwise, add the law
	 *
	 * @param l The law that the user sends in
	 */
	void addLaw(std::string l);

	/**
	 * @brief Removes a law from the vector of laws.
	 *
	 * First we must see if the law exists before removing it.
	 * If it does not exist, display a message to the user indicating that the law does not exist
	 * Otherwise, remove the law
	 *
	 * @param l The law that the user sends in
	 */
	void removeLaw(std::string l);

	/**
	 * @brief Cleans up any dynamically allocated memory. Sets the instance to null, effectively cleaning up memory
	 */
	~LawDepartment();

	/**
	 * @brief This functions gets and list(vector) that holds all the laws and returns it to the user
	 *
	 * @return The vector that holds all the laws that the user set up to this point
	 */
	std::vector<std::string> getAllLaws();
};

#endif
