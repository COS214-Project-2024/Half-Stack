#ifndef PUBLICSERVICESDEPARTMENT_H
#define PUBLICSERVICESDEPARTMENT_H

#include "Department.h"
#include "Building.h"
#include "TaxCommand.h"

class PublicServicesDepartment : public Department
{
private:
	static PublicServicesDepartment* Singleton;

	TaxCommand* commands[3];

public:

	PublicServicesDepartment();

	void collectTax(std::string tax);

	static PublicServicesDepartment* instance();

	~PublicServicesDepartment();
};

#endif