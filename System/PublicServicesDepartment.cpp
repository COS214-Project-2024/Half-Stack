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

	incomeTax =45;
	salesTax=15;
	propertyTax=18;
}

/**
 * @brief Collects the specified type of tax by executing the relevant tax command.
 * 
 * @param tax The type of tax to be collected (income, property, or sales).
 */
void PublicServicesDepartment::collectTax(std::string tax) 
{
	if (tax=="Income")
	{
		this->commands[0]->execute();
	}
	if (tax=="Sales")
	{
		this->commands[2]->execute();
	}
	if (tax=="Property")
	{
		this->commands[1]->execute();
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
		delete Singleton;
        Singleton = nullptr;
    }

	for (std::vector<Building*>::iterator i = jobBuildings.begin(); i != jobBuildings.end(); i++)
            {
                if ((*i)!=NULL)
                {
                    delete *i;
                }
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
    Government* government = Government::instance(" ");  
    std::vector<Citizen*> allCitizens = government->getCitizens();

    for (size_t i = 0; i < allCitizens.size(); ++i) 
    {
	    Citizen* citizen = allCitizens[i];	
        Satisfaction* newStatus = citizen->getSatisfaction()->lowerStatus();
        citizen->setSatisfaction(newStatus);
    }
	incomeTax +=1;
	propertyTax +=1;
	salesTax += 1;
    std::cout << "Tax increased and satisfaction decreased for all citizens." << std::endl;
}

/**
 * @brief Decreases the tax amount and Increases the satisfaction of all citizens.
 */
void PublicServicesDepartment::decreaseTax() 
{
    Government* government = Government::instance(" ");  
    std::vector<Citizen*> allCitizens = government->getCitizens();

    for (size_t i = 0; i < allCitizens.size(); ++i) 
    {
	    Citizen* citizen = allCitizens[i];	
        Satisfaction* newStatus = citizen->getSatisfaction()->raiseStatus();
        citizen->setSatisfaction(newStatus);
    }
	incomeTax -=1;
	propertyTax -=1;
	salesTax -= 1;
    std::cout << "Tax decreased and satisfaction increased for all citizens." << std::endl;
}


 /**
 * @brief gets the incomeTax variable value
 * 
 * @return value of IncomeTax variable
 */
double PublicServicesDepartment::getIncomeTax()
{
	return incomeTax;
}
 /**
 * @brief gets the propertyTax variable value
 * 
 * @return value of PropertyTax variable
 */
double PublicServicesDepartment::getPropertyTax()
{
	return propertyTax;
}
/**
 * @brief gets the salesTax variable value
 * 
 * @return value of salesTax variable
 */
double PublicServicesDepartment::getSalesTax()
{
	return salesTax;
}

 /**
 * @brief adds a building to the vector attribute
 * 
 * @param b the building to be added.
 */
void PublicServicesDepartment::addBuilding(Building* b)
{
	int num = b->getCapacity();
    ResourceManager* rm = ResourceManager::instance();
    if (rm->decreaseResourceLevels(10, 10, 20*num, 20*num, 5*num) == true)
	{
		if (rm->decreaseBudget(50*num)==true)
        {
            jobBuildings.push_back(b);
            employCitizens();
            std::cout << "Job building successfully built." <<std::endl;
        }else {
            rm->increaseResourceLevels(10, 10, 20*num, 20*num, 5*num);
            delete b;
        }
	}else{
        delete b;
    }
}

/**
 * @brief goes through the government's citizens vector and the buildings vector to find citizens without jobs
 * and assign them a job if they are over 18 and the building is not at max capaity
 */
void PublicServicesDepartment::employCitizens()
{
	std::vector<Citizen*> citizens = Government::instance(" ")->getCitizens();
    std::vector<Citizen*>::iterator it ;
    for (std::vector<Building*>::iterator i = jobBuildings.begin(); i != jobBuildings.end(); i++)
    {
        if ((*i)->isFull()==false)
        {
            for(it = citizens.begin(); it != citizens.end(); ++it)
            {
                if((*it)->getEmployment()->getStatus()=="Unemployed" && (*i)->isFull()==false)
                {
                    (*it)->setJob(*i);
                    (*i)->addCitizen(*it);
                }
            }
        }
    }
}

/**
 * @brief goes through the buildings vector and calls the consumeResources function on each
 */
void PublicServicesDepartment::consumeDailyResources()
{
    bool consumed = true;
    for (std::vector<Building*>::iterator i = jobBuildings.begin(); i != jobBuildings.end(); i++)
    {
        if ((*i)->consumeResources()==false)
        {
            consumed=false;
        }
    }
    if (consumed==false)
    {
        std::cout << "Some job buildings have no water and power. Please replenish power and water." <<std::endl;
    }
}

/**
 * @brief loops through the buildings vector to determine the amount of buildings
 * 
 * @return total amount of buildings
 */
int PublicServicesDepartment::getTotalBuildings()
{
    int counter = 0;
	for (std::vector<Building*>::iterator i = jobBuildings.begin(); i != jobBuildings.end(); i++)
    {
        counter++;
    }
    return counter;
}

/**
 * @brief loops through the buildings vector to determine the capacity of buildings
 * 
 * @return total capacity of buildings
 */
int PublicServicesDepartment::getTotalCapacity()
{
    int total = 0;
	for (std::vector<Building*>::iterator i = jobBuildings.begin(); i != jobBuildings.end(); i++)
    {
        total = total + (*i)->capacity;
    }
    return total;
}