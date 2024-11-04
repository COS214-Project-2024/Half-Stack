#include <gtest/gtest.h>
#include <sstream>
#include "Landmark.h"
#include "ResourceManager.h"

class LandmarkTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Landmark* landmarkBuilding;
    std::streambuf* originalCoutBuffer;
    std::ostringstream testOutput;

    void SetUp() override {
        // Initialize ResourceManager singleton and set resource levels
        resourceManager = ResourceManager::instance();
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);

        // Initialize Landmark building and assign ResourceManager
        landmarkBuilding = new Landmark(10, "Historic Square");
        landmarkBuilding->setResourceManager(resourceManager);

        // Redirect std::cout to capture output for testing
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(testOutput.rdbuf());
    }

    void TearDown() override {
        // Restore the original cout buffer and clean up
        std::cout.rdbuf(originalCoutBuffer);
        delete landmarkBuilding;
    }
};

// Test consumeResources with sufficient resources
TEST_F(LandmarkTest, ConsumeResources_SufficientResources_OutputConsumptionMessage) {
    // Invoke consumeResources
    landmarkBuilding->consumeResources();

    // Verify the output message indicates successful resource consumption
    EXPECT_EQ(testOutput.str(), "Landmark building is consuming resources.\n");
}

// Test consumeResources with insufficient resources
TEST_F(LandmarkTest, ConsumeResources_InsufficientResources_OutputNeedMoreResourcesMessage) {
    // Deplete resources to make them insufficient
    resourceManager->decreaseResourceLevels(100, 100, 100, 100, 100);

    // Invoke consumeResources
    landmarkBuilding->consumeResources();

    // Verify the output message indicates lack of resources
    EXPECT_EQ(testOutput.str(), "Need more Resources.\n");
}