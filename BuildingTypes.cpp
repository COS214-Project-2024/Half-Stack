#include "BuildingTypes.h"

House::House(int num, std::string  l) : Residential(num, l)
{
	
}

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

Apartment::Apartment(int num, std::string  l) : Residential(num, l)
{
	
}

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

TownHouse::TownHouse(int num, std::string  l) : Residential(num, l)
{
	
}

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

Shop::Shop(int num, std::string  l) : Commercial(num, l)
{
	
}

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

Office::Office(int num, std::string  l) : Commercial(num, l)
{
	
}

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

Mall::Mall(int num, std::string  l) : Commercial(num, l)
{
	
}

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

Factory::Factory(int num, std::string  l) : Industrial(num, l)
{
	
}

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

Warehouse::Warehouse(int num, std::string  l) : Industrial(num, l)
{
	
}

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

Park::Park(int num, std::string  l) : Landmark(num, l)
{
	
}

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

Monument::Monument(int num, std::string  l) : Landmark(num, l)
{
	
}

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

CulturalCentre::CulturalCentre(int num, std::string  l) : Landmark(num, l)
{
	
}

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