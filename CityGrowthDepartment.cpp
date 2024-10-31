#include "CityGrowthDepartment.h"
#include "BuildingTypes.h"
#include "Government.h"
#include "Plant.h"
#include <cmath>

CityGrowthDepartment* CityGrowthDepartment::uniqueInstance;

void CityGrowthDepartment::increaseHousing(char b) 
{
	//char BuildingType;
	int currHousingCapacity = resDepartment->getTotalCapacity();
	if (population > currHousingCapacity)
	{
		int homeless= population-currHousingCapacity;
		switch (b) {
			case 'F':
				if (homeless>5)
				{
					int numBuildings = ceil(homeless/5);
					for (int i=0;i<numBuildings;i++)
					{
						resDepartment->addBuilding(new Flat(5,"flat")); //should trigger government to place in homes 
					}
				}else{
					resDepartment->addBuilding(new Flat(homeless,"flat"));
					//r//esDepartment->houseHomelessCitizens();
				}
				break;
			case 'H':
				if (homeless>4)
				{
					int numBuildings = ceil(homeless/4.0);
					for (int i=0;i<numBuildings;i++)
					{
						resDepartment->addBuilding(new House(4,"House")); //should trigger government to place in homes 
						//resDepartment->houseHomelessCitizens();
					}
				}else{
					resDepartment->addBuilding(new House(homeless,"House"));
					//resDepartment->houseHomelessCitizens();
				}
				break;
			case 'T':
				if (homeless>10)
				{
					int numBuildings = ceil(homeless/10);
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
	std::vector<Citizen*>::iterator it = citizens.begin();
    for(; it != citizens.end(); ++it)
    {
        gov->addCitizen(*it);
		population++;
    }
	//increaseHousing('E');
	//increaseTransport();
	//increaseUtilities();
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
		

	if (unemployed>0)
	{
		//int openPosts = unemployed;
		//char input;
		//std::cout <<"There are " << openPosts << " jobs empty. Would you like to migrate more people?";
		//std::cin >> input;
		//if (input=='y')
		{
			//increasePopulation(openPosts);
		}
	}
}

void CityGrowthDepartment::increaseTransport() 
{
	//int trains = TransportDep->getTotalTrains();
	int airports = TransportDep->getTotalAirports();
	//int roads = TransportDep->getTotalRoads();
	//int publicTransit =TransportDep->getTotalPublicTransit();
	//int trafficJam = trains+roads+publicTransit;

	if (airports<7)
	{
		TransportDep->addTransport(new Airport());
	}
	//if (resourceManager->canBuildTrain()==true)
	{
		TransportDep->addTransport(new Railway());
	}
	//if (resourceManager->canBuildRoad()==true)
	{
		TransportDep->addTransport(new Road());
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
