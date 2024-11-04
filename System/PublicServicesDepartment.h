#ifndef PUBLICSERVICESDEPARTMENT_H
#define PUBLICSERVICESDEPARTMENT_H

#include "Department.h"
#include "Building.h"
#include "TaxCommand.h"
#include "Citizen.h"

/**
 * @class PublicServicesDepartment
 * @brief The PublicServicesDepartment class represents a department responsible for 
 * collecting various taxes and implementing the singleton design pattern.
 */
class PublicServicesDepartment : public Department
{
private:
	///< Pointer to the singleton instance of PublicServicesDepartment.
	static PublicServicesDepartment* Singleton;

	///< Array of pointers to TaxCommand objects for different tax types.
	TaxCommand* commands[3];

     double incomeTax;
     double propertyTax;
     double salesTax;

     std::vector<Building*> jobBuildings;
     
public:
	/**
     * @brief Constructs a PublicServicesDepartment and initializes the tax command objects.
     */
	PublicServicesDepartment();

	/**
     * @brief Collects the specified type of tax by executing the relevant tax command.
     * 
     * @param tax The type of tax to be collected (income, property, or sales).
     */
	void collectTax(std::string tax);

	/**
     * @brief Returns the singleton instance of the PublicServicesDepartment.
     * 
     * @return PublicServicesDepartment* Pointer to the singleton instance.
     */
	static PublicServicesDepartment* instance();

	/**
     * @brief Destructor for the PublicServicesDepartment, cleaning up dynamically allocated resources.
     */
	~PublicServicesDepartment();

	/**
     * @brief Increases the tax amount and decreases the satisfaction of all citizens.
     */
    void increaseTax();

    /**
     * @brief Decreases the tax amount and Increases the satisfaction of all citizens.
     */
    void decreaseTax();

     /**
     * @brief gets the incomeTax variable value
     * 
     * @return value of IncomeTax variable
     */
    double getIncomeTax();
    /**
     * @brief gets the propertyTax variable value
     * 
     * @return value of PropertyTax variable
     */
    double getPropertyTax();
    /**
     * @brief gets the salesTax variable value
     * 
     * @return value of salesTax variable
     */
    double getSalesTax();


     /**
     * @brief adds a building to the vector attribute
     * 
     * @param b the building to be added.
     */
    void addBuilding(Building* b);

     /**
     * @brief goes through the government's citizens vector and the buildings vector to find citizens without jobs
     * and assign them a job if they are over 18 and the building is not at max capaity
     */
    void employCitizens();

     /**
     * @brief goes through the buildings vector and calls the consumeResources function on each
     */
    void consumeDailyResources();

     /**
     * @brief loops through the buildings vector to determine the amount of buildings
     * 
     * @return total amount of buildings
     */
    int getTotalBuildings();

     /**
     * @brief loops through the buildings vector to determine the capacity of buildings
     * 
     * @return total capacity of buildings
     */
    int getTotalCapacity();
};

#endif
