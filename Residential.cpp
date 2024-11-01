#include "Residential.h"

/**
 * @brief Constructs a Residential building.
 * @param num Capacity of the building.
 * @param l Location of the building.
 */
Residential::Residential(int num, std::string l) : Building(num, l)
{
}

/**
 * @brief Destroys the Residential building and cleans up its residents.
 */
Residential::~Residential()
{
    for (size_t i = 0; i < residents.size(); ++i)
    {
        delete residents[i];
    }
}

/**
 * @brief Adds a Citizen to the building.
 * @param c Pointer to the Citizen to add.
 */
void Residential::addCitizen(Citizen* c)
{
    residents.push_back(c);
}

/**
 * @brief Removes a Citizen from the building.
 * @param c Pointer to the Citizen to remove.
 */
void Residential::removeCitizen(Citizen* c)
{
    for (std::vector<Citizen*>::iterator i = residents.begin(); i != residents.end(); i++)
    {
        if (*i == c)
        {
            i = residents.erase(i);
            return;
        }
    }
}

/**
 * @brief Consumes resources for the Residential building.
 */
void Residential::consumeResources()
{
    std::cout << "Residential building is consuming resources." << std::endl;
}

/**
 * @brief Gets the list of residents in the building.
 * @return A vector containing pointers to the residents.
 */
std::vector<Citizen*> Residential::getResidents()
{
    return residents;
}

/**
 * @brief Constructs an Estate.
 * @param num Capacity of the estate.
 * @param l Location of the estate.
 */
Estate::Estate(int num, std::string l) : Residential(num, l)
{
}

/**
 * @brief Destroys the Estate and cleans up its buildings.
 */
Estate::~Estate()
{
    for (size_t i = 0; i < buildings.size(); ++i)
    {
        delete buildings[i];
    }
}

/**
 * @brief Adds a Residential building to the estate.
 * @param b Pointer to the Residential building to add.
 */
void Estate::addBuilding(Residential* b)
{
    buildings.push_back(b);
}

/**
 * @brief Removes a Residential building from the estate.
 * @param b Pointer to the Residential building to remove.
 */
void Estate::removeBuilding(Residential* b)
{
    for (std::vector<Residential*>::iterator i = buildings.begin(); i != buildings.end(); i++)
    {
        if (*i == b)
        {
            i = buildings.erase(i);
            return;
        }
    }
}

/**
 * @brief Constructs a new Estate object.
 * @return A pointer to the new Estate.
 */
Building* Estate::build()
{
    return new Estate(capacity, location);
}

/**
 * @brief Increases the satisfaction level of residents in the estate.
 */
void Estate::increaseSatisfaction()
{
    std::cout << "Estate has neutral satisfaction for residents." << std::endl;
}

/**
 * @brief Consumes resources for the estate.
 */
void Estate::consumeResources()
{
    std::cout << "Estate consumes basic resources." << std::endl;
}
