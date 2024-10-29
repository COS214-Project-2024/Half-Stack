#ifndef CITYGROWTHDEPARTMENT_H
#define CITYGROWTHDEPARTMENT_H
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "UtilitiesDepartment.h"
#include "Building.h"
#include <vector>

class CityGrowthDepartment : public Department
{

private:

	int population;
	CityGrowthDepartment* uniqueInstance;

	//std::vector<Citizen*> citizens;
	ResidentialDepartment* resDepartment;
	TransportDepartment* TransportDep;
	UtilitiesDepartment* utilityDep;
	PublicServicesDep* psDep;
	ResourceManage* resourceManager;
	Government* gov;

public:
	void increaseHousing();

	void increasePopulation();

	void increasePopulation(int num);

	void increaseJobs();

	void increaseTransport();

	void increaseUtilities();

	CityGrowthDepartment* instance(Government* gov);

protected:
	CityGrowthDepartment(Government* gov);
};

#endif
