#include "CityGrowthDepartment.h"
#include "BuildingTypes.h"
#include "Government.h"
#include "Plant.h"
#include <cmath>

CityGrowthDepartment* CityGrowthDepartment::uniqueInstance;

/**
 * @brief Increases housing capacity based on the specified building type.
 * @param b Character representing the building type ('A' for Apartment, 'H' for House, 'T' for TownHouse, 'E' for Estate).
 * @return if housing was actually added to the residential department
 */
bool CityGrowthDepartment::increaseHousing(char b) 
{
	int homeless= gov->getHomeless();
	if (homeless > 0)
	{
		switch (b) {
			case 'A':
				if (homeless>5)
				{
					int numBuildings = ceil(homeless/5.0);
					for (int i=0;i<numBuildings;i++)
					{
						if (resDepartment->addBuilding(new Apartment(5,"apartment"))==false)
						{
							return false;
						} 
					}
				}else{
					if (resDepartment->addBuilding(new Apartment(homeless,"apartment"))==false)
						return false;
				}
				break;
			case 'H':
				if (homeless>4)
				{
					int numBuildings = ceil(homeless/4.0);
					Estate* estate = new Estate(numBuildings*4,"estate");
					for (int i=0;i<numBuildings;i++)
					{
						estate->addBuilding(new House(4,"House"));
						/*if (resDepartment->addBuilding(new House(4,"House"))==false)
							return false; */
					}
					if (resDepartment->addBuilding(estate)==false)
							return false;
				}else{
					if (resDepartment->addBuilding(new House(homeless,"House"))==false)
						return false;
				}
				break;
			case 'T':
				if (homeless>10)
				{
					int numBuildings = ceil(homeless/10.0);
					for (int i=0;i<numBuildings;i++)
					{
						if (resDepartment->addBuilding(new TownHouse(10,"TownHouse"))==false)
							return false;
					}
				}else{
					if (resDepartment->addBuilding(new TownHouse(homeless,"TownHouse"))==false)
						return false;
				}
				break;
		}
	
		return true;
	}
	return true;
}

/**
 * @brief Increases the population by adding a vector of new citizens.
 * @param citizens Vector of Citizen pointers to be added to the population.
 */
void CityGrowthDepartment::increasePopulation(std::vector<Citizen*> citizens) 
{
	int homeless= gov->getHomeless();
	if (homeless > ceil(0.05*population))
	{
		std::cout << "Too many homeless citizens. Cannot increase population. " << std::endl;
		return;
	}
	int count=0;
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
		gov->addCitizen(*it);
		//population++;
		count++;
		//resDepartment->houseNewCitizens();
    }
	std::cout << "Population increased by " << count <<std::endl;
	//resDepartment->houseNewCitizens();
}

/**
 * @brief Increases the population by a fixed amount (10 citizens).
 */
void CityGrowthDepartment::increasePopulation()
{
	int valid = ceil(population/20.0);
	if (utilityDep->getTotalWaterPlants()<valid)
	{
		std::cout << "Cannot increase population. Build more water plants to accomodate a higher population." <<std::endl;
		return;
	}
	if (utilityDep->getTotalPowerPlants()<valid)
	{
		std::cout << "Cannot increase population. Build more power plants to accomodate a higher population." <<std::endl;
		return;
	}
	int homeless= gov->getHomeless();
	if (homeless> ceil(0.05*population))
	{
		if (increaseHousing('H')==false)
		{
			std::cout << "Buy more resources to increase population!" <<std::endl;
			return;
		}
	}
	
	int counter=0;
	for (int i=0; i<10 ;i++)
	{
		homeless= gov->getHomeless();
		if (homeless>4)
			if (increaseHousing('H')==false)
			{
				std::cout << "Population increased by " << counter <<std::endl;
				std::cout << "Buy more resources to increase population!" <<std::endl;
				return;
			}

		gov->addCitizen(new Citizen(i+18));
		counter++;
		//population++;
	}
	std::cout << "Population increased by "<<counter  <<std::endl;
	//resDepartment->houseNewCitizens();
}

/**
 * @brief Increases the number of available jobs by constructing new buildings.
 */
void CityGrowthDepartment::increaseJobs() 
{
	int unemployed = gov->getTotalUnemployed();
	while (unemployed > 100)
	{
		psDep->addBuilding(new Office(40,"office"));
		psDep->addBuilding(new Shop(10,"shop"));
		psDep->addBuilding(new Warehouse(10,"warehouse"));
		psDep->addBuilding(new Mall(30,"mall"));
		psDep->addBuilding(new Factory(20,"factory"));
		unemployed -=110;
	}
	if (unemployed > 50)
	{
		psDep->addBuilding(new Office(20,"office"));
		psDep->addBuilding(new Shop(5,"shop"));
		psDep->addBuilding(new Warehouse(5,"warehouse"));
		psDep->addBuilding(new Mall(20,"mall"));
		psDep->addBuilding(new Factory(10,"factory"));
		unemployed -=60;
	}
	if (unemployed > 20)
	{
		psDep->addBuilding(new Shop(10,"shop"));
		psDep->addBuilding(new Factory(10,"factory"));
		psDep->addBuilding(new Warehouse(10,"warehouse"));
		unemployed -=30;
	}
	if (unemployed > 0)
	{
		psDep->addBuilding(new Shop(10,"shop"));
		psDep->addBuilding(new Office(10,"office"));
		unemployed -=20;
	}
}

/**
 * @brief Expands the transport infrastructure by adding new transport facilities.
 */
void CityGrowthDepartment::increaseTransport() 
{
	int trains = TransportDep->getTotalRailways();
	int airports = TransportDep->getTotalAirports();
	int roads = TransportDep->getTotalRoads();

	int a = ceil(population/500.0);
	if (airports<7 && airports<a && a!=0)
	{
		TransportDep->addTransport(new Airport());
	}

	int totalBuildings = resDepartment->getTotalBuildings()+psDep->getTotalBuildings();
	int r = ceil(totalBuildings/3.0) ;//should be a road for every building
	bool enough=true;
	while (roads<r &&r!=0 &&enough==true)
	{
		TransportDep->addTransport(new Road());
		if (roads==TransportDep->getTotalRoads())
		{
			enough=false;
		}
		roads = TransportDep->getTotalRoads();
	}
	
	TransportDep->addTransport(new Trail());

	int t = ceil(population/50.0); //should be a road for every building
	if (trains<t && t!=0)
	{
		TransportDep->addTransport(new Railway());
	}
}

/**
 * @brief Retrieves the current population of the city.
 * @return The current population as an integer.
 */
int CityGrowthDepartment::getPopulation()
{
	return population;
}


/**
 * @brief Constructor for CityGrowthDepartment.
 * @param gov Pointer to the Government instance.
 */
CityGrowthDepartment::CityGrowthDepartment(Government* gov) 
{
	this->resDepartment = gov->getResidentialDepartment();
	this->TransportDep = gov->getTransportDepartment();
	this->utilityDep = gov->getUtilitiesDepartment();
	this->psDep = gov->getPublicServicesDepartment();
	this->resourceManager = gov->getResourceManager();
	this->gov = gov;
	population = gov->getTotalCitizens();
}

/**
 * @brief Singleton method to get or create the unique instance of CityGrowthDepartment.
 * @param gov Pointer to the Government instance.
 * @return Pointer to the unique CityGrowthDepartment instance.
 */
CityGrowthDepartment* CityGrowthDepartment::instance(Government* gov)
{
	if (uniqueInstance==NULL)
	{
		uniqueInstance = new CityGrowthDepartment(gov);
	}

	return uniqueInstance;
}

/**
 * @brief destructor for CityGrowthDepartment
 */
CityGrowthDepartment::~CityGrowthDepartment()
{
	delete uniqueInstance;
}

/**
 * @brief increases population by 1
 */
void CityGrowthDepartment::updatePopulation()
{
	population++;
}
