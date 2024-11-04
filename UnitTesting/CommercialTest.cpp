#include <gtest/gtest.h>
#include <sstream>
#include "Commercial.h"
#include "ResourceManager.h"

class CommercialTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Commercial* commercialBuilding;
    std::streambuf* originalCoutBuffer;
    std::ostringstream testOutput;

    void SetUp() override {
        // Initialize the ResourceManager singleton and set resource levels
        resourceManager = ResourceManager::instance();
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);
        
        // Initialize the Commercial building and assign the ResourceManager
        commercialBuilding = new Commercial(10, "123 Business St");
        commercialBuilding->setResourceManager(resourceManager);

        // Redirect std::cout to capture output for testing
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(testOutput.rdbuf());
    }

    void TearDown() override {
        // Restore the original cout buffer and clean up
        std::cout.rdbuf(originalCoutBuffer);
        delete commercialBuilding;
    }
};

// Test consumeResources with sufficient resources
TEST_F(CommercialTest, ConsumeResources_SufficientResources_OutputConsumptionMessage) {
    // Invoke consumeResources
    commercialBuilding->consumeResources();

    // Check that the output message indicates successful resource consumption
    EXPECT_EQ(testOutput.str(), "Commercial building is consuming resources.\n");
}

// Test consumeResources with insufficient resources
TEST_F(CommercialTest, ConsumeResources_InsufficientResources_OutputNeedMoreResourcesMessage) {
    // Reduce resources to make them insufficient
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    // Invoke consumeResources
    commercialBuilding->consumeResources();

    // Check that the output message indicates lack of resources
    EXPECT_EQ(testOutput.str(), "Need more Resources.\n");
}