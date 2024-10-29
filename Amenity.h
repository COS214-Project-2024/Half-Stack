#ifndef RESIDENTIALDECORATOR_H
#define RESIDENTIALDECORATOR_H

#include"Residential.h"

class Amenity : public Residential
{

public:
	Residential* amenity;

	Amenity();

	void increaseSatisfaction();
};

class Garden : public Amenity
{

public:
	Garden();
};

class Internet : public Amenity
{

public:
	Internet();
};

class Gym : public Amenity
{

public:
	Gym();
};

class Pool : public Amenity
{

public:
	Pool();
};

#endif
