#include "Satisfaction.h"

/**
 * @brief Gets the current satisfaction status.
 * @return The status of satisfaction as a string.
 */
std::string Satisfaction::getStatus()
{
    return this->status;
}

/**
 * @brief Constructs a Satisfied object and sets the status to "Satisfied".
 */
Satisfied::Satisfied()
{
    this->status = "Satisfied";
}

/**
 * @brief Attempts to raise the satisfaction level.
 * @return A pointer to the current Satisfied object (since it's already at the highest level).
 */
Satisfaction* Satisfied::raiseStatus()
{
    //std::cout << "Already at highest satisfaction level." << std::endl;
    return this;
}

/**
 * @brief Lowers the satisfaction level to Neutral.
 * @return A pointer to a new Neutral object.
 */
Satisfaction* Satisfied::lowerStatus()
{
    return new Neutral();
}

/**
 * @brief Constructs a Neutral object and sets the status to "Neutral".
 */
Neutral::Neutral()
{
    this->status = "Neutral";
}

/**
 * @brief Raises the satisfaction level to Satisfied.
 * @return A pointer to a new Satisfied object.
 */
Satisfaction* Neutral::raiseStatus()
{
    return new Satisfied();
}

/**
 * @brief Lowers the satisfaction level to Unsatisfied.
 * @return A pointer to a new Unsatisfied object.
 */
Satisfaction* Neutral::lowerStatus()
{
    return new Unsatisfied();
}

/**
 * @brief Constructs an Unsatisfied object and sets the status to "Unsatisfied".
 */
Unsatisfied::Unsatisfied()
{
    this->status = "Unsatisfied";
}

/**
 * @brief Raises the satisfaction level to Neutral.
 * @return A pointer to a new Neutral object.
 */
Satisfaction* Unsatisfied::raiseStatus()
{
    return new Neutral();
}

/**
 * @brief Attempts to lower the satisfaction level.
 * @return A pointer to the current Unsatisfied object (since it's already at the lowest level).
 */
Satisfaction* Unsatisfied::lowerStatus()
{
    //std::cout << "Already at lowest satisfaction level." << std::endl;
    return this;
}

