#ifndef RESIDENTIALDECORATOR_H
#define RESIDENTIALDECORATOR_H

#include "Residential.h"

/**
 * @class Amenity
 * @brief A base decorator class for adding amenities to a residential area.
 * 
 * This class provides a way to decorate a Residential object with additional features
 * like increased satisfaction and resource consumption.
 */
class Amenity : public Residential
{
protected:
    Residential* amenity; ///< Pointer to the decorated Residential object.

public:
    /**
     * @brief Constructs an Amenity decorator.
     * @param amen Pointer to the Residential object to decorate.
     */
    Amenity(Residential* amen);

    /**
     * @brief Destroys the Amenity decorator and cleans up the decorated Residential object.
     */
    virtual ~Amenity();

    /**
     * @brief Consumes resources associated with the amenity.
     * 
     * This function calls the consumeResources method of the decorated Residential object.
     */
    virtual bool consumeResources()=0;

    /**
     * @brief Prototype function not needed in amenity
     * 
     * This function returns null
     */
    Building* build() {return NULL;}
};

/**
 * @class Garden
 * @brief A decorator that adds a Garden amenity to a Residential object.
 */
class Garden : public Amenity
{
public:
    /**
     * @brief Constructs a Garden decorator.
     * @param amen Pointer to the Residential object to decorate.
     */
    Garden(Residential* amen);

    /**
     * @brief Consumes extra water resources for the Garden.
     * 
     * @return if amenity successfully consumed resources
     */
    bool consumeResources() override;

    /**
     * @brief Consumes extra water resources for the Garden.
     */
    void consumeWater();

};

/**
 * @class Internet
 * @brief A decorator that adds Internet service to a Residential object.
 */
class Internet : public Amenity
{
public:
    /**
     * @brief Constructs an Internet decorator.
     * @param amen Pointer to the Residential object to decorate.
     */
    Internet(Residential* amen);

    /**
     * @brief Consumes extra power resources for the Garden.
     * 
     * @return if amenity successfully consumed resources
     */
    bool consumeResources() override;

    /**
     * @brief Consumes extra power resources for the Garden.
     */
    void consumePower();

};

/**
 * @class Gym
 * @brief A decorator that adds a Gym facility to a Residential object.
 */
class Gym : public Amenity
{
public:
    /**
     * @brief Constructs a Gym decorator.
     * @param amen Pointer to the Residential object to decorate.
     */
    Gym(Residential* amen);

    /**
     * @brief Consumes extra power resources for the Garden.
     * 
     * @return if amenity successfully consumed resources
     */
    bool consumeResources() override;

    /**
     * @brief Consumes extra power resources for the Garden.
     */
    void consumePower();

};

/**
 * @class Pool
 * @brief A decorator that adds a Swimming Pool to a Residential object.
 */
class Pool : public Amenity
{
public:
    /**
     * @brief Constructs a Pool decorator.
     * @param amen Pointer to the Residential object to decorate.
     */
    Pool(Residential* amen);

    /**
     * @brief Consumes extra water resources for the Garden.
     * 
     * @return if amenity successfully consumed resources
     */
    bool consumeResources() override;

    /**
     * @brief Consumes extra water resources for the Garden.
     */
    void consumeWater();

};

#endif
