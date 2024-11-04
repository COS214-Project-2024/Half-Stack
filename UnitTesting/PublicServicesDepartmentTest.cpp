#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PublicServicesDepartment.h"

using ::testing::Exactly;

// Mock classes for tax commands
class MockCollectIncomeTax : public CollectIncomeTax {
public:
    MOCK_METHOD(void, execute, (), (override));
};

class MockCollectPropertyTax : public CollectPropertyTax {
public:
    MOCK_METHOD(void, execute, (), (override));
};

class MockCollectSalesTax : public CollectSalesTax {
public:
    MOCK_METHOD(void, execute, (), (override));
};

class PublicServicesDepartmentTest : public ::testing::Test {
protected:
    PublicServicesDepartment* department;

    void SetUp() override {
        // Reset singleton instance for each test
        department = PublicServicesDepartment::instance();

        // Replace real commands with mocks for testing
        department->commands[0] = new MockCollectIncomeTax();
        department->commands[1] = new MockCollectPropertyTax();
        department->commands[2] = new MockCollectSalesTax();
    }

    void TearDown() override {
        // Clean up any allocated mocks
        delete department->commands[0];
        delete department->commands[1];
        delete department->commands[2];
    }
};

// Test for singleton instance
TEST_F(PublicServicesDepartmentTest, SingletonInstance_ReturnsSameInstance) {
    PublicServicesDepartment* instance1 = PublicServicesDepartment::instance();
    PublicServicesDepartment* instance2 = PublicServicesDepartment::instance();
    EXPECT_EQ(instance1, instance2);
}

// Test for command initialization
TEST_F(PublicServicesDepartmentTest, CommandInitialization_CorrectCommandTypes) {
    EXPECT_NE(dynamic_cast<MockCollectIncomeTax*>(department->commands[0]), nullptr);
    EXPECT_NE(dynamic_cast<MockCollectPropertyTax*>(department->commands[1]), nullptr);
    EXPECT_NE(dynamic_cast<MockCollectSalesTax*>(department->commands[2]), nullptr);
}

// Test collectTax calls execute on each command
TEST_F(PublicServicesDepartmentTest, CollectTax_CallsExecuteOnEachCommand) {
    auto* mockIncomeTax = dynamic_cast<MockCollectIncomeTax*>(department->commands[0]);
    auto* mockPropertyTax = dynamic_cast<MockCollectPropertyTax*>(department->commands[1]);
    auto* mockSalesTax = dynamic_cast<MockCollectSalesTax*>(department->commands[2]);

    EXPECT_CALL(*mockIncomeTax, execute()).Times(Exactly(1));
    EXPECT_CALL(*mockPropertyTax, execute()).Times(Exactly(1));
    EXPECT_CALL(*mockSalesTax, execute()).Times(Exactly(1));

    department->collectTax("any_tax_type");
}