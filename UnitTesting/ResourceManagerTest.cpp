#include <gtest/gtest.h>
#include "ResourceManager.h"

class ResourceManagerTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;

    void SetUp() override {
        // Initialize the ResourceManager singleton instance
        resourceManager = ResourceManager::instance();
        // Reset resources to a known state for each test
        resourceManager->increaseResourceLevels(100, 100, 100, 100, 100);
        resourceManager->increaseBudget(1000);
    }
    
    void TearDown() override {
        // Optionally reset state after each test if necessary
    }
};

// Test decreaseResourceLevels with sufficient resources
TEST_F(ResourceManagerTest, DecreaseResourceLevels_SufficientResources_ReturnsTrue) {
    // Decrease resources with sufficient levels
    bool result = resourceManager->decreaseResourceLevels(20, 20, 20, 20, 20);
    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager->getWaterLevel(), 80);
    EXPECT_EQ(resourceManager->getEnergyLevel(), 80);
    EXPECT_EQ(resourceManager->getWoodLevel(), 80);
    EXPECT_EQ(resourceManager->getSteelLevel(), 80);
    EXPECT_EQ(resourceManager->getGeneralMaterialsLevel(), 80);
}

// Test decreaseResourceLevels with insufficient resources
TEST_F(ResourceManagerTest, DecreaseResourceLevels_InsufficientResources_ReturnsFalse) {
    // Attempt to decrease more resources than available
    bool result = resourceManager->decreaseResourceLevels(150, 20, 20, 20, 20);
    EXPECT_FALSE(result);  // Expect failure due to insufficient water level
}

// Test decreaseBudget with sufficient funds
TEST_F(ResourceManagerTest, DecreaseBudget_SufficientFunds_ReturnsTrue) {
    // Decrease budget with sufficient funds
    bool result = resourceManager->decreaseBudget(500);
    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager->getBudget(), 500);
}

// Test decreaseBudget with insufficient funds
TEST_F(ResourceManagerTest, DecreaseBudget_InsufficientFunds_ReturnsFalse) {
    // Attempt to decrease more budget than available
    bool result = resourceManager->decreaseBudget(2000);
    EXPECT_FALSE(result);
    EXPECT_EQ(resourceManager->getBudget(), 1000);  // Budget should remain unchanged
}

// Test increaseResourceLevels to ensure resources are correctly added
TEST_F(ResourceManagerTest, IncreaseResourceLevels_IncreasesResourcesCorrectly) {
    resourceManager->increaseResourceLevels(10, 10, 10, 10, 10);
    EXPECT_EQ(resourceManager->getWaterLevel(), 110);
    EXPECT_EQ(resourceManager->getEnergyLevel(), 110);
    EXPECT_EQ(resourceManager->getWoodLevel(), 110);
    EXPECT_EQ(resourceManager->getSteelLevel(), 110);
    EXPECT_EQ(resourceManager->getGeneralMaterialsLevel(), 110);
}

// Test increaseBudget to ensure funds are correctly added
TEST_F(ResourceManagerTest, IncreaseBudget_IncreasesBudgetCorrectly) {
    resourceManager->increaseBudget(200);
    EXPECT_EQ(resourceManager->getBudget(), 1200);
}