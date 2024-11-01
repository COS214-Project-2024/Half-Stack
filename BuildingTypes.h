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
	virtual ~House();
	void increaseSatisfaction();
	void consumeResources();
};

class Apartment : public Residential
{

public:
	Apartment(int num, std::string loc);
	virtual ~Apartment();

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

class TownHouse : public Residential
{

public:
	TownHouse(int num, std::string loc);
	virtual ~TownHouse();

	Building* build();
	void increaseSatisfaction();
	void consumeResources();
};

class Shop : public Commercial
{

public:
	Shop(int num,  std::string loc);
	virtual ~Shop();

	Building* build();
};

class Office : public Commercial
{

public:
	Office(int num, std::string loc);
	virtual ~Office();

	Building* build();
};

class Mall : public Commercial
{

public:
	Mall(int num,  std::string loc );
	virtual ~Mall();

	Building* build();
};

class Factory : public Industrial
{

public:
	Factory(int num, std::string loc);
	virtual ~Factory();

	Building* build();
};

class Warehouse : public Industrial
{

public:
	Warehouse(int num, std::string loc);
	virtual ~Warehouse();

	Building* build();	
};

class Park : public Landmark
{

public:
	Park(int num, std::string loc);
	virtual ~Park();

	Building* build();
};

class Monument : public Landmark
{

public:
	Monument(int num, std::string loc);
	virtual ~Monument();

	Building* build();
};

class CulturalCentre : public Landmark
{


public:
	CulturalCentre(int num, std::string loc);
	virtual ~CulturalCentre();

	Building* build();
};

#endif
