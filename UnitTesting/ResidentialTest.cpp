#include <gtest/gtest.h>
#include <sstream>
#include "Residential.h"
#include "ResourceManager.h"

class ResidentialTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Residential* residentialBuilding;
    std::streambuf* originalCoutBuffer;
    std::ostringstream testOutput;

    void SetUp() override {
        // Initialize ResourceManager singleton and set resource levels
        resourceManager = ResourceManager::instance();
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);

        // Initialize Residential building and assign ResourceManager
        residentialBuilding = new Residential(10, "Residential Area");
        residentialBuilding->setResourceManager(resourceManager);

        // Redirect std::cout to capture output for testing
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(testOutput.rdbuf());
    }

    void TearDown() override {
        // Restore the original cout buffer and clean up
        std::cout.rdbuf(originalCoutBuffer);
        delete residentialBuilding;
    }
};

// Test consumeResources with sufficient resources
TEST_F(ResidentialTest, ConsumeResources_SufficientResources_OutputConsumptionMessage) {
    residentialBuilding->consumeResources();
    EXPECT_EQ(testOutput.str(), "Residential building is consuming resources.\n");
}

// Test consumeResources with insufficient resources
TEST_F(ResidentialTest, ConsumeResources_InsufficientResources_OutputNeedMoreResourcesMessage) {
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100); // Deplete resources

    residentialBuilding->consumeResources();
    EXPECT_EQ(testOutput.str(), "Need more Resources.\n");
}

class EstateTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Estate* estateBuilding;

    void SetUp() override {
        // Initialize ResourceManager singleton and set resource levels
        resourceManager = ResourceManager::instance();
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);

        // Initialize Estate building and assign ResourceManager
        estateBuilding = new Estate(20, "Estate Area");
        estateBuilding->setResourceManager(resourceManager);
    }

    void TearDown() override {
        delete estateBuilding;
    }
};

// Test build with sufficient resources
TEST_F(EstateTest, Build_SufficientResources_ReturnsEstate) {
    Building* builtEstate = estateBuilding->build();
    EXPECT_NE(builtEstate, nullptr);
    delete builtEstate;
}

// Test build with insufficient resources
TEST_F(EstateTest, Build_InsufficientResources_ReturnsNullptr) {
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100); // Deplete resources

    Building* builtEstate = estateBuilding->build();
    EXPECT_EQ(builtEstate, nullptr);
}