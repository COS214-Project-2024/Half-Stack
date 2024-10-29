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
	TransportDepartment();
	~TransportDepartment(){};

public:
	static TransportDepartment& instance();

	TransportDepartment(const TransportDepartment&) = delete;

	void addTransport(Transportation newTransport);

	void removeTransport(Transportation newTransport);

	void openTransport();

	void closeTransport();
};

#endif
