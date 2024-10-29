#ifndef LAWDEPARTMENT_H
#define LAWDEPARTMENT_H
#include "Department.h"
#include "Building.h"

class LawDepartment : public Department
{
private:
	std::vector<std::string> laws;
	static LawDepartment* uniqueInstance;

protected:
	LawDepartment(){std::cout << "New Law department created" << std::endl;};

public:
	LawDepartment* instance();

	LawDepartment(const LawDepartment&) = delete;

	void addLaw(std::string l);

	void removeLaw(std::string l);

	void changeLaw(std::string previous, std::string current);

	~LawDepartment();
};

#endif
