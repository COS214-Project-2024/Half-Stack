#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <vector>

#include "Building.h"
#include "Citizen.h"

class Residential : public Building
{

protected:
	std::vector<Citizen*> residents;

public:		

	Residential(int num,  std::string loc);

	virtual ~Residential();

	void addCitizen(Citizen* c);

	void removeCitizen(Citizen* c);

	void consumeResources();

	virtual void increaseSatisfaction() = 0 ;

	std::vector<Citizen*> getResidents();
};

class Estate : public Residential
{

private:
	std::vector<Residential*> buildings;

public:

	Estate(int num,  std::string loc);
	virtual ~Estate();


	void addBuilding(Residential* b);

	void removeBuilding(Residential* b);

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

#endif
