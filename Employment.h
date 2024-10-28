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

};

class Employed : public Employment
{
    public:

        std::string getStatus();
};

class Unemployed : public Employment
{
    public:

        std::string getStatus();
};

#endif