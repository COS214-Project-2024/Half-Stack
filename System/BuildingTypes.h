#ifndef BUILDINGTYPES_H
#define BUILDINGTYPES_H

#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"

/**
 * @class House
 * @brief Represents a residential house.
 * 
 * Inherits from the Residential class and implements the build method.
 */
class House : public Residential
{

public:
	/**
     * @brief Constructs a new House object.
     * 
     * @param num The initial capacity of the house.
     * @param loc The designated location of the house.
     */
	House(int num,  std::string loc);

	/**
     * @brief Builds the house if sufficient resources are available.
     * 
     * @return A pointer to the newly created House object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Apartment
 * @brief Represents a residential apartment.
 * 
 * Inherits from the Residential class and implements the build method.
 */
class Apartment : public Residential
{

public:
	/**
     * @brief Constructs a new Apartment object.
     * 
     * @param num The initial capacity of the apartment.
     * @param loc The designated location of the apartment.
     */
	Apartment(int num, std::string loc);

	/**
     * @brief Builds the apartment if sufficient resources are available.
     * 
     * @return A pointer to the newly created Apartment object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class TownHouse
 * @brief Represents a residential townhouse.
 * 
 * Inherits from the Residential class and implements the build method.
 */
class TownHouse : public Residential
{

public:
	/**
     * @brief Constructs a new TownHouse object.
     * 
     * @param num The initial capacity of the townhouse.
     * @param loc The designated location of the townhouse.
     */
	TownHouse(int num, std::string loc);

	/**
     * @brief Builds the townhouse if sufficient resources are available.
     * 
     * @return A pointer to the newly created TownHouse object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Shop
 * @brief Represents a commercial shop.
 * 
 * Inherits from the Commercial class and implements the build method.
 */
class Shop : public Commercial
{

public:
	/**
     * @brief Constructs a new Shop object.
     * 
     * @param num The initial capacity of the shop.
     * @param loc The designated location of the shop.
     */
	Shop(int num,  std::string loc);

	/**
     * @brief Builds the shop if sufficient resources are available.
     * 
     * @return A pointer to the newly created Shop object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Office
 * @brief Represents a commercial office.
 * 
 * Inherits from the Commercial class and implements the build method.
 */
class Office : public Commercial
{

public:
	/**
     * @brief Constructs a new Office object.
     * 
     * @param num The initial capacity of the office.
     * @param loc The designated location of the office.
     */
	Office(int num, std::string loc);

	/**
     * @brief Builds the office if sufficient resources are available.
     * 
     * @return A pointer to the newly created Office object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Mall
 * @brief Represents a commercial mall.
 * 
 * Inherits from the Commercial class and implements the build method.
 */
class Mall : public Commercial
{

public:
	/**
     * @brief Constructs a new Mall object.
     * 
     * @param num The initial capacity of the mall.
     * @param loc The designated location of the mall.
     */
	Mall(int num,  std::string loc );

	/**
     * @brief Builds the mall if sufficient resources are available.
     * 
     * @return A pointer to the newly created Mall object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Factory
 * @brief Represents an industrial factory.
 * 
 * Inherits from the Industrial class and implements the build method.
 */
class Factory : public Industrial
{

public:
	/**
     * @brief Constructs a new Factory object.
     * 
     * @param num The initial capacity of the factory.
     * @param loc The designated location of the factory.
     */
	Factory(int num, std::string loc);

	/**
     * @brief Builds the factory if sufficient resources are available.
     * 
     * @return A pointer to the newly created Factory object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Warehouse
 * @brief Represents an industrial warehouse.
 * 
 * Inherits from the Industrial class and implements the build method.
 */
class Warehouse : public Industrial
{

public:
	/**
     * @brief Constructs a new Warehouse object.
     * 
     * @param num The initial capacity of the warehouse.
     * @param loc The designated location of the warehouse.
     */
	Warehouse(int num, std::string loc);

	/**
     * @brief Builds the warehouse if sufficient resources are available.
     * 
     * @return A pointer to the newly created Warehouse object, or nullptr if resources are insufficient.
     */
	Building* build();	
};


/**
 * @class Park
 * @brief Represents a landmark park.
 * 
 * Inherits from the Landmark class and implements the build method.
 */
class Park : public Landmark
{

public:
	/**
     * @brief Constructs a new Park object.
     * 
     * @param num The initial capacity of the park.
     * @param loc The designated location of the park.
     */
	Park(int num, std::string loc);

	/**
     * @brief Builds the park if sufficient resources are available.
     * 
     * @return A pointer to the newly created Park object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class Monument
 * @brief Represents a landmark monument.
 * 
 * Inherits from the Landmark class and implements the build method.
 */
class Monument : public Landmark
{

public:
	/**
     * @brief Constructs a new Monument object.
     * 
     * @param num The initial capacity of the monument.
     * @param loc The designated location of the monument.
     */
	Monument(int num, std::string loc);

	/**
     * @brief Builds the monument if sufficient resources are available.
     * 
     * @return A pointer to the newly created Monument object, or nullptr if resources are insufficient.
     */
	Building* build();
};


/**
 * @class CulturalCentre
 * @brief Represents a landmark cultural centre.
 * 
 * Inherits from the Landmark class and implements the build method.
 */
class CulturalCentre : public Landmark
{

public:
	/**
     * @brief Constructs a new CulturalCentre object.
     * 
     * @param num The initial capacity of the cultural centre.
     * @param loc The designated location of the cultural centre.
     */
	CulturalCentre(int num, std::string loc);

	/**
     * @brief Builds the cultural centre if sufficient resources are available.
     * 
     * @return A pointer to the newly created CulturalCentre object, or nullptr if resources are insufficient.
     */
	Building* build();
};

#endif