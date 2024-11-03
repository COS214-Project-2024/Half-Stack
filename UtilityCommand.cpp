#include "UtilityCommand.h"
//#include "Government.h"

UtilityCommand::UtilityCommand()
{
    //Government* gov = Government::instance(" "); 
}
/**
 * @brief Executes the command to supply water through the utilities department.
 * 
 * This function calls the `supplyWater` method on the `UtilitiesDepart` to initiate water supply.
 */
void SupplyWater::execute()
{
    if (UtilitiesDepart==NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->supplyWater();
}

/**
 * @brief Checks the current water supply status.
 * 
 * @return `true` if water is being supplied (i.e., `water` level is greater than 0), `false` otherwise.
 */
bool SupplyWater::getStatus()
{
    return water > 0;
}

/**
 * @brief Executes the command to supply power through the utilities department.
 * 
 * This function calls the `supplyEnergy` method on the `UtilitiesDepart` to initiate energy supply.
 */
void SupplyPower::execute()
{
    if (UtilitiesDepart==NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->supplyEnergy();
}

/**
 * @brief Checks the current power supply status.
 * 
 * @return `true` if energy is being supplied (i.e., `energy` level is greater than 0), `false` otherwise.
 */
bool SupplyPower::getStatus()
{
    return energy > 0;
}

/**
 * @brief Executes the command to manage waste through the utilities department.
 * 
 * This function calls the `manageWaste` method on the `UtilitiesDepart` to initiate waste management operations.
 */
void ManageWaste::execute()
{
    if (UtilitiesDepart==NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->manageWaste();
}

/**
 * @brief Checks the current waste management status.
 * 
 * @return `true` if waste management is operational (indicated by `open` being true), `false` otherwise.
 */
bool ManageWaste::getStatus()
{
    return open;
}

/**
 * @brief Executes the command to manage sewage through the utilities department.
 * 
 * This function calls the `manageSewage` method on the `UtilitiesDepart` to initiate sewage management operations.
 */
void ManageSewage::execute()
{
    if (UtilitiesDepart==NULL)
    {
        UtilitiesDepart = UtilitiesDepartment::instance();
    }
    UtilitiesDepart->manageSewage();
}

/**
 * @brief Checks the current sewage management status.
 * 
 * @return `true` if sewage management is operational (indicated by `open` being true), `false` otherwise.
 */
bool ManageSewage::getStatus()
{
    return open;
}
