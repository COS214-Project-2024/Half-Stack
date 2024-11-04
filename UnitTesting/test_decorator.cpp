#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Residential.h"
#include "Amenity.h"
#include "ResourceManager.h"
#include "BuildingTypes.h"
#include "Citizen.h"

// Test Amenity decorators
TEST_CASE("Testing Amenity decorators") {
    Residential* baseRes = new House(3, "Central Park");

    SUBCASE("Test Gym decorator") {
        Gym gym(baseRes);
        gym.consumeResources();  // Should increase power consumption
        CHECK(baseRes->getNumResidents() == 0);  // Still no residents
    }

    SUBCASE("Test Pool decorator") {
        Pool pool(baseRes);
        pool.consumeResources();  // Should increase water consumption
        CHECK(baseRes->getNumResidents() == 0);  // Still no residents
    }

    SUBCASE("Test Internet decorator") {
        Internet internet(baseRes);
        internet.consumeResources();  // Should increase power consumption
        CHECK(baseRes->getNumResidents() == 0);  // Still no residents
    }

    SUBCASE("Test Garden decorator") {
        Garden garden(baseRes);
        garden.consumeResources();  // Should increase water consumption
        CHECK(baseRes->getNumResidents() == 0);  // Still no residents
    }
}
