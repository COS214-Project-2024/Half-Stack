#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "vcpkg/buildtrees/doctest/src/v2.4.11-2c5d2f15c5.clean.tmp/doctest-2.4.11/doctest/doctest.h"
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

TEST_CASE("Existing Law Change")
{
    LawDepartment* dep = LawDepartment::instance();

    std::string old = "Law of the old";
    std::string newL = "Law of the new";

    dep->addLaw(old);

    dep->changeLaw(old, newL);

    CHECK(dep->getAllLaws().size() == 1);
    CHECK(dep->getAllLaws().at(0) == newL);
}

TEST_CASE("Non-existing Law Change")
{
    LawDepartment* lD = LawDepartment::instance();

    std::string non = "Law of the old";
    std::string newL = "Law of the new";

    CHECK_NOTHROW(lD->changeLaw(non, newL));
}