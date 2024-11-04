#include <gtest/gtest.h>
#include <sstream>
#include "Industrial.h"
#include "ResourceManager.h"

class IndustrialTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Industrial* industrialBuilding;
    std::streambuf* originalCoutBuffer;
    std::ostringstream testOutput;

    void SetUp() override {
        // Initialize ResourceManager singleton and set resource levels
        resourceManager = ResourceManager::instance();
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);

        // Initialize Industrial building and assign ResourceManager
        industrialBuilding = new Industrial(10, "Industrial Zone");
        industrialBuilding->setResourceManager(resourceManager);

        // Redirect std::cout to capture output for testing
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(testOutput.rdbuf());
    }

    void TearDown() override {
        // Restore the original cout buffer and clean up
        std::cout.rdbuf(originalCoutBuffer);
        delete industrialBuilding;
    }
};

// Test consumeResources with sufficient resources
TEST_F(IndustrialTest, ConsumeResources_SufficientResources_OutputConsumptionMessage) {
    // Invoke consumeResources
    industrialBuilding->consumeResources();

    // Verify the output message indicates successful resource consumption
    EXPECT_EQ(testOutput.str(), "Industrial building is consuming resources.\n");
}

// Test consumeResources with insufficient resources
TEST_F(IndustrialTest, ConsumeResources_InsufficientResources_OutputNeedMoreResourcesMessage) {
    // Deplete resources to make them insufficient
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    // Invoke consumeResources
    industrialBuilding->consumeResources();

    // Verify the output message indicates lack of resources
    EXPECT_EQ(testOutput.str(), "Need more Resources.\n");
}