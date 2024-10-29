#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Department.h"
#include <vector>

class Government : public Department {

private:
	std::vector<Department*> departmentList;
	std::string name;
	static Government* uniqueInstance;

protected:
	Government(std::string name);

	static Government* instance(std::string);

	~Government();

	Government(Government& g);
};

#endif
