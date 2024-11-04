#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Building.h"
#include "Department.h"

#include <vector>

// class Building;
// class Department;

/**
 * @class ResourceManager
 * @brief Manages the resources and budget of the city.
 * 
 * Implements a singleton pattern to ensure only one instance
 * exists throughout the application. Responsible for resource
 * allocation, budgeting, and updating resource levels.
 */
class ResourceManager 
{

private:
	static ResourceManager* Singleton; ///< Pointer to the single instance of ResourceManager.
	int waterLevel; ///< Current water level.
	int energyLevel; ///< Current energy level.
	double budget; ///< Current budget.
	int wood; ///< Current wood amount.
	int steel; ///< Current steel amount.
	int generalMaterials; ///< Current general materials amount.
	// std::vector<Building*> buildingList;
    // std::vector<Department*> departmentList;

	///< Private constructor for Singleton.
	ResourceManager();

public:
	/** 
     * @brief Gets the singleton instance of ResourceManager.
     * @return Pointer to the instance of ResourceManager.
     */
	static ResourceManager* instance();

	/**
     * @brief Decreases resource levels based on provided amounts.
     * @param water Amount of water to decrease.
     * @param energy Amount of energy to decrease.
     * @param wood Amount of wood to decrease.
     * @param steel Amount of steel to decrease.
     * @param materials Amount of general materials to decrease.
     * @return True if resources were successfully decreased, false otherwise.
     */
	bool decreaseResourceLevels(int water, int energy, int wood, int steel, int materials);
	
	/**
     * @brief Decreases the budget by the specified amount.
     * @param money Amount of money to decrease.
     * @return True if the budget was successfully decreased, false otherwise.
     */
	bool decreaseBudget(int money);
	
	/**
     * @brief Increases resource levels based on provided amounts.
     * @param water Amount of water to increase.
     * @param energy Amount of energy to increase.
     * @param wood Amount of wood to increase.
     * @param steel Amount of steel to increase.
     * @param materials Amount of general materials to increase.
     */
	void increaseResourceLevels(int water, int energy, int wood, int steel, int materials);
	
	/**
     * @brief Increases the budget by the specified amount.
     * @param money Amount of money to increase.
     */
	void increaseBudget(double money);

	/**
     * @brief Gets the current water level.
     * @return Current water level.
     */
    int getWaterLevel() const { return waterLevel; }

	/**
     * @brief Gets the current energy level.
     * @return Current energy level.
     */
    int getEnergyLevel() const { return energyLevel; }

	/**
     * @brief Gets the current wood amount.
     * @return Current wood amount.
     */
    int getWood() const { return wood; }

	/**
     * @brief Gets the current steel amount.
     * @return Current steel amount.
     */
    int getSteel() const { return steel; }

	/**
     * @brief Gets the current general materials amount.
     * @return Current general materials amount.
     */
    int getGeneralMaterials() const { return generalMaterials; }

	/**
     * @brief Gets the current budget amount.
     * @return Current budget amount.
     */
    double getBudget() const { return budget;}

	/** 
     * @brief Destructor for ResourceManager.
     */
	~ResourceManager();



	//FUNCTIONS IF RESOURCEMANAGER IS THE SUBJECT

	// bool attachBuilding(Building* building);

	// bool detachBuilding(Building* building);

	// void notify();

	// bool attachDepartment(Department* department);

	// bool detachDepartment(Department* department);
};

#endif
