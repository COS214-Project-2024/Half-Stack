#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BuildingTypes.h"
#include "BuildingState.h"
#include "ResidentialDepartment.h"
#include "ResourceManager.h"

// Test for the build() function in House
TEST_CASE("House::build() function") {
    ResourceManager* resourceManager = ResourceManager::instance();
    
    // Simulate having enough resources
    resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);
    
    House house(5, "Downtown");
    Building* builtHouse = house.build();
    
    CHECK(builtHouse != nullptr); // Check if the house was successfully built
    
    // Simulate insufficient resources
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);
    Building* failedHouse = house.build();
    
    CHECK(failedHouse == nullptr); // Check if the building fails with insufficient resources
}

// Test for the build() function in Apartment
TEST_CASE("Apartment::build() function") {
    ResourceManager* resourceManager = ResourceManager::instance();
    
    // Simulate having enough resources
    resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);
    
    Apartment apartment(10, "City Center");
    Building* builtApartment = apartment.build();
    
    CHECK(builtApartment != nullptr); // Check if the apartment was successfully built
    
    // Simulate insufficient resources
    resourceManager->decreaseResourceLevels(95, 90, 88, 88, 80);
    Building* failedApartment = apartment.build();
    
    CHECK(failedApartment == nullptr); // Check if the building fails with insufficient resources
}

// Test for the update() function in BuildingState
TEST_CASE("BuildingState::update() function") {
    BuildingState* state = new Planning();
    
    CHECK(state->getStatus() == "PLANNING");
    
    BuildingState* nextState = state->update();
    CHECK(nextState->getStatus() == "CONSTRUCTION");
    
    delete state;
    state = nextState;
    
    nextState = state->update();
    CHECK(nextState->getStatus() == "OPERATIONAL");
    
    delete state;
    state = nextState;
    
    nextState = state->update();
    CHECK(nextState->getStatus() == "RENOVATION");
    
    delete state;
    state = nextState;
    
    nextState = state->update();
    CHECK(nextState->getStatus() == "OPERATIONAL"); // Renovation loops back to Operational
    
    delete state;
    delete nextState;
}

// Test for ResidentialDepartment functions
TEST_CASE("ResidentialDepartment functions") {
    ResidentialDepartment* department = ResidentialDepartment::instance();
    ResourceManager* resourceManager = ResourceManager::instance();
    
    resourceManager->increaseResourceLevels(1000, 1000, 1000, 1000, 1000);
    resourceManager->increaseBudget(10000);
    
    Residential* house = new House(5, "Area 1");
    department->addBuilding(house);
    
    CHECK(department->getTotalBuildings() == 1); // Check if building was added
    CHECK(department->getTotalCapacity() == 5);  // Check capacity
    
    Residential* apartment = new Apartment(10, "Area 2");
    department->addBuilding(apartment);
    
    CHECK(department->getTotalBuildings() == 2); // Check if second building was added
    CHECK(department->getTotalCapacity() == 15); // Check total capacity

    department->removeBuilding(house);
    CHECK(department->getTotalBuildings() == 1); // Check if building was removed
    
    department->removeBuilding(apartment);
    CHECK(department->getTotalBuildings() == 0); // Check if all buildings were removed
}
