#ifndef LANDMARK_H
#define LANDMARK_H

#include <vector>
#include <string>

#include "Building.h"

class Landmark : public Building
{

private:
	std::vector<Citizen*> employees;

public:

	Landmark(int num, std::string loc);

	void addCitizen(Citizen* c);

	void removeCitizen(Citizen* c);

	void consumeResources();
};

#endif