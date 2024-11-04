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
        //this->increaseSatisfaction();
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
bool Amenity::consumeResources()
{
    if (amenity != NULL)
    {
        return amenity->consumeResources();
    }
    return false;
}

/**
 * @brief Constructs a Gym decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Gym::Gym(Residential* amen) : Amenity(amen)
{
}

/**
* @brief Consumes extra power resources for the Garden.
* 
* @return if amenity successfully consumed resources
*/
bool Gym::consumeResources()
{
    std::cout << "Gym consumes extra electricity." << std::endl;
    bool r= Amenity::consumeResources();
    consumePower();
    return r;
}

/**
* @brief Consumes extra power resources for the Garden.
*/
void Gym::consumePower()
{
    amenity->increasePowerConsumption(2);
}


/**
 * @brief Constructs a Pool decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Pool::Pool(Residential* amen) : Amenity(amen)
{
}

/**
* @brief Consumes extra water resources for the Garden.
* 
* @return if amenity successfully consumed resources
*/
bool Pool::consumeResources()
{
    std::cout << "Swimming Pool consumes extra water." << std::endl;
    bool r= Amenity::consumeResources();
    consumeWater();
    return r;
}

/**
* @brief Consumes extra water resources for the Garden.
*/
void Pool::consumeWater()
{
    amenity->increaseWaterConsumption(5);
}



/**
 * @brief Constructs an Internet decorator.
 * @param amen Pointer to the Residential object to decorate.
 */
Internet::Internet(Residential* amen) : Amenity(amen)
{
}

/**
* @brief Consumes extra power resources for the Garden.
* 
* @return if amenity successfully consumed resources
*/
bool Internet::consumeResources()
{
    std::cout << "Internet consumes extra power." << std::endl;
    bool r=Amenity::consumeResources();
    consumePower();
    return r;
}

/**
* @brief Consumes extra power resources for the Garden.
*/
void Internet::consumePower()
{
    amenity->increasePowerConsumption(1);
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
* 
* @return if amenity successfully consumed resources
*/
bool Garden::consumeResources()
{
    std::cout << "Garden consumes extra water." << std::endl;
    bool r=Amenity::consumeResources();
    consumeWater();
    return r;
}

/**
* @brief Consumes extra water resources for the Garden.
*/
void Garden::consumeWater()
{
    amenity->increaseWaterConsumption(2);
}
