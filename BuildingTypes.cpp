#include "BuildingTypes.h"

House::House(int num, std::string  l) : Residential(num, l)
{
	
}

Building* House::build()
{
	return new House(capacity, location);
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

Building* Shop::build()
{
	return new Shop(capacity, location);
}

Office::Office(int num, std::string  l) : Commercial(num, l)
{
	
}

Building* Office::build()
{
	return new Office(capacity, location);
}

Mall::Mall(int num, std::string  l) : Commercial(num, l)
{
	
}

Building* Mall::build()
{
	return new Mall(capacity, location);
}

Factory::Factory(int num, std::string  l) : Industrial(num, l)
{
	
}

Building* Factory::build()
{
	return new Factory(capacity, location);
}

Warehouse::Warehouse(int num, std::string  l) : Industrial(num, l)
{
	
}

Building* Warehouse::build()
{
	return new Warehouse(capacity, location);
}

Park::Park(int num, std::string  l) : Landmark(num, l)
{
	
}

Building* Park::build()
{
	return new Park(capacity, location);
}

Monument::Monument(int num, std::string  l) : Landmark(num, l)
{
	
}

Building* Monument::build()
{
	return new Monument(capacity, location);
}

CulturalCentre::CulturalCentre(int num, std::string  l) : Landmark(num, l)
{
	
}

Building* CulturalCentre::build()
{
	return new CulturalCentre(capacity, location);
}