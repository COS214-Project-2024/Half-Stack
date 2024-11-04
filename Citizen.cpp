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
    home = NULL;
    tax=NULL;
    noResources=false;
}

/**
 * @brief Destructor for the Citizen class.
 * 
 * Cleans up dynamically allocated resources for employment, satisfaction and tax.
 */
Citizen::~Citizen()
{
    delete employment;
    delete satisfaction;
    delete tax;
}

/**
 * @brief Processes tax payment for the citizen based on the specified tax type, provided they are of legal age and employed.
 * 
 * This function determines if the citizen is eligible to pay tax based on age and employment status. 
 * If eligible, it dynamically allocates and invokes the appropriate tax payment action. Outputs a 
 * message indicating the type of tax paid, or "invalid input" if the tax type is unrecognized.
 * 
 * @param tax A string representing the type of tax. Expected values are:
 *            - "IncomeTax" for income tax
 *            - "SalesTax" for sales tax
 *            - "PropertyTax" for property tax
 * 
 * If `tax` matches one of the specified values:
 *   - Allocates and assigns the appropriate tax payment class.
 *   - Calls the pay() method of the assigned tax class, outputting a message in the format:
 *     - "<name> paid income tax." if tax is "IncomeTax"
 *     - "<name> paid sales tax." if tax is "SalesTax"
 *     - "<name> paid property tax." if tax is "PropertyTax"
 * 
 * If an unrecognized tax type is provided, no action is taken and "invalid input" is output.
 * 
 * Note:
 *   - The function returns immediately without processing if the citizen is under 18 years old
 *     or has an employment status of "Unemployed".
 *   - If a previous tax payment action is allocated, it is deleted to prevent memory leaks.
 */
void Citizen::payTax(std::string tax)
{
    if (age<18)
    {
        return;
    }
    if (employment->getStatus()=="Unemployed")
    {
        return;
    }
    if (this->tax!=NULL)
    {
        delete this->tax;
    }
    if (tax=="IncomeTax")
        this->tax = new payIncomeTax();
    if (tax=="SalesTax")
        this->tax = new paySalesTax();
    if (tax=="PropertyTax")
        this->tax = new payPropertyTax();

    if (this->tax!=NULL)
    {
        this->tax->pay();
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
        std::cout << this->ID << " is starting work." << std::endl;
    }
    else
    {
        std::cout << this->ID << " does not have a job." << std::endl;
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
    if (employment!=NULL)
    {
        delete employment;
    }
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
    if (satisfaction!=NULL)
    {
        delete satisfaction;
    }
    this->satisfaction = s;
}

/**
 * @brief Attempts to get a job for the citizen.
 * 
 * If the citizen is unemployed, they become employed and a message is output.
 * If the citizen is already employed, an error message is output.
 */
void Citizen::setJob(Building* b)
{
    if (this->employment->getStatus() == "Unemployed")
    {
        //std::cout << this->ID << " obtained a job." << std::endl;

        setEmployment(employment->toggleStatus());
        jobBuilding = b;
    }
    else
    {
        std::cout << this->ID << " already has a job. " << this->ID
                  << " cannot obtain a job if they already have one." << std::endl;
    }
}

/**
 * @brief Receives and displays a notification for the citizen.
 * @param message The notification message to display.
 */
void Citizen::receiveNotification(const std::string& message)
{
    if (message=="No power and water")
    {
        setSatisfaction(satisfaction->lowerStatus());
        noResources=true;
        return;
    }

    if (message=="Load-shedding has ended.")
    {
        setSatisfaction(satisfaction->raiseStatus());
        return;
    }

    setSatisfaction(satisfaction->lowerStatus());
    //std::cout << "Notification for " << this->ID << ": " << message << std::endl;
}

/**
 * @brief Gets the age of the citizen.
 * @return int The age of the citizen.
 */
int Citizen::getAge()
{
    return age;
}

Building* Citizen::getHome()
{
    return home;
}

void Citizen::moveIn(Residential* housing)
{
    home = housing;
}

bool Citizen::getNoResources()
{
    return noResources;
}

void Citizen::setNoResources(bool s)
{
    noResources=s;
}
