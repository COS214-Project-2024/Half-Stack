#ifndef RESIDENTIALDEPARTMENT_H
#define RESIDENTIALDEPARTMENT_H

#include "Building.h"
#include "Department.h"

/**
 * @class Residential Department
 * @brief The residential department manages the the residential buildings and their respective citizens.
 * (Implements the singleton design pattern.)
 */
class ResidentialDepartment : public Department
{
	private:

		/**
		 * @brief Constructor for the ResidentialDepartment class.
		 */
		ResidentialDepartment();

		static ResidentialDepartment* uniqueInstance;

		std::vector<Building*> residents;

		std::vector<Citizen*> Observingcitizens; 

    	bool isLoadShedding;

	public:

		/** 
		 * @brief Singleton instance of ResidentialDepartment.
		 * @return Pointer to the instance of ResidentialDepartment.
		 */
		static ResidentialDepartment* instance();

		/**
		 * @brief Adds a building to the vector of residential buildings.
		 * @param b Pointer to the building.
		 */
		void addBuilding(Building* b);

		/**
		 * @brief Removes a building from the vector of residential buildings.
		 * @param b Pointer to the building.
		 */
		void removeBuilding(Building* b);

		/**
		 * @brief Calculates the number of residential buildings.
		 * @return Number of residential buildings.
		 */
		int getTotalBuildings();

		/**
		 * @brief Calculates the number of possible citizens in the residential buildings.
		 * @return Number of possible citizens.
		 */
		int getTotalCapacity();

		void attachCitizen(Citizen* c); 

   		void detachCitizen(Citizen* c);

		void setLoadShedding(bool status, const std::string& startTime, const std::string& endTime);

    	void notifyCitizens(const std::string& message);
};

#endif
