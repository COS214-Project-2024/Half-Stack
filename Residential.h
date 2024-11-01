#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <vector>
#include "Building.h"
#include "Citizen.h"

/**
 * @class Residential
 * @brief Abstract base class representing a residential building.
 * 
 * A Residential building can house multiple residents and consume resources. 
 * It is an extension of the Building class and must be extended by concrete subclasses.
 */
class Residential : public Building
{
protected:
    std::vector<Citizen*> residents; ///< List of residents living in the building.

public:
    /**
     * @brief Constructs a Residential building.
     * @param num Capacity of the building.
     * @param loc Location of the building.
     */
    Residential(int num, std::string loc);

    /**
     * @brief Destroys the Residential building and its residents.
     */
    virtual ~Residential();

    /**
     * @brief Adds a Citizen to the building.
     * @param c Pointer to the Citizen to add.
     */
    void addCitizen(Citizen* c);

    /**
     * @brief Removes a Citizen from the building.
     * @param c Pointer to the Citizen to remove.
     */
    void removeCitizen(Citizen* c);

    /**
     * @brief Consumes resources for the Residential building.
     */
    void consumeResources();

    /**
     * @brief Pure virtual function to increase satisfaction of residents.
     * 
     * Must be implemented by subclasses.
     */
    virtual void increaseSatisfaction() = 0;

    /**
     * @brief Gets the list of residents in the building.
     * @return A vector containing pointers to the residents.
     */
    std::vector<Citizen*> getResidents();
};

/**
 * @class Estate
 * @brief Concrete class representing an estate that consists of multiple residential buildings.
 */
class Estate : public Residential
{
private:
    std::vector<Residential*> buildings; ///< List of residential buildings in the estate.

public:
    /**
     * @brief Constructs an Estate.
     * @param num Capacity of the estate.
     * @param loc Location of the estate.
     */
    Estate(int num, std::string loc);

    /**
     * @brief Destroys the Estate and its buildings.
     */
    virtual ~Estate();

    /**
     * @brief Adds a Residential building to the estate.
     * @param b Pointer to the Residential building to add.
     */
    void addBuilding(Residential* b);

    /**
     * @brief Removes a Residential building from the estate.
     * @param b Pointer to the Residential building to remove.
     */
    void removeBuilding(Residential* b);

    /**
     * @brief Constructs a new Estate object.
     * @return A pointer to the new Estate.
     */
    Building* build();

    /**
     * @brief Increases the satisfaction level of residents in the estate.
     */
    void increaseSatisfaction();

    /**
     * @brief Consumes resources for the estate.
     */
    void consumeResources();
};

#endif
