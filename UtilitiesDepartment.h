#ifndef UTILITIESDEPARTMENT_H
#define UTILITIESDEPARTMENT_H

#include "Building.h"
#include "Department.h"
#include "UtilityCommand.h"

class UtilitiesDepartment : public Department
{

private:
	UtilitiesDepartment();

	static UtilitiesDepartment uniqueInstance;

	UtilityCommand* commands[4];

public:

	~UtilitiesDepartment();

	static UtilitiesDepartment& instance();

	void supplyWater();

	void supplyEnergy();

	void manageWaste();

	void manageSewage();

	void performRoutine();
};

#endif
