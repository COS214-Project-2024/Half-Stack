#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Government.h"

TEST_CASE("Only one singleton")
{
    Government* first = Government::instance("");
    Government* second = Government::instance("");

    CHECK(first == second);
}