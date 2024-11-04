#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Citizen.h"
#include "OpenBusiness.h"
#include "CloseBusiness.h"
#include "SupplyWater.h"
#include "SupplyPower.h"
#include "ManageWaste.h"
#include "ManageSewage.h"

class EmploymentMockery {
public:
    std::string status;

    EmploymentMockery(const std::string& employmentStatus) : status(employmentStatus) {}

    std::string getStatus() { return status; }
};

class TaxMockery {
public:
    std::string message;

    virtual void pay() { message = "Tax paid."; }
};

class IncomeTaxMockery : public TaxMockery {
public:
    void pay() override { message = "paid income tax."; }
};

class SalesTaxMockery : public TaxMockery {
public:
    void pay() override { message = "paid sales tax."; }
};

class PropertyTaxMockery : public TaxMockery {
public:
    void pay() override { message = "paid property tax."; }
};

TEST_CASE("Citizen::payTax with valid conditions and tax types") {
    Citizen citizen;
    citizen.setAge(25);
    citizen.setEmployment(new EmploymentMockery("Employed"));

    SUBCASE("Income tax payment") {
        citizen.payTax("IncomeTax");
        CHECK(citizen.getTaxMessage() == "<name> paid income tax.");
    }

    SUBCASE("Sales tax payment") {
        citizen.payTax("SalesTax");
        CHECK(citizen.getTaxMessage() == "<name> paid sales tax.");
    }

    SUBCASE("Property tax payment") {
        citizen.payTax("PropertyTax");
        CHECK(citizen.getTaxMessage() == "<name> paid property tax.");
    }

    SUBCASE("Invalid tax type") {
        citizen.payTax("InvalidTax");
        CHECK(citizen.getTaxMessage() == "invalid input");
    }
}

TEST_CASE("Citizen::payTax ineligible cases") {
    Citizen citizen;

    SUBCASE("Citizen is underage") {
        citizen.setAge(16);
        citizen.setEmployment(new EmploymentMockery("Employed"));
        citizen.payTax("IncomeTax");
        CHECK(citizen.getTaxMessage().empty());
    }

    SUBCASE("Citizen is unemployed") {
        citizen.setAge(30);
        citizen.setEmployment(new EmploymentMockery("Unemployed"));
        citizen.payTax("SalesTax");
        CHECK(citizen.getTaxMessage().empty());
    }
}

TEST_CASE("OpenBusiness::getStatus") {
    OpenBusiness openBusiness;
    openBusiness.open = true;
    CHECK(openBusiness.getStatus() == true);

    openBusiness.open = false;
    CHECK(openBusiness.getStatus() == false);
}

TEST_CASE("CloseBusiness::getStatus") {
    CloseBusiness closeBusiness;
    closeBusiness.close = true;
    CHECK(closeBusiness.getStatus() == true);

    closeBusiness.close = false;
    CHECK(closeBusiness.getStatus() == false);
}

TEST_CASE("SupplyWater::getStatus") {
    SupplyWater waterSupply;

    waterSupply.water = 10;
    CHECK(waterSupply.getStatus() == true);

    waterSupply.water = 0;
    CHECK(waterSupply.getStatus() == false);
}

TEST_CASE("SupplyPower::getStatus") {
    SupplyPower powerSupply;

    powerSupply.energy = 20;
    CHECK(powerSupply.getStatus() == true);

    powerSupply.energy = 0;
    CHECK(powerSupply.getStatus() == false);
}

TEST_CASE("ManageWaste::getStatus") {
    ManageWaste wasteManagement;

    wasteManagement.open = true;
    CHECK(wasteManagement.getStatus() == true);

    wasteManagement.open = false;
    CHECK(wasteManagement.getStatus() == false);
}

TEST_CASE("ManageSewage::getStatus") {
    ManageSewage sewageManagement;

    sewageManagement.open = true;
    CHECK(sewageManagement.getStatus() == true);

    sewageManagement.open = false;
    CHECK(sewageManagement.getStatus() == false);
}
