#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Government.h"
#include "Citizen.h"
#include "ResidentialDepartment.h"
#include "ResourceManager.h"
#include "PublicServicesDepartment.h"
#include "TransportDepartment.h"
#include "UtilitiesDepartment.h"
#include "CityGrowthDepartment.h"
#include "LawDepartment.h"

// Mock classes (or use the actual implementations if they're not complex)
class MockCitizen : public Citizen {
public:
    MockCitizen(int age) : Citizen(age) {}
    // Override methods as necessary for your tests
};


TEST_CASE("Government Singleton Instance") {
    Government* gov1 = Government::instance("Test City");
    Government* gov2 = Government::instance("Another City");
    CHECK(gov1 == gov2); // Both should point to the same instance
}

TEST_CASE("Add Citizen - Successful") {
    Government* gov = Government::instance("Test City");
    Citizen* citizen = new MockCitizen(30);

    gov->addCitizen(citizen);
    CHECK(gov->getTotalCitizens() == 1); // Ensure citizen is added
    CHECK(gov->getTotalUnemployed() == 1);
    CHECK(gov->hasCitizen(citizen) == true); // Check if the citizen is registered
}

TEST_CASE("Get Total Unemployed") {
    Government* gov = Government::instance("Test City");
    // Add employed and unemployed citizens
    Citizen* employed = new MockCitizen(30);
    employed->setEmployment(new Employed());
    
    Citizen* unemployed = new MockCitizen(25);
    unemployed->setEmployment(new Unemployed());

    gov->addCitizen(employed);
    gov->addCitizen(unemployed);

    CHECK(gov->getTotalUnemployed() == 2);
    CHECK(gov->getTotalEmployed() == 1);
}

TEST_CASE("City Stats Report") {
    Government* gov = Government::instance("Test City");

    // Populate the government with some citizens
    gov->addCitizen(new MockCitizen(30));
    gov->addCitizen(new MockCitizen(25));

    std::cout << gov->getHomeless() << std::endl;
    
    // Capture output
    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    gov->getCityStats(); // Call the method that prints city stats

    std::cout.rdbuf(oldCout); // Reset to original buffer

    // Check if the expected output is present
    CHECK(buffer.str().find("Population: 5") != std::string::npos);
    CHECK(buffer.str().find("Homeless: 5") != std::string::npos);
}

TEST_CASE("Add Citizen - Homeless Limit") {
    Government* gov = Government::instance("Test City");
    gov->addCitizen(new MockCitizen(30)); // First citizen
    gov->addCitizen(new MockCitizen(25));   // Second citizen

    // Assuming the homeless limit is being checked here
    for (int i = 0; i < 100; ++i) {
        gov->addCitizen(new MockCitizen(20)); // Try adding more
    }
    CHECK(gov->getHomeless() > 0); // Expect some citizens to be homeless
}
