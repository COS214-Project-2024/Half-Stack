#ifndef RESIDENTIALDEPARTMENT_H
#define RESIDENTIALDEPARTMENT_H

#include "Building.h"
#include "Department.h"

class ResidentialDepartment : public Department
{
	private:

		std::vector<Building*> residents;

	public:

		ResidentialDepartment();

		void addBuilding(Building* b);
		void removeBuilding(Building* b);

		int getTotalBuildings();
		int getTotalCapacity();
};

#endif