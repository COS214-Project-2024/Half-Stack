#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Building.h"
#include <vector>

class Department {

	private:

		std::vector<Building*> buildings;

	public:

		void addBuilding(Building* building);

		void removeBuilding(Building* building);

		void update();

};

#endif
