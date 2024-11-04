#ifndef SATISFACTION_H
#define SATISFACTION_H

#include <iostream>
#include <string>

/**
 * @class Satisfaction
 * @brief Abstract base class representing the satisfaction level of a citizen.
 */
class Satisfaction
{   
        protected:
                std::string status; ///< Status of the satisfaction level.

        public:
                /**
                 * @brief Gets the current satisfaction status.
                 * @return The status of satisfaction as a string.
                 */
                std::string getStatus();

                /**
                 * @brief Raises the satisfaction level.
                 * @return A pointer to the new Satisfaction object after raising the status.
                 */
                virtual Satisfaction* raiseStatus() = 0;

                /**
                 * @brief Lowers the satisfaction level.
                 * @return A pointer to the new Satisfaction object after lowering the status.
                 */
                virtual Satisfaction* lowerStatus() = 0;

                /**
                 * @brief Virtual destructor for Satisfaction.
                 */
                virtual ~Satisfaction() {};
};

/**
 * @class Satisfied
 * @brief Represents a satisfied level of citizen satisfaction.
 */
class Satisfied : public Satisfaction
{
        public:
                /**
                 * @brief Constructs a Satisfied object and sets the status.
                 */
                Satisfied();

                /**
                 * @brief Attempts to raise the satisfaction level.
                 * @return A pointer to the current Satisfied object (since it's already at the highest level).
                 */
                Satisfaction* raiseStatus();

                /**
                 * @brief Lowers the satisfaction level to Neutral.
                 * @return A pointer to a new Neutral object.
                 */
                Satisfaction* lowerStatus();
};

/**
 * @class Neutral
 * @brief Represents a neutral level of citizen satisfaction.
 */
class Neutral : public Satisfaction
{
        public:
                /**
                 * @brief Constructs a Neutral object and sets the status.
                 */
                Neutral();

                /**
                 * @brief Raises the satisfaction level to Satisfied.
                 * @return A pointer to a new Satisfied object.
                 */
                Satisfaction* raiseStatus();

                /**
                 * @brief Lowers the satisfaction level to Unsatisfied.
                 * @return A pointer to a new Unsatisfied object.
                 */
                Satisfaction* lowerStatus();
};

/**
 * @class Unsatisfied
 * @brief Represents an unsatisfied level of citizen satisfaction.
 */
class Unsatisfied : public Satisfaction
{
        public:
                /**
                 * @brief Constructs an Unsatisfied object and sets the status.
                 */
                Unsatisfied();

                /**
                 * @brief Raises the satisfaction level to Neutral.
                 * @return A pointer to a new Neutral object.
                 */
                Satisfaction* raiseStatus();

                /**
                 * @brief Attempts to lower the satisfaction level.
                 * @return A pointer to the current Unsatisfied object (since it's already at the lowest level).
                 */
                Satisfaction* lowerStatus();
};

#endif
