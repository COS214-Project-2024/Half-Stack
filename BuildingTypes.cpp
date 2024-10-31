#include "BuildingTypes.h"

House::House(int num, std::string  l) : Residential(num, l)
{
	
}

Building* House::build()
{
	return new House(capacity, location);
}

House::~House()
{

}

void House::increaseSatisfaction()
{
	std::cout << "House has neutral satisfaction for residents." << std::endl;
}

void House::consumeResources()
{
	std::cout << "House consumes basic resources." << std::endl;
}

Apartment::Apartment(int num, std::string  l) : Residential(num, l)
{
	
}

Apartment::~Apartment()
{

}

Building* Apartment::build()
{
	return new Apartment(capacity, location);
}

void Apartment::increaseSatisfaction()
{
	std::cout << "Apartment has neutral satisfaction for residents." << std::endl;
}

void Apartment::consumeResources()
{
	std::cout << "Apartment consumes basic resources." << std::endl;
}

TownHouse::TownHouse(int num, std::string  l) : Residential(num, l)
{
	
}

TownHouse::~TownHouse()
{

}

Building* TownHouse::build()
{
	return new TownHouse(capacity, location);	
}

void TownHouse::increaseSatisfaction()
{
	std::cout << "TownHouse has neutral satisfaction for residents." << std::endl;
}

void TownHouse::consumeResources()
{
	std::cout << "TownHouse consumes basic resources." << std::endl;
}

Shop::Shop(int num, std::string  l) : Commercial(num, l)
{
	
}

Shop::~Shop()
{

}

Building* Shop::build()
{
	return new Shop(capacity, location);
}

Office::Office(int num, std::string  l) : Commercial(num, l)
{
	
}

Office::~Office()
{

}

Building* Office::build()
{
	return new Office(capacity, location);
}

Mall::Mall(int num, std::string  l) : Commercial(num, l)
{
	
}

Mall::~Mall()
{

}

Building* Mall::build()
{
	return new Mall(capacity, location);
}

Factory::Factory(int num, std::string  l) : Industrial(num, l)
{
	
}

Factory::~Factory()
{

}

Building* Factory::build()
{
	return new Factory(capacity, location);
}

Warehouse::Warehouse(int num, std::string  l) : Industrial(num, l)
{
	
}

Warehouse::~Warehouse()
{

}

Building* Warehouse::build()
{
	return new Warehouse(capacity, location);
}

Park::Park(int num, std::string  l) : Landmark(num, l)
{
	
}

Park::~Park()
{

}

Building* Park::build()
{
	return new Park(capacity, location);
}

Monument::Monument(int num, std::string  l) : Landmark(num, l)
{
	
}

Monument::~Monument()
{

}

Building* Monument::build()
{
	return new Monument(capacity, location);
}

CulturalCentre::CulturalCentre(int num, std::string  l) : Landmark(num, l)
{
	
}

CulturalCentre::~CulturalCentre()
{
	
}

Building* CulturalCentre::build()
{
	return new CulturalCentre(capacity, location);
}
