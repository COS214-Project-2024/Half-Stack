#include "PublicServicesDepartment.h"

PublicServicesDepartment* PublicServicesDepartment::Singleton = nullptr;

/**
 * @brief Constructs a PublicServicesDepartment and initializes the tax command objects.
 */
PublicServicesDepartment::PublicServicesDepartment() 
{
	this->commands[0] = new CollectIncomeTax();
	this->commands[1] = new CollectPropertyTax();
	this->commands[2] = new CollectSalesTax();
}

/**
 * @brief Collects the specified type of tax by executing the relevant tax command.
 * 
 * @param tax The type of tax to be collected (income, property, or sales).
 */
void PublicServicesDepartment::collectTax(std::string tax) 
{
	for (int i = 0; i < 3; i++)
	{
		this->commands[0]->execute();
	}
}

/**
 * @brief Returns the singleton instance of the PublicServicesDepartment.
 * 
 * @return PublicServicesDepartment* Pointer to the singleton instance.
 */
PublicServicesDepartment* PublicServicesDepartment::instance() 
{
    if (Singleton == nullptr) 
	{
        Singleton = new PublicServicesDepartment();
    }

    return Singleton;
}

/**
 * @brief Destructor for the PublicServicesDepartment, cleaning up dynamically allocated resources.
 */
PublicServicesDepartment::~PublicServicesDepartment()
{
	for (int i = 0; i < 3; ++i) 
	{
        delete commands[i];
        commands[i] = nullptr;
    }

    // Nullify the Singleton pointer if this is the instance being destroyed
    if (Singleton == this) 
	{
        Singleton = nullptr;
    }
}