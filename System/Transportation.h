#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <string>

/**
 * @class Transportation
 * @brief These are the various transport modes available.
 * (Implements the adapter design pattern.)
 */
class Transportation
{

private:
	bool isOpen;
	std::string type;

public:

	/**
	 * @brief Opens the transport to be used by citizens.
	 * (Target of Adapter)
	 */
	virtual void open();

	/**
	 * @brief Closes the transport from being used by citizens.
	 * (Target of Adapter)
	 */
	virtual void close();

	/**
	 * @brief Whether the transport is open or closed.
	 * (Target of Adapter)
	 * @return Status of the respective transportation mode.
	 */
	virtual bool getStatus();

	Transportation(std::string t);

	virtual ~Transportation(){};

	std::string getType();
};

class Airport : public Transportation
{
	//private:
		//static int counter;
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

	/**
	 * @brief Clears the pathway to be accessed.
	 * (Adaptee of Adapter)
	 */
	void clear();

	/**
	 * @brief Blocks the pathway from being accessed.
	 * (Adaptee of Adapter)
	 */
	void block();
	
	/**
	 * @brief Whether the pathway is cleared or blocked.
	 * (Adaptee of Adapter)
	 * @return Status of the pathway.
	 */
	bool getPathStatus();
};

class Trail : public Transportation, private Pathway
{

public:
	Trail();

	/**
	 * @brief Opens the trail to be used by citizens.
	 * (Adapter of Adapter)
	 */
	virtual void open();

	/**
	 * @brief Closes the trail from being used by citizens.
	 * (Adapter of Adapter)
	 */
	virtual void close();

	/**
	 * @brief Whether the trail is open or closed.
	 * (Adapter of Adapter)
	 * @return Status of the trail.
	 */
	virtual bool getStatus();
};

#endif
