#ifndef TRANSPORTCOMMAND_H
#define TRANSPORTCOMMAND_H

#include "Transportation.h"

/**
 * @class TransportCommand
 * @brief Abstract base class for transportation-related commands.
 *
 * Defines an interface for commands that control the operation of a transportation entity. 
 * Derived classes must implement the `execute()` and `getStatus()` methods to perform specific actions.
 */
class TransportCommand
{
	public:
		/**
		 * @brief Executes the transportation command on a specified transportation entity.
		 * 
		 * Pure virtual function to be implemented by derived classes, defining the action 
		 * to be performed on the provided `Transportation` object.
		 * 
		 * @param Transport A pointer to the `Transportation` object on which the command will be executed.
		 */
		virtual void execute(Transportation* Transport) = 0;

		/**
		 * @brief Retrieves the status of the transportation command.
		 * 
		 * Pure virtual function to be implemented by derived classes, indicating the command's success 
		 * or operational state.
		 * 
		 * @return `true` if the command was successful or active; `false` otherwise.
		 */
		virtual bool getStatus() = 0;

		/**
		 * @brief Virtual destructor for TransportCommand.
		 *
		 * Ensures proper cleanup of derived classes when a TransportCommand pointer is deleted.
		 */
		virtual ~TransportCommand() {};
};

/**
 * @class OpenBusiness
 * @brief Command class to open a transportation-related business.
 *
 * Implements the `execute()` method to activate or open a transportation service or business.
 */
class OpenBusiness : public TransportCommand
{
	public:
		bool open; ///< Status indicating whether the business is open.

		/**
		 * @brief Executes the command to open the transportation business.
		 *
		 * Activates the transportation service by performing necessary operations on the 
		 * provided `Transportation` object.
		 * 
		 * @param Transport A pointer to the `Transportation` object to open.
		 */
		void execute(Transportation* Transport);

		/**
		 * @brief Retrieves the open status of the transportation business.
		 * 
		 * @return `true` if the business is open; `false` otherwise.
		 */
		bool getStatus();
};

/**
 * @class CloseBusiness
 * @brief Command class to close a transportation-related business.
 *
 * Implements the `execute()` method to deactivate or close a transportation service or business.
 */
class CloseBusiness : public TransportCommand
{
	public:
		bool close; ///< Status indicating whether the business is closed.

		/**
		 * @brief Executes the command to close the transportation business.
		 *
		 * Deactivates the transportation service by performing necessary operations on the 
		 * provided `Transportation` object.
		 * 
		 * @param Transport A pointer to the `Transportation` object to close.
		 */
		void execute(Transportation* Transport);

		/**
		 * @brief Retrieves the closed status of the transportation business.
		 * 
		 * @return `true` if the business is closed; `false` otherwise.
		 */
		bool getStatus();
};



#endif
