#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ResourceManager.h"
#include "Plant.h"

TEST_SUITE("Plant Tests") 
{
    TEST_CASE("Test Plant Initialization") 
    {
        ResourceManager::instance()->increaseResourceLevels(20, 20, 400, 400, 200);

        PowerPlant powerPlant(100, "FactoryZone");
        CHECK(powerPlant.getType() == "Power");
        CHECK(powerPlant.capacity == 100);
        CHECK(powerPlant.location == "FactoryZone");

        WaterPlant waterPlant(50, "WaterZone");
        CHECK(waterPlant.getType() == "Water");
        CHECK(waterPlant.capacity == 50);
        CHECK(waterPlant.location == "WaterZone");
    }

    TEST_CASE("Test ResourceManager Decreases on PowerPlant Creation") 
    {
        ResourceManager::instance()->increaseResourceLevels(100, 100, 100, 100, 100);

        PowerPlant powerPlant(100, "FactoryZone");
        
        CHECK(ResourceManager::instance()->getWaterLevel() == 140);
        CHECK(ResourceManager::instance()->getEnergyLevel() == 140);
        CHECK(ResourceManager::instance()->getWood() == 700);
        CHECK(ResourceManager::instance()->getSteel() == 700);
        CHECK(ResourceManager::instance()->getGeneralMaterials() == 420);

        ResourceManager::instance()->decreaseResourceLevels(0, 75, 0, 25, 0);

        CHECK(ResourceManager::instance()->getWaterLevel() == 140);
        CHECK(ResourceManager::instance()->getEnergyLevel() == 65);
        CHECK(ResourceManager::instance()->getWood() == 700);
        CHECK(ResourceManager::instance()->getSteel() == 675);
        CHECK(ResourceManager::instance()->getGeneralMaterials() == 420);

        ResourceManager::instance()->increaseResourceLevels(0, 75, 0, 25, 0);
    }

    TEST_CASE("Test ResourceManager Decreases on WaterPlant Creation") 
    {
        ResourceManager::instance()->increaseResourceLevels(100, 100, 100, 100, 100);

        WaterPlant waterPlant(50, "WaterZone");

        CHECK(ResourceManager::instance()->getWaterLevel() == 240);
        CHECK(ResourceManager::instance()->getEnergyLevel() == 240);
        CHECK(ResourceManager::instance()->getWood() == 750);
        CHECK(ResourceManager::instance()->getSteel() == 750);
        CHECK(ResourceManager::instance()->getGeneralMaterials() == 500);

        ResourceManager::instance()->decreaseResourceLevels(50, 0, 0, 0, 0);

        CHECK(ResourceManager::instance()->getWaterLevel() == 190);
        CHECK(ResourceManager::instance()->getEnergyLevel() == 240);
        CHECK(ResourceManager::instance()->getWood() == 750);
        CHECK(ResourceManager::instance()->getSteel() == 750);
        CHECK(ResourceManager::instance()->getGeneralMaterials() == 500);

        ResourceManager::instance()->increaseResourceLevels(50, 0, 0, 0, 0);
    }

    TEST_CASE("Test PowerPlant Generate Function") 
    {
        ResourceManager::instance()->increaseResourceLevels(100, 100, 100, 100, 100);

        PowerPlant powerPlant(100, "FactoryZone");
        powerPlant.generate();

        CHECK(ResourceManager::instance()->getEnergyLevel() == 840);

        ResourceManager::instance()->decreaseResourceLevels(100, 0, 0, 0, 0);
    }

    TEST_CASE("Test WaterPlant Generate Function") 
    {
        ResourceManager::instance()->increaseResourceLevels(100, 100, 100, 100, 100);

        WaterPlant waterPlant(50, "WaterZone");
        waterPlant.generate();

        CHECK(ResourceManager::instance()->getWaterLevel() == 840);

        ResourceManager::instance()->decreaseResourceLevels(100, 0, 0, 0, 0);
    }

    TEST_CASE("Test PowerPlant Build Function") 
    {
        PowerPlant powerPlant(100, "FactoryZone");
        Building* newPlant = powerPlant.build();

        CHECK(dynamic_cast<PowerPlant*>(newPlant) != nullptr);
        delete newPlant;
    }

    TEST_CASE("Test WaterPlant Build Function") 
    {
        WaterPlant waterPlant(50, "WaterZone");
        Building* newPlant = waterPlant.build();

        CHECK(dynamic_cast<WaterPlant*>(newPlant) != nullptr);
        delete newPlant;
    }
}