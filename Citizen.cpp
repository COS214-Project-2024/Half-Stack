#include "Citizen.h"

int Citizen::counter=0;
/**
 * @brief Constructs a Citizen object with a given name and age.
 * 
 * The citizen is initialized as unemployed and with a neutral satisfaction level.
 * @param name The name of the citizen.
 * @param age The age of the citizen.
 */
Citizen::Citizen(int age)
{
    counter++;
    this->ID = counter;
    this->age = age;

    this->employment = new Unemployed();
    this->satisfaction = new Neutral();
}

/**
 * @brief Destructor for the Citizen class.
 * 
 * Cleans up dynamically allocated resources for employment and satisfaction.
 */
Citizen::~Citizen()
{
    delete employment;
    delete satisfaction;
}

/**
 * @brief Processes tax payment for the citizen based on the specified tax type.
 * 

 * Outputs a message indicating which type of tax was paid by the citizen.
 * If an unrecognized tax type is provided, it outputs "invalid input."
 * 
 * @param tax A string representing the type of tax. Expected values are:
 *            - "incomeTax" for income tax
 *            - "SalesTax" for sales tax
 *            - "PropertyTax" for property tax
 * 
 * - Outputs a message in the format:

 *   - "<name> paid income tax." if tax is "incomeTax"
 *   - "<name> paid sales tax." if tax is "SalesTax"
 *   - "<name> paid property tax." if tax is "PropertyTax"
 *   - "invalid input." for any other value
 */
void Citizen::payTax(std::string tax)
{

    if (tax == "incomeTax")
    {
        std::cout << this->name << " paid income tax." << std::endl;
    }
    else if (tax == "SalesTax")
    {
        std::cout << this->name << " paid sales tax." << std::endl;
    }
    else if (tax == "PropertyTax")
    {
        std::cout << this->name << " paid property tax." << std::endl;
    }
    else
    {
        std::cout << "invalid input." << std::endl;
    }
}

/**
 * @brief Initiates work for the citizen if they are employed.
 * 
 * Outputs a message indicating whether the citizen is starting work or does not have a job.
 */
void Citizen::startWork()
{
    if (this->employment->getStatus() == "Employed")
    {
        std::cout << this->name << " is starting work." << std::endl;
    }
    else
    {
        std::cout << this->name << " does not have a job." << std::endl;
    }
}

/**
 * @brief Gets the employment status of the citizen.
 * @return Employment* Pointer to the current employment status.
 */
Employment* Citizen::getEmployment()
{
    return this->employment;
}


/**
 * @brief Sets the employment status of the citizen.
 * @param e Pointer to the new employment status.
 */
void Citizen::setEmployment(Employment* e)
{
    this->employment = e;
}

/**
 * @brief Gets the satisfaction status of the citizen.
 * @return Satisfaction* Pointer to the current satisfaction status.
 */
Satisfaction* Citizen::getSatisfaction()
{
    return this->satisfaction;
}

/**
 * @brief Sets the satisfaction status of the citizen.
 * @param s Pointer to the new satisfaction status.
 */
void Citizen::setSatisfaction(Satisfaction* s)
{
    this->satisfaction = s;
}

/**
 * @brief Attempts to get a job for the citizen.
 * 
 * If the citizen is unemployed, they become employed and a message is output.
 * If the citizen is already employed, an error message is output.
 */
void Citizen::getJob()
{
    if (this->employment->getStatus() == "Unemployed")
    {
        std::cout << this->name << " obtained a job." << std::endl;
        this->employment = employment->toggleStatus();
    }
    else
    {
        std::cout << this->name << " already has a job. " << this->name
                  << " cannot obtain a job if they already have one." << std::endl;
    }
}

/**
 * @brief Receives and displays a notification for the citizen.
 * @param message The notification message to display.
 */
void Citizen::receiveNotification(const std::string& message)
{
    std::cout << "Notification for " << name << ": " << message << std::endl;
}

/**
 * @brief Gets the age of the citizen.
 * @return int The age of the citizen.
 */
int Citizen::getAge()
{
    return age;
}