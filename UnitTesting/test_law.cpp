#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LawDepartment.h"

TEST_CASE("Only one singleton")
{
    LawDepartment* first = LawDepartment::instance();
    LawDepartment* second = LawDepartment::instance();

    CHECK(first == second);
}

TEST_CASE("Law add")
{
    LawDepartment* lD = LawDepartment::instance();

    std::string lawToAdd = "Law A";
    lD->addLaw(lawToAdd);

    lD->addLaw(lawToAdd);

    CHECK(lD->getAllLaws().size() == 1);
    CHECK(lD->getAllLaws().at(0) == "Law A");
}

TEST_CASE("Law remove")
{
    LawDepartment* lD = LawDepartment::instance();

    lD->removeLaw("Law A");

    CHECK(lD->getAllLaws().empty());
}