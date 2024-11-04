#ifndef UTILITIESDEPARTMENT_H
#define UTILITIESDEPARTMENT_H

#include <iostream>
#include "Building.h"
#include "Department.h"
#include "UtilityCommand.h"
#include "Plant.h"

class UtilityCommand;

/**
 * @class Utilities Department
 * @brief The utilities department manages the utility services.
 * (Implements the singleton design pattern.)
 */
class UtilitiesDepartment : public Department
{
	private:

		/**
		 * @brief Constructor for the UtilitiesDepartment class.
		 * (Initialises the necessary commands.)
		 */
		UtilitiesDepartment();
		
		static UtilitiesDepartment* uniqueInstance;
		
		UtilityCommand* commands[4];

		 std::vector<Plant*> plants;

	public:

		/**
		 * @brief Destructor for the UtilitiesDepartment class.
		 * (Deletes the array of commands.)
		 */
		~UtilitiesDepartment();

		/** 
		 * @brief Singleton instance of UtilitiesDepartment.
		 * @return Pointer to the instance of UtilitiesDepartment.
		 */
		static UtilitiesDepartment* instance();

		/** 
		 * @brief Responsible for supply water to the city.
		 */
		void supplyWater();

		/** 
		 * @brief Responsible for supply energy to the city.
		 */
		void supplyEnergy();

		/** 
		 * @brief Responsible for managing waste of the city.
		 */
		void manageWaste();

		/** 
		 * @brief Responsible for managing sewage of the city.
		 */
		void manageSewage();
		
		/** 
		 * @brief Executes all of the commands for the above utility services.
		 */
		void performRoutine();

		/**
		 * @brief Adds a plant to the vector of residential buildings.
		 * @param b Pointer to the plant building.
		 */
		void addBuilding(Plant* b);

		/**
		* @brief loop through plant vector and determine amount of water plants
		* @return amount of water plants
		*/
		int getTotalWaterPlants();
		/**
		* @brief loop through plant vector and determine amount of power plants
		* @return amount of power plants
		*/
		int getTotalPowerPlants();
};

#endif
