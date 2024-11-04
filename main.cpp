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
#include "BuildingTypes.h"
#include "PlantCreator.h"
#include "Amenity.h"
#include "Residential.h"
#include <cmath>

Government* gov;
ResidentialDepartment* residentialDep;
CityGrowthDepartment* cityGrowthDep;
PublicServicesDepartment* publicDep;
ResourceManager* rm;
LawDepartment* lawDep;
UtilitiesDepartment* utilityDep ;
TransportDepartment* transportDep ;

char start;
std::string cityName;

void printCityOutline()
{
    std::cout << "-----------------------------------------------------------------------------------" <<std::endl;
    std::cout << "                                       HALF STACK                                  " <<std::endl;
    std::cout << "                                                                                   " <<std::endl;
    std::cout << "                                             |                                     " <<std::endl;
    std::cout << "                                           _| |_                                   " <<std::endl;
    std::cout << "                                   ______ |     |   ____                           " <<std::endl;
    std::cout << "                             _____|__    || === |  | == |__                        " <<std::endl;
    std::cout << "                            | ====== | = || === |__| = === |                       " <<std::endl;
    std::cout << "                           _| ===  = |== || === |  | ===== |                       " <<std::endl;
    std::cout << "                         _| | ====== |=  || === |  | ===== |                       " <<std::endl;
    std::cout << "                   _____| = | == === |== || === |  |       |                       " <<std::endl;
    std::cout << "                  | === |   | ====== |== || === |  | == == |____                   " <<std::endl;
    std::cout << "                  | === |   | = ==== |___|| === |  | ===== |=== |                  " <<std::endl;
    std::cout << "                  | === |   | ====== | == | === |  | = === | == |                  " <<std::endl;
    std::cout << "                  |     |   | =    = |    | === |  | =     |    |                  " <<std::endl;
}

void WelcomePlayer()
{
    printCityOutline();
    std::cout << "-----------------------------------------------------------------------------------" <<std::endl;
    std::cout << "                     <<< WELCOME TO HALFSTACK CITY BUILDER >>>                     " <<std::endl;
    std::cout << "-----------------------------------------------------------------------------------" <<std::endl;
    std::cout << "Start game? (Y/N) ";
    std::cin >> start;
    if (start!='Y')
    {
        return;
    }
    std::cout << "Enter a name for your city: " ;
    //std::getline(std::cin, cityName);
    std::cin >> cityName;
    //std::cin.clear();
}

void menu()
{
    std::cout << "              __________________________ " <<std::endl;
    std::cout << "             |          MENU            |" <<std::endl;
    std::cout << "             | a. Start day             |" <<std::endl;
    std::cout << "             | b. Increase transport    |" <<std::endl;
    std::cout << "             | c. Add a citizen         |" <<std::endl;
    std::cout << "             | d. Increase population   |" <<std::endl;
    std::cout << "             | e. Build building        |" <<std::endl;
    std::cout << "             | f. House all homeless    |" <<std::endl;
    std::cout << "             | g. Collect tax           |" <<std::endl;
    std::cout << "             | h. Increase/Decrease tax |" <<std::endl;
    std::cout << "             | i. Increase jobs         |" <<std::endl;
    std::cout << "             | j. Handle Law            |" <<std::endl;
    std::cout << "             | k. Buy resources         |" <<std::endl;
    std::cout << "             | l. Build plant           |" <<std::endl;
    std::cout << "             | m. City stats            |" <<std::endl;
    std::cout << "             | n. View menu             |" <<std::endl;
    std::cout << "             |                          |" <<std::endl;
    std::cout << "             | z. END GAME              |" <<std::endl;
    std::cout << "             |__________________________|" <<std::endl;


}

void addCitizen()
{
    int valid = ceil(cityGrowthDep->getPopulation()/20.0);
	if (utilityDep->getTotalWaterPlants()<valid)
	{
		std::cout << "Cannot increase population. Build more water plants to accomodate a higher population." <<std::endl;
		return;
	}
	if (utilityDep->getTotalPowerPlants()<valid)
	{
		std::cout << "Cannot increase population. Build more power plants to accomodate a higher population." <<std::endl;
		return;
	}
    int age;
    std::cout << "Enter age of citizen: ";
    std::cin >> age;
    gov->addCitizen(new Citizen(age));
}

void increasePopulation()
{
    cityGrowthDep->increasePopulation();
    std::cout << "There are " << residentialDep->emptyRooms() << " rooms available, and "<< gov->getHomeless() << " citizens without homes." <<std::endl;
}

void addResidential()
{
    char type;
     Residential* b=NULL;
    std::cout << "Residential type (Apartment/House/Townhouse): [ type A/H/T]:  ";
    std::cin >> type;
    if (type=='A') 
    {
            Residential* b = new Apartment(5,"apartment");
            residentialDep->addBuilding(b);
    }
    if (type=='H')
    {
            Residential* b = new House(4,"house");
            residentialDep->addBuilding(b);
    }
    if (type=='T')
    {
            Residential* b = new TownHouse(10,"townHouse");
            residentialDep->addBuilding(b);
    }
    
    char addAmenity;
    std::string amenity;
    std::cout << "Add amenity (Y/N): ";
    std::cin >> addAmenity;
    if (addAmenity=='N')
    {
        return;
    }
        std::cout << " Pool,Gym,Internet or Garden? ";
        std::cin >> amenity;
        if (amenity=="Pool")
        {
            Amenity* pool=new Pool(b);
            delete pool;
        }
        if (amenity=="Gym")
        {
            Amenity* gym=new Gym(b);
            delete gym;
        }
        if (amenity=="Internet")
        {
            Amenity* i=new Internet(b);
            delete i;
        }
        if (amenity=="Garden")
        {
            Amenity* g=new Garden(b);
            delete g;
        }

    //cityGrowthDep->increaseHousing(type);
    //std::cout << "There are " << residentialDep->emptyRooms() << " rooms available, and "<< gov->getHomeless() << " citizens without homes." <<std::endl;
}
void addCommercial()
{
    char type;
    std::cout << "Commercial type (Shop/Office/Mall): ";
    std::cin >> type;
    switch (type)
    {
        case 'S':
            publicDep->addBuilding(new Shop(5,"shop"));
            break;
        case 'O':
            publicDep->addBuilding(new Office(20,"office"));
            break;
        case 'M':
            publicDep->addBuilding(new Mall(20,"mall"));
            break;
        default: break;
    }
}
void addIndustrial()
{
    char type;
    std::cout << "Industrial type (Factory/Warehouse): ";
    std::cin >> type;
    switch (type)
    {
        case 'F':
            publicDep->addBuilding(new Shop(5,"Factory"));
            break;
        case 'W':
            publicDep->addBuilding(new Office(5,"Warehouse"));
            break;
        default: break;
    }
}
void addLandmark()
{
    char type;
    std::cout << "Landmark type (Park/Monument/CulturalCentre): ";
    std::cin >> type;
    switch (type)
    {
        case 'P':
            publicDep->addBuilding(new Park(0,"Park"));
            break;
        case 'M':
            publicDep->addBuilding(new Monument(0,"monument"));
            break;
        case 'C':
            publicDep->addBuilding(new CulturalCentre(5,"culturalcentre"));
            break;
        default: break;
    }
}
void addBuilding()
{
    char type;
    std::cout << "              ________________________" <<std::endl;
    std::cout << "             | SELECT A BUILDING TYPE |" <<std::endl;
    std::cout << "             | c. Commercial          |" <<std::endl;
    std::cout << "             | i. Industrial          |" <<std::endl;
    std::cout << "             | l. Landmark            |" <<std::endl;
    std::cout << "             | r. Residential         |" <<std::endl;
    std::cout << "             |________________________|" <<std::endl;
    std::cout << "Select a type: " <<std::endl;
    std::cin >> type;
    switch (type)
    {
        case 'c':
            addCommercial();
            break;
        case 'i':
            addIndustrial();
            break;
        case 'l':
            addLandmark();
            break;
        case 'r':
            addResidential();
            break;
        default: break;
    }
    
}

void houseHomeless()
{
    char type;
    std::cout << "Residential type -Apartment,House,Townhouse (A/H/T): ";
    std::cin >> type;
    cityGrowthDep->increaseHousing(type);
    std::cout << "There are " << residentialDep->emptyRooms() << " rooms available, and "<< gov->getHomeless() << " citizens without homes." <<std::endl;
}
void collectTax()
{
    std::string taxType;
    std::cout << "Type of tax (Income/Sales/Property) :";
    std::cin >> taxType;
    publicDep->collectTax(taxType);
    std::cout << "City budget increased: " << rm->getBudget() <<std::endl;
}

void increaseTax()
{
    char choice;
    std::cout << "a. Increase"<<std::endl;
    std::cout << "b. Decrease" <<std::endl;
    std::cin >> choice;
    if (choice=='a')
    {
        publicDep->increaseTax();
    }
    if (choice=='b')
    {
        publicDep->decreaseTax();
    }
}

void increaseJobs()
{
    cityGrowthDep->increaseJobs();
}

void handleLaw()
{
    std::string law;
    char type;
    std::cout << "Add or Remove law? (A/R): ";
    std::cin >> type;
    if (type=='A')
    {
            std::cout << "Law: ";
            std::cin >> law;
            lawDep->addLaw(law);
    }
    if (type=='R')
    {
        std::cout << "Law: ";
        std::cin >> law;
        lawDep->removeLaw(law);
    }
}

void buyResources()
{
    int wood;int mats;
    std::cout << "How much wood and steel each: ";
    std::cin >> wood;
    std::cout << "How much materials: ";
    std::cin >> mats;
    if (rm->decreaseBudget(wood+wood+mats)==true)
        rm->increaseResourceLevels(100,100,wood,wood,mats);
}

void buildPlant()
{
    WaterPlantCreator waterPlant;
    PowerPlantCreator powerPlant;
    char type;
    std::cout << "Water or power plant? (W/P): ";
    std::cin >> type;
    if (type=='W')
    {
        utilityDep->addBuilding(waterPlant.createPlant(1,"waterplant"));
    }
    if (type=='P')
    {
        utilityDep->addBuilding(powerPlant.createPlant(1,"powerplant"));
    }
    std::cout << "City Budget: " << rm->getBudget() << std::endl;
    std::cout << "Water: " << rm->getWaterLevel()
              << ", Energy: " << rm->getEnergyLevel() 
              << ", Wood: " << rm->getWood()
              << ", Steel: " << rm->getSteel()
              << ", General Materials: " <<  rm->getGeneralMaterials() << std::endl;
}

void startDay()
{
    utilityDep->performRoutine();
    residentialDep->consumeDailyResources();
    publicDep->consumeDailyResources();
    transportDep->openTransport();
    if (rm->getEnergyLevel() < 100)
    {
        residentialDep->setLoadShedding(true,"3:00","5:00");
        residentialDep->setLoadShedding(false,"3:00","5:00");
    }
    double moneyMade = gov->getTotalNeutral() + (gov->getTotalSatisfied()*2);
    rm->increaseBudget(moneyMade);
     transportDep->closeTransport();
    std::cout << "City budget at end of day: " << rm->getBudget() <<std::endl;
     std::cout << "Water: " << rm->getWaterLevel()
              << ", Energy: " << rm->getEnergyLevel() 
              << ", Wood: " << rm->getWood()
              << ", Steel: " << rm->getSteel()
              << ", General Materials: " <<  rm->getGeneralMaterials() << std::endl;
}

void incTransport()
{
    cityGrowthDep->increaseTransport();
}

void getStats()
{
    gov->getCityStats();
}

int main()
{
    char userChoice;
    WelcomePlayer();
    if (start!='Y') {return 0;}

    gov = Government::instance(cityName);
    residentialDep = gov->getResidentialDepartment();
    transportDep = gov->getTransportDepartment();
    utilityDep = gov->getUtilitiesDepartment();
    publicDep = gov->getPublicServicesDepartment();
    lawDep = gov->getLawDepartment();
    cityGrowthDep = gov->getCityGrowthDepartment();
    rm = gov->getResourceManager();

    residentialDep->addBuilding(new House(8,"house"));

    std::vector<Citizen*> newCitizens;
    Citizen* Keanu = new Citizen(21);
    Citizen* Devan = new Citizen(20);
    Citizen* Austin = new Citizen(19);
    Citizen* Sashen = new Citizen(20);
    Citizen* Stone = new Citizen(20);
    Citizen* Jamean = new Citizen(20);
    Citizen* Ayush = new Citizen(21);
    newCitizens.push_back(Keanu);
    newCitizens.push_back(Devan);
    newCitizens.push_back(Austin);
    newCitizens.push_back(Sashen);
    newCitizens.push_back(Stone);
    newCitizens.push_back(Jamean);
    newCitizens.push_back(Ayush);
    cityGrowthDep->increasePopulation(newCitizens);

    menu();

    while (userChoice!='z')
    {
        std::cout << "Select an option: ";
        std::cin >> userChoice;

        switch (userChoice)
        {
            case 'a':
                startDay();
                break;
            case 'b':
                incTransport();
                break;
            case 'c':
                addCitizen();
                break;
            case 'd':
                increasePopulation();
                break;
            case 'e':
                addBuilding();
                break;
            case 'f':
                houseHomeless();
                break;
            case 'g':
                collectTax();
                break;
            case 'h':
                increaseTax();
                break;
            case 'i':
                increaseJobs();
                break;
            case 'j':
                handleLaw();
                break;
            case 'k':
                buyResources();
                break;
             case 'l':
                buildPlant();
                break;
            case 'm':
                getStats();
                break;
            case 'n':
                menu();
                break;

            default: break;
        }
       
    }

    return 0;
}
