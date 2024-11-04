#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "UtilitiesDepartment.h"
#include "Plant.h"
#include "Citizen.h"
#include "ResourceManager.h"
#include "Government.h"

TEST_CASE("UtilitiesDepartment Singleton") 
{
    UtilitiesDepartment* instance1 = UtilitiesDepartment::instance();
    UtilitiesDepartment* instance2 = UtilitiesDepartment::instance();
    CHECK(instance1 == instance2);
}