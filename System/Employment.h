#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H

#include <iostream>
#include <string>

/**
 * @class Employment
 * @brief Abstract base class representing the employment status of a citizen.
 */


class Employment
{
    protected:
        Employment* status;     ///< Pointer to the current employment status.

    public:
        /**
         * @brief Retrieves the status of the employment.
         * @return A string representing the employment status.
         */
        virtual std::string getStatus() = 0;

         /**
         * @brief Toggles the employment status.
         * @return A pointer to the new employment status.
         */
        virtual Employment* toggleStatus() = 0;

        /**
         * @brief Virtual destructor for the Employment class.
         */
        virtual ~Employment() {};

};


/**
 * @class Employed
 * @brief Represents the employed state of a citizen.
 */
class Employed : public Employment
{
    public:
        /**
         * @brief Retrieves the status of the employment.
         * @return A string indicating that the citizen is employed.
         */
        std::string getStatus();

         /**
         * @brief Toggles the employment status to unemployed.
         * @return A pointer to an Unemployed object.
         */
        Employment* toggleStatus();
};


/**
 * @class Unemployed
 * @brief Represents the unemployed state of a citizen.
 */
class Unemployed : public Employment
{
    public:
        /**
         * @brief Retrieves the status of the employment.
         * @return A string indicating that the citizen is unemployed.
         */
        std::string getStatus();

        /**
         * @brief Toggles the employment status to employed.
         * @return A pointer to an Employed object.
         */
        Employment* toggleStatus();
};

#endif
