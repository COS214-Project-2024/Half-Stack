#include <iostream>
#include "Government.h"
#include "Department.h"
#include "ResidentialDepartment.h"
#include "TransportDepartment.h"
#include "UtilitiesDepartment.h"
#include "PublicServicesDepartment.h"
#include "LawDepartment.h"
#include "CityGrowthDepartment.h"
#include "ResourceManager.h"

char start;
std::string cityName;

void printCityOutline()
{
    std::cout << "-------------------------------------------------------" <<std::endl;
    std::cout << "                        HALF STACK                     " <<std::endl;
    std::cout << "                                                       " <<std::endl;
    std::cout << "                              |                        " <<std::endl;
    std::cout << "                            _| |_                      " <<std::endl;
    std::cout << "                    ______ |     |   ____              " <<std::endl;
    std::cout << "              _____|__    || === |  | == |__           " <<std::endl;
    std::cout << "             | ====== | = || === |__| = === |          " <<std::endl;
    std::cout << "            _| ===  = |== || === |  | ===== |          " <<std::endl;
    std::cout << "          _| | ====== |=  || === |  | ===== |          " <<std::endl;
    std::cout << "    _____| = | == === |== || === |  |       |          " <<std::endl;
    std::cout << "   | === |   | ====== |== || === |  | == == |____      " <<std::endl;
    std::cout << "   | === |   | = ==== |___|| === |  | ===== |=== |     " <<std::endl;
    std::cout << "   | === |   | ====== | == | === |  | = === | == |     " <<std::endl;
    std::cout << "   |     |   | =    = |    | === |  | =     |    |     " <<std::endl;
}

void WelcomePlayer()
{
    printCityOutline();
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "       <<< WELCOME TO HALFSTACK CITY BUILDER >>>      " <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "Start game? (Y/N) ";
    std::cin >> start;
    if (start!='Y')
    {
        return;
    }
    std::cout << "Enter a name for your city: " ;
    std::cin >> cityName;
}

int main()
{
    WelcomePlayer();
    if (start!='Y') {return 0;}

    Government* gov = Government::instance(cityName);
    ResidentialDepartment* residentialDep = gov->getResidentialDepartment();
    TransportDepartment* transportDep = gov->getTransportDepartment();
    UtilitiesDepartment* utilityDep = gov->getUtilitiesDepartment();
    PublicServicesDepartment* publicDep = gov->getPublicServicesDepartment();
    LawDepartment* lawDep = gov->getLawDepartment();
    CityGrowthDepartment* cityGrowthDep = gov->getCityGrowthDepartment();
    ResourceManager* rm = gov->getResourceManager();

    std::vector<Citizen*> newCitizens;
    Citizen* Keanu = new Citizen("Keanu",21);
    Citizen* Devan = new Citizen("Devan",20);
    Citizen* Austin = new Citizen("Austin",19);
    Citizen* Sashen = new Citizen("Sashen",20);
    Citizen* Stone = new Citizen("Stone",20);
    Citizen* Jamean = new Citizen("Jamean",20);
    Citizen* Ayush = new Citizen("Ayush",21);
    newCitizens.push_back(Keanu);
    newCitizens.push_back(Devan);
    newCitizens.push_back(Austin);
    newCitizens.push_back(Sashen);
    newCitizens.push_back(Stone);
    newCitizens.push_back(Jamean);
    newCitizens.push_back(Ayush);

    cityGrowthDep->increasePopulation(newCitizens);
    int homeless= cityGrowthDep->getPopulation()-residentialDep->getTotalCapacity() ;
    std::cout << "There is currently " << gov->getTotalCitizens() << " in the city." <<std::endl;
    std::cout << "There are " << residentialDep->getTotalCapacity() << " rooms available, and "<< homeless << " citizens without homes." <<std::endl;
    char resType = 'H';
    cityGrowthDep->increaseHousing(resType);
    std::cout << "There are " << residentialDep->getTotalCapacity() << " rooms available, and "<< homeless << " citizens without homes." <<std::endl;

    return 0;
}