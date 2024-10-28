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

	ResidentialDepartment* resDepartment;
	TransportDepartment* TransportDep;
	UtilitiesDepartment* utilityDep;

public:
	void increaseHousing();

	void increasePopulation();

	void increaseJobs();

	void increaseTransport();

	void increaseUtilities();

	CityGrowthDepartment();
};

#endif
