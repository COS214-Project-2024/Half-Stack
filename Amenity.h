#ifndef RESIDENTIALDECORATOR_H
#define RESIDENTIALDECORATOR_H

#include"Residential.h"

class Amenity : public Residential
{

protected:
	Residential* amenity;
	
public:
	Amenity(Residential* amen);

	void increaseSatisfaction();
	void consumeResources();
};

class Garden : public Amenity
{

public:
	Garden(Residential* amen);
	void consumeResources() override;
    void increaseSatisfaction() override;
};

class Internet : public Amenity
{

public:
	Internet(Residential* amen);
	void consumeResources() override;
    void increaseSatisfaction() override;
	
};

class Gym : public Amenity
{

public:
	Gym(Residential* amen);
	void consumeResources() override;
    void increaseSatisfaction() override;
};

class Pool : public Amenity
{

public:
	Pool(Residential* amen);
	void consumeResources() override;
    void increaseSatisfaction() override;
};

#endif
