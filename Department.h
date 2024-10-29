#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Building.h"
#include <vector>

class Department
{

	private:

		std::vector<Building*> buildings;

	public:

		Department();

		void addBuilding(Building* b);

		void removeBuilding(Building* b);
};

#endif
