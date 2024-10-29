#ifndef RESIDENTIALDEPARTMENT_H
#define RESIDENTIALDEPARTMENT_H

#include "Building.h"
#include "Department.h"

class ResidentialDepartment : public Department
{
	private:

		ResidentialDepartment();
		static ResidentialDepartment* uniqueInstance;

		std::vector<Building*> residents;

		std::vector<Citizen*> Observingcitizens; //obsever list
    		bool isLoadShedding;

	public:

		static ResidentialDepartment* instance();

		void addBuilding(Building* b);
		void removeBuilding(Building* b);

		int getTotalBuildings();
		int getTotalCapacity();

		void attachCitizen(Citizen* c); 
   		void detachCitizen(Citizen* c);

		void setLoadShedding(bool status, const std::string& startTime, const std::string& endTime);
    		void notifyCitizens(const std::string& message);
};

#endif
