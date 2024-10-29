#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <string>
#include <vector>

#include "Building.h"

class Commercial : public Building
{

private:
	std::vector<Citizen*> employees;

public:

	Commercial(int num, std::string loc);

	void addCitizen(Citizen* c);

	void removeCitizen(Citizen* c);

	void consumeResources();
};

#endif