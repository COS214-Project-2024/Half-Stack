#include "PublicServicesDepartment.h"

PublicServicesDepartment* PublicServicesDepartment::Singleton = nullptr;

PublicServicesDepartment::PublicServicesDepartment() 
{
	this->commands[0] = new CollectIncomeTax();
	this->commands[1] = new CollectPropertyTax();
	this->commands[2] = new CollectSalesTax();
}

void PublicServicesDepartment::collectTax(std::string tax) 
{
	for (int i = 0; i < 3; i++)
	{
		this->commands[0]->execute();
	}
}

PublicServicesDepartment* PublicServicesDepartment::instance() 
{
    if (Singleton == nullptr) 
	{
        Singleton = new PublicServicesDepartment();
    }

    return Singleton;
}

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