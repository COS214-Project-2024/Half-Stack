#include "UtilityCommand.h"
//#include "Government.h"

UtilityCommand::UtilityCommand()
{
    //Government* gov = Government::instance(" "); 
}
/**
 * @brief Executes the command to supply water through the utilities department.
 * 
 * This function ensures that an instance of the `UtilitiesDepartment` exists and then calls 
 * the `supplyWater` method on it to initiate water supply for the city.
 */
void SupplyWater::execute()
{
    if (UtilitiesDepart == NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->supplyWater();
}

/**
 * @brief Checks the current water supply status.
 * 
 * Determines if water supply is active by checking if the `water` level is greater than 0.
 * 
 * @return `true` if water is currently being supplied, `false` otherwise.
 */
bool SupplyWater::getStatus()
{
    return water > 0;
}

/**
 * @brief Executes the command to supply power through the utilities department.
 * 
 * This function ensures that an instance of the `UtilitiesDepartment` exists and then calls 
 * the `supplyEnergy` method on it to start supplying energy to the city.
 */
void SupplyPower::execute()
{
    if (UtilitiesDepart == NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->supplyEnergy();
}

/**
 * @brief Checks the current power supply status.
 * 
 * Determines if power supply is active by checking if the `energy` level is greater than 0.
 * 
 * @return `true` if energy is currently being supplied, `false` otherwise.
 */
bool SupplyPower::getStatus()
{
    return energy > 0;
}

/**
 * @brief Executes the command to manage waste through the utilities department.
 * 
 * This function ensures that an instance of the `UtilitiesDepartment` exists and then calls 
 * the `manageWaste` method on it to handle waste management operations for the city.
 */
void ManageWaste::execute()
{
    if (UtilitiesDepart == NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->manageWaste();
}

/**
 * @brief Checks the current waste management status.
 * 
 * Determines if waste management is active by checking if `open` is set to `true`.
 * 
 * @return `true` if waste management is operational, `false` otherwise.
 */
bool ManageWaste::getStatus()
{
    return open;
}

/**
 * @brief Executes the command to manage sewage through the utilities department.
 * 
 * This function ensures that an instance of the `UtilitiesDepartment` exists and then calls 
 * the `manageSewage` method on it to handle sewage management operations for the city.
 */
void ManageSewage::execute()
{
    if (UtilitiesDepart == NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->manageSewage();
}

/**
 * @brief Checks the current sewage management status.
 * 
 * Determines if sewage management is active by checking if `open` is set to `true`.
 * 
 * @return `true` if sewage management is operational, `false` otherwise.
 */
bool ManageSewage::getStatus()
{
    return open;
}
