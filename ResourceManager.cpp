#include "ResourceManager.h"
#include <iostream>
#include <algorithm>

ResourceManager* ResourceManager::Singleton = nullptr;

ResourceManager::ResourceManager()
{ 
	this->waterLevel = 0;
	this->energyLevel = 0;
	this->budget = 0.0;
	this->wood = 0;
	this->steel = 0;
	this->generalMaterials = 0;
}

ResourceManager* ResourceManager::instance() 
{
    if (Singleton == nullptr) 
	{
        Singleton = new ResourceManager();
    }

    return Singleton;
}


bool ResourceManager::decreaseResourceLevels(int water, int energy, int wood, int steel, int materials) 
{
    if ((this->waterLevel - water < 0) || (this->energyLevel - energy < 0) || (this->wood - wood < 0) || (this->steel - steel < 0) || (this->generalMaterials - materials < 0)) //check enough resources
    {
        std::cout << "Not enough resources";
        return false;
    }

    this->waterLevel -= water;
    this->energyLevel -= energy;
    this->wood -= wood;
    this->steel -= steel;
    this->generalMaterials -= materials;

    std::cout << "Updated City resource levels - Water: " << this->waterLevel
              << ", Energy: " << this->energyLevel
              << ", Wood: " << this->wood
              << ", Steel: " << this->steel
              << ", General Materials: " << this->generalMaterials << std::endl;

    return true;
}

bool ResourceManager::decreaseBudget(int money)
{
    if (this->budget - money < 0)
    {
        std::cout << "Not enough budget" << std::endl;
        return false;
    }

	this->budget -= money;

	std::cout << "Updated City Budget: " << this->budget << std::endl;
}

void ResourceManager::increaseResourceLevels(int water, int energy, int wood, int steel, int materials)
{
    this->waterLevel += water;
    this->energyLevel += energy;
    this->wood += wood;
    this->steel += steel;
    this->generalMaterials += materials;

    std::cout << "Updated City resource levels - Water: " << this->waterLevel
              << ", Energy: " << this->energyLevel
              << ", Wood: " << this->wood
              << ", Steel: " << this->steel
              << ", General Materials: " << this->generalMaterials << std::endl;
}

void ResourceManager::increaseBudget(int money)
{
    this->budget += money;

    std::cout << "Updated City Budget: " << this->budget << std::endl;
}



//BELOW ARE FUNCTIONS THAT WERE IMPLEMENTED IN THE OBSERVER PATTERN FOR RESOURCE MANAGER WHICH I DON'T THINK IS NECESSARY

// bool ResourceManager::attachBuilding(Building* building) 
// {
// 	if (building != nullptr) 
// 	{
//         buildingList.push_back(building);

//         return true;
//     }

//     return false;
// }

// bool ResourceManager::detachBuilding(Building* building) 
// {
// 	auto it = std::find(buildingList.begin(), buildingList.end(), building);

//     if (it != buildingList.end()) 
// 	{
//         buildingList.erase(it);
//         return true;
//     }
	
//     return false;
// }

// void ResourceManager::notify() 
// {
// 	for (Building* building : buildingList) 
// 	{
//         if (building) 
// 		{
//             building->update();
//         }
//     }

//     for (Department* department : departmentList) 
// 	{
//         if (department) 
// 		{
//             department->update(); 
//         }
//     }
// }

// bool ResourceManager::attachDepartment(Department* department) 
// {
// 	if (department != nullptr) 
// 	{
//         departmentList.push_back(department);

//         return true;
//     }

//     return false;
// }

// bool ResourceManager::detachDepartment(Department* department) 
// {
// 	auto it = std::find(departmentList.begin(), departmentList.end(), department);

//     if (it != departmentList.end()) 
// 	{
//         departmentList.erase(it);
//         return true;
//     }
//     return false;
// }
