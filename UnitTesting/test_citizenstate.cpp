#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Satisfaction.h"
#include "Citizen.h"
#include "Employment.h"
#include "BuildingTypes.h"

// Test for Satisfaction Class
TEST_CASE("Satisfaction status transitions") {
    Satisfaction* satisfaction = new Neutral();
    
    // Check initial status
    CHECK(satisfaction->getStatus() == "Neutral");

    // Raise to Satisfied
    satisfaction = satisfaction->raiseStatus();
    CHECK(satisfaction->getStatus() == "Satisfied");

    // Try to raise again (should stay the same)
    satisfaction = satisfaction->raiseStatus();
    CHECK(satisfaction->getStatus() == "Satisfied");

    // Lower to Neutral
    satisfaction = satisfaction->lowerStatus();
    CHECK(satisfaction->getStatus() == "Neutral");

    // Lower to Unsatisfied
    satisfaction = satisfaction->lowerStatus();
    CHECK(satisfaction->getStatus() == "Unsatisfied");

    // Try to lower again (should stay the same)
    satisfaction = satisfaction->lowerStatus();
    CHECK(satisfaction->getStatus() == "Unsatisfied");

    delete satisfaction;
}

// Test for Citizen Class
TEST_CASE("Citizen functionality") 
{
    Citizen citizen(25); // Create a Citizen of age 25

    // Check initial status
    CHECK(citizen.getAge() == 25);
    CHECK(citizen.getSatisfaction()->getStatus() == "Neutral");
    CHECK(citizen.getEmployment()->getStatus() == "Unemployed");
    std::cout<<"Passed 1" << std::endl;

    // Check job setting
    citizen.setJob(new Office(20,"Office")); // Assuming Building is defined
    CHECK(citizen.getEmployment()->getStatus() == "Employed");
    std::cout<<"Passed 2" << std::endl;

    // Test satisfaction levels after notifications
    citizen.receiveNotification("No power and water");
    CHECK(citizen.getSatisfaction()->getStatus() == "Unsatisfied");
    std::cout<<"Passed 3" << std::endl;

    citizen.receiveNotification("Load-shedding has ended.");
    CHECK(citizen.getSatisfaction()->getStatus() == "Neutral");
    std::cout<<"Passed 4" << std::endl;

    citizen.receiveNotification("Some random notification");
    CHECK(citizen.getSatisfaction()->getStatus() == "Unsatisfied");
    std::cout<<"Passed 5" << std::endl;
}

// Test for Employment Class
TEST_CASE("Employment status transitions") {
    Employment* employment = new Unemployed();

    // Check initial status
    CHECK(employment->getStatus() == "Unemployed");

    // Toggle to Employed
    employment = employment->toggleStatus();
    CHECK(employment->getStatus() == "Employed");

    // Toggle back to Unemployed
    employment = employment->toggleStatus();
    CHECK(employment->getStatus() == "Unemployed");

    delete employment;
}
