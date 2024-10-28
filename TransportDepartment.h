#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include "Transportation.h"
#include "Department.h"
#include "TransportCommand.h"

class TransportDepartment : public Department
{

private:
	std::vector<Transportation*> transports;
	TransportCommand* commands[2];

public:

	void addTransport(Transportation newTransport);

	void removeTransport(Transportation newTransport);

	TransportDepartment(){std::cout << "New Transport department created" << std::endl;};

	void openTransport();

	void closeTransport();
};

#endif
