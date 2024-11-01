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
     * @brief Increases the satisfaction level of residents.
     * 
     * This function calls the increaseSatisfaction method of the decorated Residential object.
     */
    virtual void increaseSatisfaction();

    /**
     * @brief Consumes resources associated with the amenity.
     * 
     * This function calls the consumeResources method of the decorated Residential object.
     */
    virtual void consumeResources();
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
     */
    void consumeResources() override;

    /**
     * @brief Increases the satisfaction level of residents due to the Garden.
     */
    void increaseSatisfaction() override;
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
     * @brief Consumes extra power resources for the Internet service.
     */
    void consumeResources() override;

    /**
     * @brief Increases the satisfaction level of residents due to Internet service.
     */
    void increaseSatisfaction() override;
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
     * @brief Consumes extra electricity resources for the Gym.
     */
    void consumeResources() override;

    /**
     * @brief Increases the satisfaction level of residents due to the Gym.
     */
    void increaseSatisfaction() override;
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
     * @brief Consumes extra water resources for the Pool.
     */
    void consumeResources() override;

    /**
     * @brief Increases the satisfaction level of residents due to the Pool.
     */
    void increaseSatisfaction() override;
};

#endif
