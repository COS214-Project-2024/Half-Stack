#include "Amenity.h"

/**
 * @brief Constructs an Amenity decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Amenity::Amenity(Residential* amen) : Residential(0, ""), amenity(amen)
{
}

/**
 * @brief Destroys the Amenity decorator and cleans up the decorated Residential object.
 */
Amenity::~Amenity()
{
    delete amenity;
}

/**
 * @brief Increases the satisfaction level of residents.
 */
void Amenity::increaseSatisfaction()
{
    amenity->increaseSatisfaction();
}

/**
 * @brief Consumes resources associated with the amenity.
 */
void Amenity::consumeResources()
{
    amenity->consumeResources();
}

/**
 * @brief Constructs a Gym decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Gym::Gym(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Destroys the Gym decorator.
 */
Gym::~Gym()
{
}

/**
 * @brief Consumes extra electricity resources for the Gym.
 */
void Gym::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Gym consumes extra electricity." << std::endl;
}

/**
 * @brief Increases the satisfaction level of residents due to the Gym.
 */
void Gym::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();
    std::cout << "Gym is increasing satisfaction for all residents." << std::endl;
    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++)
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

/**
 * @brief Constructs a Pool decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Pool::Pool(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Destroys the Pool decorator.
 */
Pool::~Pool()
{
}

/**
 * @brief Consumes extra water resources for the Pool.
 */
void Pool::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Swimming Pool consumes extra water." << std::endl;
}

/**
 * @brief Increases the satisfaction level of residents due to the Pool.
 */
void Pool::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();
    std::cout << "Pool is increasing satisfaction for all residents." << std::endl;
    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++)
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

/**
 * @brief Constructs an Internet decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Internet::Internet(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Destroys the Internet decorator.
 */
Internet::~Internet()
{
}

/**
 * @brief Consumes extra power resources for the Internet service.
 */
void Internet::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Internet consumes extra power." << std::endl;
}

/**
 * @brief Increases the satisfaction level of residents due to Internet service.
 */
void Internet::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();
    std::cout << "Internet is increasing satisfaction for all residents." << std::endl;
    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++)
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}

/**
 * @brief Constructs a Garden decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Garden::Garden(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Destroys the Garden decorator.
 */
Garden::~Garden()
{
}

/**
 * @brief Consumes extra water resources for the Garden.
 */
void Garden::consumeResources()
{
    Amenity::consumeResources();
    std::cout << "Garden consumes extra water." << std::endl;
}

/**
 * @brief Increases the satisfaction level of residents due to the Garden.
 */
void Garden::increaseSatisfaction()
{
    Amenity::increaseSatisfaction();
    std::cout << "Garden is increasing satisfaction for all residents." << std::endl;
    std::vector<Citizen*> residents = this->amenity->getResidents();
    for (size_t i = 0; i < residents.size(); i++)
    {
        Citizen* citizen = residents[i];
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
}
