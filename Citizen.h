#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <string>
#include "Building.h"
#include "Employment.h"
#include "Satisfaction.h"
#include "payTaxStrategy.h"
#include "Residential.h"

class Building;
class payTaxStrategy;
class Residential;

/**
 * @class Citizen
 * @brief Represents a citizen with attributes such as name, age, employment status, and satisfaction level.
 * 
 * The Citizen class manages various aspects of a citizen, including their job status, tax payments,
 * and notification handling. Each citizen is associated with a home and possibly a job building.
 */
class Citizen
{
private:
    int ID;
    //std::string name; ///< The name of the citizen.
    int age; ///< The age of the citizen.
    Employment* employment; ///< Pointer to the employment status of the citizen.
    Satisfaction* satisfaction; ///< Pointer to the satisfaction status of the citizen.
    Building* jobBuilding; ///< Pointer to the building where the citizen works.
    Building* home; ///< Pointer to the building where the citizen lives.
    static int counter;
    bool noResources;

    payTaxStrategy* tax;

public:
    /**
     * @brief Constructs a Citizen object with a given name and age.
     * 
     * The citizen is initially unemployed and has a neutral satisfaction level.
     * @param name The name of the citizen.
     * @param age The age of the citizen.
     */
    Citizen(int age);

    /**
     * @brief Destructor for the Citizen class.
     * 
     * Cleans up dynamically allocated resources for employment, satisfaction and tax.
     */
    ~Citizen();

    /**
     * @brief Processes tax payment for the citizen based on the specified tax type, provided they are of legal age and employed.
     * 
     * This function checks if the citizen meets the age and employment requirements to pay tax. 
     * If eligible, it dynamically allocates and invokes the appropriate tax payment action. Outputs a 
     * message indicating the type of tax paid, or "invalid input" if the tax type is unrecognized.
     * 
     * @param tax A string representing the type of tax. Expected values are:
     *            - "IncomeTax" for income tax
     *            - "SalesTax" for sales tax
     *            - "PropertyTax" for property tax
     * 
     * The function performs the following:
     *   - If the citizen is under 18 years old or unemployed, the function returns without processing.
     *   - If the `tax` parameter matches a recognized tax type, it allocates and assigns the appropriate 
     *     tax payment action class, deletes any previously allocated tax class, and then calls the `pay()` method.
     *   - Outputs a message in the format "<name> paid <tax type> tax." (e.g., "John Doe paid income tax.").
     * 
     * @note If an unrecognized tax type is provided, "invalid input" is output, and no action is taken.
     */
    void payTax(std::string tax);

    /**
     * @brief Initiates work for the citizen if they are employed.
     * 
     * Outputs a message indicating whether the citizen is starting work or does not have a job.
     */
    void startWork();

    /**
     * @brief Gets the employment status of the citizen.
     * @return Employment* Pointer to the current employment status.
     */
    Employment* getEmployment();

    /**
     * @brief Sets the employment status of the citizen.
     * @param e Pointer to the new employment status.
     */
    void setEmployment(Employment* e);

    /**
     * @brief Gets the satisfaction status of the citizen.
     * @return Satisfaction* Pointer to the current satisfaction status.
     */
    Satisfaction* getSatisfaction();

    /**
     * @brief Sets the satisfaction status of the citizen.
     * @param s Pointer to the new satisfaction status.
     */
    void setSatisfaction(Satisfaction* s);

    /**
     * @brief Attempts to get a job for the citizen.
     * 
     * If the citizen is unemployed, they become employed and a message is output.
     * If the citizen is already employed, an error message is output.
     */
    void setJob(Building* b);

    /**
     * @brief Receives and displays a notification for the citizen.
     * @param message The notification message to display.
     */
    void receiveNotification(const std::string& message);

    /**
     * @brief Gets the age of the citizen.
     * @return int The age of the citizen.
     */
    int getAge();

    Building* getHome();

    void moveIn(Residential* housing);

    bool getNoResources();

    void setNoResources(bool s);
};

#endif
