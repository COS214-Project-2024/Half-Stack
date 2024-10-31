#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "UtilitiesDepartment.h"
#include "PublicServicesDepartment.h"
#include "LawDepartment.h"
#include "CityGrowthDepartment.h"
#include "ResourceManager.h"
#include <vector>

class Government : public Department {

private:
	std::vector<Department*> departments;
	std::string name;
	static Government* uniqueInstance;
	std::vector<Citizen*> citizens;

	ResidentialDepartment* resDep;
	TransportDepartment* transportDep;
	UtilitiesDepartment* utilityDep;
	PublicServicesDepartment* psDep;
	LawDepartment* lawDep;
	CityGrowthDepartment* cgDep;
	ResourceManager* resourceManager;

protected:
	Government(std::string name);

public:
	static Government* instance(std::string name);

	ResidentialDepartment* getResidentialDepartment();
	TransportDepartment* getTransportDepartment();
	UtilitiesDepartment* getUtilitiesDepartment();
	PublicServicesDepartment* getPublicServicesDepartment();
	LawDepartment* getLawDepartment();
	CityGrowthDepartment* getCityGrowthDepartment();
	ResourceManager* getResourceManager();

	~Government();
	void addCitizen(Citizen* c);
	bool hasCitizen(Citizen* c);
	int getTotalCitizens();
	int getTotalUnemployed();
};

#endif
