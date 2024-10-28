#ifndef SATISFACTION_H
#define SATISFACTION_H

#include <iostream>
#include <string>

class Satisfaction
{   
    private:
        std::string status;

    public:

        std::string getStatus();
        virtual Satisfaction* raiseStatus() = 0;
        virtual Satisfaction* lowerStatus() = 0;
};

class Satisfied : public Satisfaction
{

public:
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

class Neutral : public Satisfaction
{

public:
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

class Unsatisfied : public Satisfaction
{

public:
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

#endif