#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "Department.h"
#include "BuildingMock.h"

using ::testing::AtLeast;

class DepartmentTest : public ::testing::Test {
protected:
    Department department;
    std::streambuf* originalCoutBuffer;
    std::ostringstream testOutput;

    void SetUp() override {
        // Redirect std::cout to capture output for testing
        originalCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(testOutput.rdbuf());
    }

    void TearDown() override {
        // Restore the original cout buffer
        std::cout.rdbuf(originalCoutBuffer);
    }
};

// Test update with buildings in the department
TEST_F(DepartmentTest, Update_WithBuildings_CallsConsumeResourcesAndPrintsUpdateMessage) {
    // Create mock buildings and add them to the department
    MockBuilding mockBuilding1(10, "Building 1");
    MockBuilding mockBuilding2(20, "Building 2");
    department.addBuilding(&mockBuilding1);
    department.addBuilding(&mockBuilding2);

    // Set expectations for consumeResources to be called on each building
    EXPECT_CALL(mockBuilding1, consumeResources()).Times(1);
    EXPECT_CALL(mockBuilding2, consumeResources()).Times(1);

    // Call update and check output
    department.update();
    EXPECT_EQ(testOutput.str(), "Department is updating its buildings.\n");
}

// Test update with no buildings
TEST_F(DepartmentTest, Update_NoBuildings_OnlyPrintsUpdateMessage) {
    // Call update when no buildings are added
    department.update();
    EXPECT_EQ(testOutput.str(), "Department is updating its buildings.\n");
}