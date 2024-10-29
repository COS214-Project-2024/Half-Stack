#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

class Industrial : public Building
{

private:
	std::vector<Citizen*> employees;

public:

	Industrial(int num,  std::string loc);

	void addCitizen(Citizen* c);

	void removeCitizen(Citizen* c);

	void consumeResources();

	//produce resources function for plants and factories?
};

#endif