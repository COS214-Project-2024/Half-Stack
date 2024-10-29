#ifndef CITYGROWTHDEPARTMENT_H
#define CITYGROWTHDEPARTMENT_H
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "PublicServicesDepartment.h"
#include "UtilitiesDepartment.h"
#include "ResourceManager.h"
//#include "Government.h"
#include "Building.h"
#include <vector>

class Government;

class CityGrowthDepartment : public Department
{

private:

	int population;
	static CityGrowthDepartment* uniqueInstance;

	//std::vector<Citizen*> citizens;
	ResidentialDepartment* resDepartment;
	TransportDepartment* TransportDep;
	UtilitiesDepartment* utilityDep;
	PublicServicesDepartment* psDep;
	ResourceManager* resourceManager;
	Government* gov;

public:
	void increaseHousing(char b);

	void increasePopulation(std::vector<Citizen*> citizens);

	void increaseJobs();

	void increaseTransport();

	void increaseUtilities();

	static CityGrowthDepartment* instance(Government* gov);

protected:
	CityGrowthDepartment(Government* gov);
};

#endif
