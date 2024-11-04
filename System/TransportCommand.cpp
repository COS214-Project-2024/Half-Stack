#include "TransportCommand.h"

/**
 * @brief Executes the command to open the transport service.
 * 
 * This function calls the `open` method on the associated transport service to initiate its operations.
 */
void OpenBusiness::execute(Transportation* Transport)
{
    Transport->open();
}

/**
 * @brief Checks the current status of the transport service for an open operation.
 * 
 * @return `true` if the transport service is open, `false` otherwise.
 */
bool OpenBusiness::getStatus()
{
    return open;
}

/**
 * @brief Executes the command to close the transport service.
 * 
 * This function calls the `close` method on the associated transport service to halt its operations.
 */
void CloseBusiness::execute(Transportation* Transport)
{
    Transport->close();
}

/**
 * @brief Checks the current status of the transport service for a close operation.
 * 
 * @return `true` if the transport service is closed, `false` otherwise.
 */
bool CloseBusiness::getStatus()
{
    return close;
}
