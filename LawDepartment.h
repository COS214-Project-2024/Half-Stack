#ifndef LAWDEPARTMENT_H
#define LAWDEPARTMENT_H
#include "Department.h"
#include "Building.h"

class LawDepartment : public Department
{
private:
	std::vector<std::string> laws;

public:
	void addLaw(std::string l);

	void removeLaw(std::string l);

	LawDepartment(){std::cout << "New Law department created" << std::endl;};

	void changeLaw(std::string previous, std::string current);
};

#endif
