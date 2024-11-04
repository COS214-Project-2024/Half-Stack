#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "CityGrowthDepartment.h"
#include "Government.h"
#include "BuildingTypes.h"
#include "ResourceManager.h"
#include <vector>

TEST_CASE("increaseHousing")
{
    Government* gov = Government::instance("gov");
    gov->addCitizen(new Citizen(21));
    gov->addCitizen(new Citizen(21));
    gov->addCitizen(new Citizen(21));
    gov->addCitizen(new Citizen(21));
    CityGrowthDepartment* cg = CityGrowthDepartment::instance(gov);
    ResourceManager* rm = ResourceManager::instance();

    SUBCASE("Apartment")
    {
        rm->decreaseResourceLevels(20,20,400,400,200);
        rm->decreaseBudget(10400);
        bool output = cg->increaseHousing('A');
        CHECK(output==false);
    }

    rm->increaseResourceLevels(1000,1000,1000,1000,1000);
    rm->increaseBudget(1000);
    SUBCASE("Apartment")
    {
        bool output = cg->increaseHousing('A');
        CHECK(output==true);
        int h =gov->getHomeless();
        CHECK(h<=4);
    }
    SUBCASE("House")
    {
        bool output = cg->increaseHousing('H');
        CHECK(output==true);
        int h =gov->getHomeless();
        CHECK(h<=3);
    }
    SUBCASE("Townhouse")
    {
        bool output = cg->increaseHousing('T');
        CHECK(output==true);
        int h =gov->getHomeless();
        CHECK(h<=9);
    }

}

TEST_CASE("increasePopulation")
{
    Government* gov = Government::instance("gov");
    CityGrowthDepartment* cg = CityGrowthDepartment::instance(gov);
    ResourceManager* rm = ResourceManager::instance();
    rm->increaseResourceLevels(1000,1000,1000,1000,1000);
    rm->increaseBudget(1000);
    
    SUBCASE("vector")
    {
        std::vector<Citizen*> newCitizens;
        Citizen* Keanu = new Citizen(21);
        Citizen* Devan = new Citizen(20);
        Citizen* Austin = new Citizen(19);
        Citizen* Sashen = new Citizen(20);
        Citizen* Stone = new Citizen(20);
        Citizen* Jamean = new Citizen(20);
        Citizen* Ayush = new Citizen(21);
        newCitizens.push_back(Keanu);
        newCitizens.push_back(Devan);
        newCitizens.push_back(Austin);
        newCitizens.push_back(Sashen);
        newCitizens.push_back(Stone);
        newCitizens.push_back(Jamean);
        newCitizens.push_back(Ayush);
        cg->increasePopulation(newCitizens);

        int p = cg->getPopulation();
        CHECK(p==7);
    }

    SUBCASE("increase by 10")
    {
        cg->increasePopulation();
        int p = cg->getPopulation();
        CHECK(p==10);
    }

}