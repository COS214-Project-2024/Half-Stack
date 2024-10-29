#include "CityGrowthDepartment.h"

CityGrowthDepartment* CityGrowthDepartment::uniqueInstance;

void CityGrowthDepartment::increaseHousing(char BuildingType) 
{
	char BuildingType;
	int currHousingCapacity = resDepartment->getTotalCapacity();
	if (population > currHousingCapacity)
	{
		int homeless= population-currHousingCapacity;
		//std::cout << homeless << "citizens currently without homes." << std::endl;
		//std::cout << "Select a residential building to house these citizens (F/H/T/E): ";
		//std::cin >> BuildingType;
		//should all buildings be the same?
		switch (BuildingType) {
			case 'F': {
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
			}
			case 'H':{
				if (homeless>4)
				{
					int numBuildings = ceil(homeless/4);
					for (int i=0;i<numBuildings;i++)
					{
						resDepartment->addBuilding(new House(4,"House")); //should trigger government to place in homes 
						//resDepartment->houseHomelessCitizens();
					}
				}else{
					resDepartment->addBuilding(new House(homeless,"House"));
					//resDepartment->houseHomelessCitizens();
				}
			}
			case 'T': {
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
			}
			case 'E': {
				resDepartment->addBuilding(new Estate(homeless,"Estate"));
			}
		}


	}
}

void CityGrowthDepartment::increasePopulation() 
{
	population += 10;
	for (int i=0;i<10;i++)
	{
		gov->addCitizen("citizen",i*3);
	}
	//increaseHousing('F');
	//increaseTransport();
	//increaseUtilities();
}

void CityGrowthDepartment::increasePopulation(int num) 
{
	population += num;
	for (int i=0;i<num;i++)
	{
		gov->addCitizen("citizen",i*3);
	}
	//increaseHousing();
	//increaseTransport();
	//increaseUtilities();
}

void CityGrowthDepartment::increaseJobs() 
{
		int c =psDep->buildCommercial(); //psDepartment needs a buildCommercial() to build each type of commercial buildings
		int i= psDep->buildIndustrial(); //same with industrial

	int total = c+i;
	int unemployed = gov->getTotalUnemployed();
	if (total-unemployed>0)
	{
		int openPosts = total-unemployed;
		//char input;
		//std::cout <<"There are " << openPosts << " jobs empty. Would you like to migrate more people?";
		//std::cin >> input;
		//if (input=='y')
		{
			increasePopulation(openPosts);
		}
	}
}

void CityGrowthDepartment::increaseTransport() 
{
	int trains = TransportDep->getTotalTrains();
	int airports = Transport->getTotalAirports();
	int roads = Transport->getTotalRoads();
	int publicTransit =Transport->getTotalPublicTransit();
	//int trafficJam = trains+roads+publicTransit;

	if (resourceManager->getBudget()>1000000000 && airports<7)
	{
		TransportDep->addTransport(new Airport());
	}
	if (resourceManager->getBudget()>2000000)
	{
		TransportDep->addTransport(new Train());
	}
	if (resourceManager->getBudget()>3500000)
	{
		TransportDep->addRoads();
	}
}

void CityGrowthDepartment::increaseUtilities() 
{
	if (resourceManager->getBudget()>500000)
	{
		utilityDep->addBuilding(new PowerPlant());
	}
	if (resourceManager->getBudget()>500000)
	{
		utilityDep->addBuilding(new WaterPlant());
	}
	if (resourceManager->getBudget()>500000)
	{
		utilityDep->addBuilding(new MaterialsPlant());
	}
}


CityGrowthDepartment::CityGrowthDepartment(Government* gov) 
{
	this->resDepartment = gov->getResDepartment();
	this->TransportDep = gov->getTransportDep();
	this->utilityDep = gov->getUtilityDep();
	this->psDep = gov->getPsDep();
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
