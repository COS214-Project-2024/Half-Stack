#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Building.h"
#include "Department.h"

#include <vector>

// class Building;
// class Department;

class ResourceManager 
{

private:
	static ResourceManager* Singleton;
	int waterLevel;
	int energyLevel;
	double budget;
	int wood;
	int steel;
	int generalMaterials;
	// std::vector<Building*> buildingList;
    // std::vector<Department*> departmentList;

	ResourceManager();

public:
	static ResourceManager* instance();

	bool decreaseResourceLevels(int water, int energy, int wood, int steel, int materials);
	bool decreaseBudget(int money);
	
	void increaseResourceLevels(int water, int energy, int wood, int steel, int materials);
	void increaseBudget(int money);

    int getWaterLevel() const { return waterLevel; }
    int getEnergyLevel() const { return energyLevel; }
    int getWood() const { return wood; }
    int getSteel() const { return steel; }
    int getGeneralMaterials() const { return generalMaterials; }

	~ResourceManager();



	//FUNCTIONS IF RESOURCEMANAGER IS THE SUBJECT

	// bool attachBuilding(Building* building);

	// bool detachBuilding(Building* building);

	// void notify();

	// bool attachDepartment(Department* department);

	// bool detachDepartment(Department* department);
};

#endif
