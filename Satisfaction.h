#ifndef SATISFACTION_H
#define SATISFACTION_H

#include <iostream>
#include <string>

class Satisfaction
{   
    protected:
        std::string status;

    public:

        std::string getStatus();
        virtual Satisfaction* raiseStatus() = 0;
        virtual Satisfaction* lowerStatus() = 0;

        virtual ~Satisfaction() {};
};

class Satisfied : public Satisfaction
{

public:
        Satisfied();
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

class Neutral : public Satisfaction
{

public:
        Neutral();
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

class Unsatisfied : public Satisfaction
{

public:
        Unsatisfied();
        Satisfaction* raiseStatus();
        Satisfaction* lowerStatus();
};

#endif
