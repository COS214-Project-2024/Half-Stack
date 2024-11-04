#include "BuildingTypes.h"

/**
 * @brief Constructs a new House object.
 * 
 * Initializes a House with the specified capacity and location.
 * 
 * @param num The initial capacity of the House.
 * @param loc The location of the House.
 */
House::House(int num, std::string  l) : Residential(num, l)
{
	
}

/**
 * @brief Builds a House.
 * 
 * Decreases resource levels necessary to construct the House. If successful,
 * returns a new House object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed House or nullptr if
 * resources are insufficient.
 */
Building* House::build()
{
	if (this->resourceManager->decreaseResourceLevels(5, 15, 20, 20, 40) == true)
	{
		return new House(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Apartment object.
 * 
 * Initializes an Apartment with the specified capacity and location.
 * 
 * @param num The initial capacity of the Apartment.
 * @param loc The location of the Apartment.
 */
Apartment::Apartment(int num, std::string  l) : Residential(num, l)
{
	
}

/**
 * @brief Builds an Apartment.
 * 
 * Decreases resource levels necessary to construct the Apartment. If successful,
 * returns a new Apartment object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Apartment or nullptr if
 * resources are insufficient.
 */
Building* Apartment::build()
{
	if (this->resourceManager->decreaseResourceLevels(5, 10, 12, 12, 20) == true)
	{
		return new Apartment(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new TownHouse object.
 * 
 * Initializes a TownHouse with the specified capacity and location.
 * 
 * @param num The initial capacity of the TownHouse.
 * @param loc The location of the TownHouse.
 */
TownHouse::TownHouse(int num, std::string  l) : Residential(num, l)
{
	
}

/**
 * @brief Builds a TownHouse.
 * 
 * Decreases resource levels necessary to construct the TownHouse. If successful,
 * returns a new TownHouse object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed TownHouse or nullptr if
 * resources are insufficient.
 */
Building* TownHouse::build()
{
	if (this->resourceManager->decreaseResourceLevels(5, 10, 12, 12, 20) == true)
	{
		return new TownHouse(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Shop object.
 * 
 * Initializes a Shop with the specified capacity and location.
 * 
 * @param num The initial capacity of the Shop.
 * @param loc The location of the Shop.
 */
Shop::Shop(int num, std::string  l) : Commercial(num, l)
{
	
}

/**
 * @brief Builds a Shop.
 * 
 * Decreases resource levels necessary to construct the Shop. If successful,
 * returns a new Shop object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Shop or nullptr if
 * resources are insufficient.
 */
Building* Shop::build()
{
	if (this->resourceManager->decreaseResourceLevels(10, 15, 25, 25, 48) == true)
	{
		return new Shop(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Office object.
 * 
 * Initializes an Office with the specified capacity and location.
 * 
 * @param num The initial capacity of the Office.
 * @param loc The location of the Office.
 */
Office::Office(int num, std::string  l) : Commercial(num, l)
{
	
}

/**
 * @brief Builds an Office.
 * 
 * Decreases resource levels necessary to construct the Office. If successful,
 * returns a new Office object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Office or nullptr if
 * resources are insufficient.
 */
Building* Office::build()
{
	if (this->resourceManager->decreaseResourceLevels(10, 15, 25, 25, 50) == true)
	{
		return new Office(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Mall object.
 * 
 * Initializes a Mall with the specified capacity and location.
 * 
 * @param num The initial capacity of the Mall.
 * @param loc The location of the Mall.
 */
Mall::Mall(int num, std::string  l) : Commercial(num, l)
{
	
}

/**
 * @brief Builds a Mall.
 * 
 * Decreases resource levels necessary to construct the Mall. If successful,
 * returns a new Mall object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Mall or nullptr if
 * resources are insufficient.
 */
Building* Mall::build()
{
	if (this->resourceManager->decreaseResourceLevels(25, 60, 100, 100, 200))
	{
		return new Mall(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Factory object.
 * 
 * Initializes a Factory with the specified capacity and location.
 * 
 * @param num The initial capacity of the Factory.
 * @param loc The location of the Factory.
 */
Factory::Factory(int num, std::string  l) : Industrial(num, l)
{
	
}

/**
 * @brief Builds a Factory.
 * 
 * Decreases resource levels necessary to construct the Factory. If successful,
 * returns a new Factory object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Factory or nullptr if
 * resources are insufficient.
 */
Building* Factory::build()
{
	if (this->resourceManager->decreaseResourceLevels(30, 100, 50, 150, 150) == true)
	{
		return new Factory(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Warehouse object.
 * 
 * Initializes a Warehouse with the specified capacity and location.
 * 
 * @param num The initial capacity of the Warehouse.
 * @param loc The location of the Warehouse.
 */
Warehouse::Warehouse(int num, std::string  l) : Industrial(num, l)
{
	
}

/**
 * @brief Builds a Warehouse.
 * 
 * Decreases resource levels necessary to construct the Warehouse. If successful,
 * returns a new Warehouse object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Warehouse or nullptr if
 * resources are insufficient.
 */
Building* Warehouse::build()
{
	if (this->resourceManager->decreaseResourceLevels(30, 40, 100, 60, 90) == true)
	{
		return new Warehouse(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Park object.
 * 
 * Initializes a Park with the specified capacity and location.
 * 
 * @param num The initial capacity of the Park.
 * @param loc The location of the Park.
 */
Park::Park(int num, std::string  l) : Landmark(num, l)
{
	
}

/**
 * @brief Builds a Park.
 * 
 * Decreases resource levels necessary to construct the Park. If successful,
 * returns a new Park object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Park or nullptr if
 * resources are insufficient.
 */
Building* Park::build()
{
	if (this->resourceManager->decreaseResourceLevels(40, 15, 50, 20, 40) == true)
	{
		return new Park(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new Monument object.
 * 
 * Initializes a Monument with the specified capacity and location.
 * 
 * @param num The initial capacity of the Monument.
 * @param loc The location of the Monument.
 */
Monument::Monument(int num, std::string  l) : Landmark(num, l)
{
	
}

/**
 * @brief Builds a Monument.
 * 
 * Decreases resource levels necessary to construct the Monument. If successful,
 * returns a new Monument object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed Monument or nullptr if
 * resources are insufficient.
 */
Building* Monument::build()
{
	if (this->resourceManager->decreaseResourceLevels(25, 25, 20, 55, 50))
	{
		return new Monument(capacity, location);
	}
	else
	{
		return nullptr;
	}
}

/**
 * @brief Constructs a new CulturalCentre object.
 * 
 * Initializes a CulturalCentre with the specified capacity and location.
 * 
 * @param num The initial capacity of the CulturalCentre.
 * @param loc The location of the CulturalCentre.
 */
CulturalCentre::CulturalCentre(int num, std::string  l) : Landmark(num, l)
{
	
}

/**
 * @brief Builds a CulturalCentre.
 * 
 * Decreases resource levels necessary to construct the CulturalCentre. If successful,
 * returns a new CulturalCentre object; otherwise, returns nullptr.
 * 
 * @return Building* Pointer to the newly constructed CulturalCentre or nullptr if
 * resources are insufficient.
 */
Building* CulturalCentre::build()
{
	if (this->resourceManager->decreaseResourceLevels(20, 30, 65, 65, 65) == true)
	{
		return new CulturalCentre(capacity, location);
	}
	else
	{
		return nullptr;
	}
}