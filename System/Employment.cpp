#include "Employment.h"

/**
 * @brief Retrieves the status of the employment.
 * @return A string indicating that the citizen is employed.
 */
std::string Employed::getStatus()
{
    return "Employed"; // Returns the employment status as "Employed"
}

/**
 * @brief Toggles the employment status to unemployed.
 * @return A pointer to an Unemployed object.
 */
Employment* Employed::toggleStatus()
{
    return new Unemployed(); // Toggles the status to Unemployed
}

/**
 * @brief Retrieves the status of the employment.
 * @return A string indicating that the citizen is unemployed.
 */
std::string Unemployed::getStatus()
{
    return "Unemployed"; // Returns the employment status as "Unemployed"
}

/**
 * @brief Toggles the employment status to employed.
 * @return A pointer to an Employed object.
 */
Employment* Unemployed::toggleStatus()
{
    return new Employed(); // Toggles the status to Employed
}
