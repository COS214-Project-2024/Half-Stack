#include <gmock/gmock.h>
#include "Building.h"

class MockBuilding : public Building {
public:
    MockBuilding(int num, std::string l) : Building(num, l) {}
    MOCK_METHOD(void, consumeResources, (), (override));
};