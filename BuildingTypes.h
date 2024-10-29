#ifndef BUILDINGTYPES_H
#define BUILDINGTYPES_H

#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"

class House : public Residential
{

public:
	House(int num,  std::string loc);

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

class Apartment : public Residential
{

public:
	Apartment(int num, std::string loc);

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

class TownHouse : public Residential
{

public:
	TownHouse(int num, std::string loc);

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

class Shop : public Commercial
{

public:
	Shop(int num,  std::string loc);

	Building* build();
};

class Office : public Commercial
{

public:
	Office(int num, std::string loc);

	Building* build();
};

class Mall : public Commercial
{

public:
	Mall(int num,  std::string loc );

	Building* build();
};

class Factory : public Industrial
{

public:
	Factory(int num, std::string loc);

	Building* build();
};

class Warehouse : public Industrial
{

public:
	Warehouse(int num, std::string loc);

	Building* build();	
};

class Park : public Landmark
{

public:
	Park(int num, std::string loc);

	Building* build();
};

class Monument : public Landmark
{

public:
	Monument(int num, std::string loc);

	Building* build();
};

class CulturalCentre : public Landmark
{

public:
	CulturalCentre(int num, std::string loc);

	Building* build();
};

#endif