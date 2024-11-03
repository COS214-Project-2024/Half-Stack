#ifndef TRANSPORTCOMMAND_H
#define TRANSPORTCOMMAND_H

#include "Transportation.h"

/**
 * @brief Abstract base class representing a transport command.
 */
class TransportCommand
{
	public:
		//Transportation* Transport; //= new Transportation();
		
        /**
         * @brief Executes the transport command.
         * 
         * This is a pure virtual function that must be overridden by derived classes.
         */
	virtual void execute(Transportation* Transport ) = 0;
        /**
         * @brief Gets the current status of the transport command.
         * 
         * @return bool The status of the command.
         */
        virtual bool getStatus() = 0;

	virtual ~TransportCommand() {};
};


/**
 * @brief Command for opening a business.
 */
class OpenBusiness : public TransportCommand
{

	public:
	bool open;
        /**
         * @brief Executes the command to open a business.
         * 
         * This method implements the logic for opening a business within the transportation system.
         */
        void execute(Transportation* Transport );

        /**
         * @brief Gets the current status of the open business command.
         * 
         * @return bool The status of the business opening operation.
         */
        bool getStatus();
};

/**
 * @brief Command for closing a business.
 */
class CloseBusiness : public TransportCommand
{
    public:
	bool close;
        /**
         * @brief Executes the command to close a business.
         * 
         * This method implements the logic for closing a business within the transportation system.
         */
	void execute(Transportation* Transport );

        /**
         * @brief Gets the current status of the close business command.
         * 
         * @return bool The status of the business closing operation.
         */
        bool getStatus();
};

#endif
