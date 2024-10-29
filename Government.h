#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Department.h"
#include <vector>

class Government : public Department {

private:
	std::vector<Department*> departments;
	std::string name;
	static Government* uniqueInstance;

protected:
	Government(std::string name);

public:
	static Government* instance(std::string name);

	~Government();
};

#endif
