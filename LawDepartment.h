#ifndef LAWDEPARTMENT_H
#define LAWDEPARTMENT_H

#include <iostream>
#include "Department.h"
#include "Building.h"

class LawDepartment : public Department
{
private:
	std::vector<std::string> laws;
	static LawDepartment* uniqueInstance;

protected:
	LawDepartment(){/*std::cout << "New Law department created" << std::endl;*/};

public:
	static LawDepartment* instance();

	void addLaw(std::string l);

	void removeLaw(std::string l);

	~LawDepartment();

	//std::vector<std::string> getAllLaws();
};

#endif
