#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <string>

#include "Building.h"
#include "Employment.h"
#include "Satisfaction.h"

class Building;

class Citizen
{
    private:
        std::string name;
        int age;
        Employment* employment;
        Satisfaction* satisfaction;
        Building* jobBuilding;
        Building* home;

    public:
        Citizen(std::string name, int age);
        ~Citizen();
        void payTax(std::string tax);
        void startWork();
        Employment* getEmployment();
        void setEmployment(Employment* e);
        Satisfaction* getSatisfaction();
        void setSatisfaction(Satisfaction* s);
        void getJob();
        int getAge();

         void receiveNotification(const std::string& message);
};

#endif
