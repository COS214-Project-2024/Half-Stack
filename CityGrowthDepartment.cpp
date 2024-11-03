#include "CityGrowthDepartment.h"
#include "BuildingTypes.h"
#include "Government.h"
#include "Plant.h"
#include <cmath>

CityGrowthDepartment* CityGrowthDepartment::uniqueInstance;

void CityGrowthDepartment::increaseHousing(char b) 
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
						resDepartment->addBuilding(new Apartment(5,"apartment")); //should trigger government to place in homes 
					}
				}else{
					resDepartment->addBuilding(new Apartment(homeless,"apartment"));
				}
				break;
			case 'H':
				if (homeless>4)
				{
					int numBuildings = ceil(homeless/4.0);
					for (int i=0;i<numBuildings;i++)
					{
						resDepartment->addBuilding(new House(4,"House")); //should trigger government to place in homes 
					}
				}else{
					resDepartment->addBuilding(new House(homeless,"House"));
				}
				break;
			case 'T':
				if (homeless>10)
				{
					int numBuildings = ceil(homeless/10.0);
					for (int i=0;i<numBuildings;i++)
					{
						resDepartment->addBuilding(new TownHouse(10,"TownHouse"));
					}
				}else{
					resDepartment->addBuilding(new TownHouse(homeless,"TownHouse"));
				}
				break;
			case 'E': 
				resDepartment->addBuilding(new Estate(homeless,"Estate"));
				break;
		}
	

	}
}

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

void CityGrowthDepartment::increasePopulation()
{
	int homeless= gov->getHomeless();
	if (homeless> ceil(0.05*population))
	{
		//std::cout << "Too many homeless citizens. Cannot increase population. " << std::endl;
		//return;
		increaseHousing('H');
	}
	//int growth = ceil(0.1*population);
	for (int i=0; i<10 ;i++)
	{
		homeless= gov->getHomeless();
		if (homeless> ceil(0.05*population))
		{
			increaseHousing('H');
		}
		//Citizen* addCitizen = new Citizen(i+18);
		gov->addCitizen(new Citizen(i+18));
		//population++;
	}
	std::cout << "Population increased by 10." <<std::endl;
	//resDepartment->houseNewCitizens();
}

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
			enough==false;
		}
		roads = TransportDep->getTotalRoads();
	}
	

	int t = ceil(population/50.0); //should be a road for every building
	if (trains<t && t!=0)
	{
		TransportDep->addTransport(new Railway());
	}
}

void CityGrowthDepartment::increaseUtilities() 
{
	//if (resourceManager->getBudget()>500000)
	{
		//utilityDep->addBuilding(new PowerPlant(10,"powerplant"));
	}
	//if (resourceManager->getBudget()>500000)
	{
		//utilityDep->addBuilding(new WaterPlant(10,"waterplant"));
	}
	//if (resourceManager->getBudget()>500000)
	{
		//utilityDep->addBuilding(new MaterialsPlant(10,"materialsplant"));
	}
}

int CityGrowthDepartment::getPopulation()
{
	return population;
}



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

CityGrowthDepartment* CityGrowthDepartment::instance(Government* gov)
{
	if (uniqueInstance==NULL)
	{
		uniqueInstance = new CityGrowthDepartment(gov);
	}

	return uniqueInstance;
}

CityGrowthDepartment::~CityGrowthDepartment()
{
	delete uniqueInstance;
}

void CityGrowthDepartment::updatePopulation()
{
	population++;
}