#ifndef TRANSPORTDEPARTMENT_H
#define TRANSPORTDEPARTMENT_H

#include "Transportation.h"
#include "Department.h"
#include "TransportCommand.h"

class TransportDepartment : public Department
{

private:
	std::vector<std::pair<Transportation*, std::pair<TransportCommand*, TransportCommand*>>> transports;
	static TransportDepartment* uniqueInstance;

protected:
	TransportDepartment(){};

public:
	TransportDepartment* instance();

	void addTransport(Transportation* newTransport);

	void removeTransport(Transportation* newTransport);

	void openTransport();

	void closeTransport();

	~TransportDepartment();
};

#endif
