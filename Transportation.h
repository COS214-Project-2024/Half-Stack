#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <string>

class Transportation
{

private:
	bool isOpen;

public:
	virtual void open();
	virtual void close();

	virtual bool getStatus();

	Transportation();
};

class Airport : public Transportation
{

public:
	Airport();
};

class Road : public Transportation
{

public:
	Road();
};

class Railway : public Transportation
{

public:
	Railway();
};

class Pathway
{

private:
	bool path;

public:
	Pathway();

	void clear();
	void block();
	
	bool getPathStatus();
};

class Trail : public Transportation, private Pathway
{

public:
	Trail();

	void open();
	void close();

	bool getStatus();
};

#endif
