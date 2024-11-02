#ifndef UTILITYCOMMAND_H
#define UTILITYCOMMAND_H

#include "UtilitiesDepartment.h"

/**
 * @brief Abstract base class representing a utility command.
 */
class UtilityCommand
{
    public:
        UtilitiesDepartment* UtilitiesDepart; 

        /**
         * @brief Executes the utility command.
         * 
         * This is a pure virtual function that must be overridden by derived classes.
         */
        virtual void execute() = 0;

        /**
         * @brief Gets the current status of the utility command.
         * 
         * @return bool The status of the command.
         */
        virtual bool getStatus() = 0;
};

/**
 * @brief Command for supplying water.
 */
class SupplyWater : public UtilityCommand
{
    private:
        int water; 

    public:
        /**
         * @brief Executes the water supply command.
         * 
         * This method implements the logic for supplying water through the UtilitiesDepartment.
         */
        void execute();

        /**
         * @brief Gets the current status of the water supply command.
         * 
         * @return bool The status of the water supply operation.
         */
        bool getStatus();
};

/**
 * @brief Command for supplying power.
 */
class SupplyPower : public UtilityCommand
{
    private:
        int energy; 

    public:
        /**
         * @brief Executes the power supply command.
         * 
         * This method implements the logic for supplying power through the UtilitiesDepartment.
         */
        void execute();

        /**
         * @brief Gets the current status of the power supply command.
         * 
         * @return bool The status of the power supply operation.
         */
        bool getStatus();
};

/**
 * @brief Command for managing waste.
 */
class ManageWaste : public UtilityCommand
{
    private:
        bool open;

    public:
        /**
         * @brief Executes the waste management command.
         * 
         * This method implements the logic for managing waste through the UtilitiesDepartment.
         */
        void execute();

        /**
         * @brief Gets the current status of the waste management command.
         * 
         * @return bool The status of the waste management operation.
         */
        bool getStatus();
};

/**
 * @brief Command for managing sewage.
 */
class ManageSewage : public UtilityCommand
{
    private:
        bool open; 

    public:
        /**
         * @brief Executes the sewage management command.
         * 
         * This method implements the logic for managing sewage through the UtilitiesDepartment.
         */
        void execute();

        /**
         * @brief Gets the current status of the sewage management command.
         * 
         * @return bool The status of the sewage management operation.
         */
        bool getStatus();
};

#endif
