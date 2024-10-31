#include "PublicServicesDepartment.h"
#include "Government.h"

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

/**
 * @brief Increases the tax amount and reduces satisfaction for all citizens.
 *
 * This method increases the tax rate and subsequently decreases each citizen's
 * satisfaction level by one step, simulating the effect of higher taxes on citizen satisfaction.
 */
void PublicServicesDepartment::increaseTax() 
{
    Government* government = Government::instance("HalfStack City Builder");  
    std::vector<Citizen*> allCitizens = government->getCitizens();

    for (size_t i = 0; i < allCitizens.size(); ++i) 
    {
	Citizen* citizen = allCitizens[i];	
        Satisfaction* newStatus = citizen->getSatisfaction()->lowerStatus();
        citizen->setSatisfaction(newStatus);
    }

    std::cout << "Tax increased and satisfaction decreased for all citizens." << std::endl;
}
