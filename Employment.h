#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H

#include <iostream>
#include <string>

class Employment
{
    protected:
        Employment* status;

    public:
        virtual std::string getStatus() = 0;
        virtual Employment* toggleStatus() = 0;

    virtual ~Employment() {};

};

class Employed : public Employment
{
    public:

        std::string getStatus();
        Employment* toggleStatus();
};

class Unemployed : public Employment
{
    public:

        std::string getStatus();
        Employment* toggleStatus();
};

#endif
