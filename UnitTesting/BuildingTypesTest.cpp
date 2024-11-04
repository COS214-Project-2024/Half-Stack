#include <gtest/gtest.h>
#include "BuildingTypes.h"  // Include all building types here
#include "ResourceManager.h" // Include ResourceManager

class BuildingTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;

    void SetUp() override {
        resourceManager = ResourceManager::instance();
        // Reset resource levels for each test
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);
        resourceManager->increaseBudget(1000);
    }
};

// House Tests
TEST_F(BuildingTest, HouseBuild_SufficientResources_ReturnsHouse) {
    House house(10, "123 Main St");
    house.setResourceManager(resourceManager);

    Building* builtHouse = house.build();
    EXPECT_NE(builtHouse, nullptr);
    delete builtHouse;
}

TEST_F(BuildingTest, HouseBuild_InsufficientResources_ReturnsNullptr) {
    House house(10, "123 Main St");
    house.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtHouse = house.build();
    EXPECT_EQ(builtHouse, nullptr);
}

// Apartment Tests
TEST_F(BuildingTest, ApartmentBuild_SufficientResources_ReturnsApartment) {
    Apartment apartment(20, "456 Maple St");
    apartment.setResourceManager(resourceManager);

    Building* builtApartment = apartment.build();
    EXPECT_NE(builtApartment, nullptr);
    delete builtApartment;
}

TEST_F(BuildingTest, ApartmentBuild_InsufficientResources_ReturnsNullptr) {
    Apartment apartment(20, "456 Maple St");
    apartment.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtApartment = apartment.build();
    EXPECT_EQ(builtApartment, nullptr);
}

// TownHouse Tests
TEST_F(BuildingTest, TownHouseBuild_SufficientResources_ReturnsTownHouse) {
    TownHouse townHouse(15, "789 Oak St");
    townHouse.setResourceManager(resourceManager);

    Building* builtTownHouse = townHouse.build();
    EXPECT_NE(builtTownHouse, nullptr);
    delete builtTownHouse;
}

TEST_F(BuildingTest, TownHouseBuild_InsufficientResources_ReturnsNullptr) {
    TownHouse townHouse(15, "789 Oak St");
    townHouse.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtTownHouse = townHouse.build();
    EXPECT_EQ(builtTownHouse, nullptr);
}

// Shop Tests
TEST_F(BuildingTest, ShopBuild_SufficientResources_ReturnsShop) {
    Shop shop(30, "321 Elm St");
    shop.setResourceManager(resourceManager);

    Building* builtShop = shop.build();
    EXPECT_NE(builtShop, nullptr);
    delete builtShop;
}

TEST_F(BuildingTest, ShopBuild_InsufficientResources_ReturnsNullptr) {
    Shop shop(30, "321 Elm St");
    shop.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtShop = shop.build();
    EXPECT_EQ(builtShop, nullptr);
}

// Office Tests
TEST_F(BuildingTest, OfficeBuild_SufficientResources_ReturnsOffice) {
    Office office(50, "654 Pine St");
    office.setResourceManager(resourceManager);

    Building* builtOffice = office.build();
    EXPECT_NE(builtOffice, nullptr);
    delete builtOffice;
}

TEST_F(BuildingTest, OfficeBuild_InsufficientResources_ReturnsNullptr) {
    Office office(50, "654 Pine St");
    office.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtOffice = office.build();
    EXPECT_EQ(builtOffice, nullptr);
}

// Mall Tests
TEST_F(BuildingTest, MallBuild_SufficientResources_ReturnsMall) {
    Mall mall(100, "987 Market St");
    mall.setResourceManager(resourceManager);

    Building* builtMall = mall.build();
    EXPECT_NE(builtMall, nullptr);
    delete builtMall;
}

TEST_F(BuildingTest, MallBuild_InsufficientResources_ReturnsNullptr) {
    Mall mall(100, "987 Market St");
    mall.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtMall = mall.build();
    EXPECT_EQ(builtMall, nullptr);
}

// Factory Tests
TEST_F(BuildingTest, FactoryBuild_SufficientResources_ReturnsFactory) {
    Factory factory(70, "555 Industrial Rd");
    factory.setResourceManager(resourceManager);

    Building* builtFactory = factory.build();
    EXPECT_NE(builtFactory, nullptr);
    delete builtFactory;
}

TEST_F(BuildingTest, FactoryBuild_InsufficientResources_ReturnsNullptr) {
    Factory factory(70, "555 Industrial Rd");
    factory.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtFactory = factory.build();
    EXPECT_EQ(builtFactory, nullptr);
}

// Warehouse Tests
TEST_F(BuildingTest, WarehouseBuild_SufficientResources_ReturnsWarehouse) {
    Warehouse warehouse(80, "111 Storage Ave");
    warehouse.setResourceManager(resourceManager);

    Building* builtWarehouse = warehouse.build();
    EXPECT_NE(builtWarehouse, nullptr);
    delete builtWarehouse;
}

TEST_F(BuildingTest, WarehouseBuild_InsufficientResources_ReturnsNullptr) {
    Warehouse warehouse(80, "111 Storage Ave");
    warehouse.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtWarehouse = warehouse.build();
    EXPECT_EQ(builtWarehouse, nullptr);
}

// Park Tests
TEST_F(BuildingTest, ParkBuild_SufficientResources_ReturnsPark) {
    Park park(60, "222 Green St");
    park.setResourceManager(resourceManager);

    Building* builtPark = park.build();
    EXPECT_NE(builtPark, nullptr);
    delete builtPark;
}

TEST_F(BuildingTest, ParkBuild_InsufficientResources_ReturnsNullptr) {
    Park park(60, "222 Green St");
    park.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtPark = park.build();
    EXPECT_EQ(builtPark, nullptr);
}

// Monument Tests
TEST_F(BuildingTest, MonumentBuild_SufficientResources_ReturnsMonument) {
    Monument monument(25, "333 Monument Ln");
    monument.setResourceManager(resourceManager);

    Building* builtMonument = monument.build();
    EXPECT_NE(builtMonument, nullptr);
    delete builtMonument;
}

TEST_F(BuildingTest, MonumentBuild_InsufficientResources_ReturnsNullptr) {
    Monument monument(25, "333 Monument Ln");
    monument.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtMonument = monument.build();
    EXPECT_EQ(builtMonument, nullptr);
}

// CulturalCentre Tests
TEST_F(BuildingTest, CulturalCentreBuild_SufficientResources_ReturnsCulturalCentre) {
    CulturalCentre culturalCentre(40, "444 Arts Ave");
    culturalCentre.setResourceManager(resourceManager);

    Building* builtCulturalCentre = culturalCentre.build();
    EXPECT_NE(builtCulturalCentre, nullptr);
    delete builtCulturalCentre;
}

TEST_F(BuildingTest, CulturalCentreBuild_InsufficientResources_ReturnsNullptr) {
    CulturalCentre culturalCentre(40, "444 Arts Ave");
    culturalCentre.setResourceManager(resourceManager);
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    Building* builtCulturalCentre = culturalCentre.build();
    EXPECT_EQ(builtCulturalCentre, nullptr);
}