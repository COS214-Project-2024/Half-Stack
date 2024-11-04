#include "LawDepartment.h"

LawDepartment* LawDepartment::uniqueInstance;

/** 
* @brief Sets the law department singleton instance to ensure that only one instance is created
* @return Returns the instance. Now we can use the LawDepartment functionality through this instance
*/
LawDepartment *LawDepartment::instance()
{
    if(uniqueInstance == nullptr)
	{
		uniqueInstance = new LawDepartment();
	}

	return uniqueInstance;
}

/**
 * @brief Adds a new law to the vector of laws. 
 * 
 * First we must see if the law does not already exist before adding it. 
 * If it does already exist, display a message to the user indicating that the law already exists
 * Otherwise, add the law
 * 
 * @param l The law that the user sends in. A string variable describing the law
*/
void LawDepartment::addLaw(std::string l)
{
	std::vector<std::string>::iterator it = this->laws.begin();
	bool found = false;

	for(; it != this->laws.end(); ++it)
	{
		if(*it == l)
		{
			found = true;
		}
	}

	if(found == false)
	{
		this->laws.push_back(l);
	}
	else
	{
		std::cout << "Law already exists" << std::endl;
	}
}

/**
* @brief Removes a law from the vector of laws.
*
* First we must see if the law exists before removing it.
* If it does not exist, display a message to the user indicating that the law does not exist
* Otherwise, remove the law
*
* @param l The law that the user sends in
*/
void LawDepartment::removeLaw(std::string l) 
{
	std::vector<std::string>::iterator it = this->laws.begin();
	bool found = false;

	for(; it != this->laws.end(); ++it)
	{
		if((*it) == l)
		{
			found = true;
			this->laws.erase(it);
			break;
		}
	}

	if(found == false)
	{
		std::cout << "Law was not found" << std::endl;
	}
}

/**
 * @brief Cleans up any dynamically allocated memory. Deletes the instance, effectively cleaning up memory
 */
LawDepartment::~LawDepartment()
{
	delete uniqueInstance;
}

/**
 * @brief This functions gets and list(vector) that holds all the laws and returns it to the user
 * 
 * @return The vector that holds all the laws that the user set up to this point
 */
std::vector<std::string> LawDepartment::getAllLaws()
{
    return this->laws;
}
