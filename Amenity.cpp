#include "Amenity.h"

Amenity::Amenity(Residential* amen) : Residential(0, ""), amenity(amen)
{
	
}

void Amenity::increaseSatisfaction()
{
	amenity->increaseSatisfaction();
}

void Amenity::consumeResources()
{
    amenity->consumeResources();
}

Gym::Gym(Residential *amen) : Amenity(amen)
{   

}

void Gym::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Gym consumes extra electricity." << std::endl;
}

void Gym::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();  // Call base method if other amenities exist

    std::cout << "Gym is increasing satisfaction for all residents." << std::endl;

    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++) 
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

Pool::Pool(Residential *amen) : Amenity(amen)
{

}

void Pool::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Swimming Pool consumes extra water." << std::endl;
}

void Pool::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();  // Call base method if other amenities exist

    std::cout << "Pool is increasing satisfaction for all residents." << std::endl;

    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++) 
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

Internet::Internet(Residential *amen) : Amenity(amen)
{

}

void Internet::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Internet consumes extra power." << std::endl;
}

void Internet::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();  // Call base method if other amenities exist

    std::cout << "Internet is increasing satisfaction for all residents." << std::endl;

    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++) 
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

Garden::Garden(Residential *amen) : Amenity(amen)
{

}

void Garden::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Garden consumes extra water." << std::endl;
}

void Garden::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();  // Call base method if other amenities exist

    std::cout << "Garden is increasing satisfaction for all residents." << std::endl;

    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++) 
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}
