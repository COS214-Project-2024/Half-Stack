#ifndef UTILITYCOMMAND_H
#define UTILITYCOMMAND_H

#include "UtilitiesDepartment.h"

class UtilitiesDepartment;

class UtilityCommand
{
    protected:
        UtilitiesDepartment* UtilitiesDepart; /**< Pointer to the utilities department instance. */

    public:
        /**
         * @brief Constructor for UtilityCommand.
         * 
         * Initializes the UtilityCommand and sets up any necessary state.
         */
        UtilityCommand();

        /**
         * @brief Executes the utility command.
         * 
         * This is a pure virtual function that must be implemented by derived classes.
         */
        virtual void execute() = 0;

        /**
         * @brief Retrieves the status of the utility command.
         * 
         * This is a pure virtual function that must be implemented by derived classes.
         * 
         * @return `true` if the utility is active, `false` otherwise.
         */
        virtual bool getStatus() = 0;

        /**
         * @brief Virtual destructor for UtilityCommand.
         */
        virtual ~UtilityCommand() {};
};

/**
 * @brief Command class to supply water through the utilities department.
 */
class SupplyWater : public UtilityCommand
{
    private:
        int water; /**< Level of water currently being supplied. */

    public:
        /**
         * @brief Executes the water supply command.
         * 
         * Ensures an instance of the `UtilitiesDepartment` exists and initiates water supply.
         */
        void execute();

        /**
         * @brief Checks the current water supply status.
         * 
         * @return `true` if water is being supplied (i.e., `water` level is greater than 0), `false` otherwise.
         */
        bool getStatus();
};

/**
 * @brief Command class to supply power through the utilities department.
 */
class SupplyPower : public UtilityCommand
{
    private:
        int energy; /**< Level of energy currently being supplied. */

    public:
        /**
         * @brief Executes the power supply command.
         * 
         * Ensures an instance of the `UtilitiesDepartment` exists and initiates energy supply.
         */
        void execute();

        /**
         * @brief Checks the current power supply status.
         * 
         * @return `true` if energy is being supplied (i.e., `energy` level is greater than 0), `false` otherwise.
         */
        bool getStatus();
};

/**
 * @brief Command class to manage waste through the utilities department.
 */
class ManageWaste : public UtilityCommand
{
    private:
        bool open; /**< Indicates if waste management is active. */

    public:
        /**
         * @brief Executes the waste management command.
         * 
         * Ensures an instance of the `UtilitiesDepartment` exists and initiates waste management operations.
         */
        void execute();

        /**
         * @brief Checks the current waste management status.
         * 
         * @return `true` if waste management is operational (indicated by `open` being true), `false` otherwise.
         */
        bool getStatus();
};

/**
 * @brief Command class to manage sewage through the utilities department.
 */
class ManageSewage : public UtilityCommand
{
    private:
        bool open; /**< Indicates if sewage management is active. */

    public:
        /**
         * @brief Executes the sewage management command.
         * 
         * Ensures an instance of the `UtilitiesDepartment` exists and initiates sewage management operations.
         */
        void execute();

        /**
         * @brief Checks the current sewage management status.
         * 
         * @return `true` if sewage management is operational (indicated by `open` being true), `false` otherwise.
         */
        bool getStatus();
};

#endif
