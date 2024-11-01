#include "Amenity.h"

/**
 * @brief Constructs an Amenity decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Amenity::Amenity(Residential* amen) : Residential(0, ""), amenity(amen)
{
    if (amenity != NULL)
    {
        std::vector<Citizen*> residents = this->amenity->getResidents();
        for (size_t i = 0; i < residents.size(); i++)
        {
            Citizen* citizen = residents[i];
            Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
            citizen->setSatisfaction(newStatus);
        }
        this->amenity->increaseSatisfaction();
    }
}

/**
 * @brief Destroys the Amenity decorator and cleans up the decorated Residential object.
 */
Amenity::~Amenity()
{
    if (amenity != NULL)
    {
        delete amenity;
    }
}

/**
 * @brief Consumes resources associated with the amenity.
 */
void Amenity::consumeResources()
{
    if (amenity != NULL)
    {
        amenity->consumeResources();
    }
}

/**
 * @brief Constructs a Gym decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Gym::Gym(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Consumes extra electricity resources for the Gym.
 */
void Gym::consumeResources()
{
    std::cout << "Gym consumes extra electricity." << std::endl;
    Amenity::consumeResources();
}

/**
 * @brief Increases the satisfaction level of residents due to the Gym.
 */
void Gym::increaseSatisfaction()
{
    std::cout << "Gym is increasing satisfaction for all residents." << std::endl;
    Amenity::increaseSatisfaction();
}

/**
 * @brief Constructs a Pool decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Pool::Pool(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Consumes extra water resources for the Pool.
 */
void Pool::consumeResources()
{
    std::cout << "Swimming Pool consumes extra water." << std::endl;
    Amenity::consumeResources();
}

/**
 * @brief Increases the satisfaction level of residents due to the Pool.
 */
void Pool::increaseSatisfaction()
{
    std::cout << "Pool is increasing satisfaction for all residents." << std::endl;
    Amenity::increaseSatisfaction();
}

/**
 * @brief Constructs an Internet decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Internet::Internet(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Consumes extra power resources for the Internet service.
 */
void Internet::consumeResources()
{
    std::cout << "Internet consumes extra power." << std::endl;
    Amenity::consumeResources();
}

/**
 * @brief Increases the satisfaction level of residents due to Internet service.
 */
void Internet::increaseSatisfaction()
{
    std::cout << "Internet is increasing satisfaction for all residents." << std::endl;
    Amenity::increaseSatisfaction();
}

/**
 * @brief Constructs a Garden decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Garden::Garden(Residential* amen) : Amenity(amen)
{
}

/**
 * @brief Consumes extra water resources for the Garden.
 */
void Garden::consumeResources()
{
    std::cout << "Garden consumes extra water." << std::endl;
    Amenity::consumeResources();
}

/**
 * @brief Increases the satisfaction level of residents due to the Garden.
 */
void Garden::increaseSatisfaction()
{
    std::cout << "Garden is increasing satisfaction for all residents." << std::endl;
    Amenity::increaseSatisfaction();
}
