#ifndef RESIDENTIALDEPARTMENT_H
#define RESIDENTIALDEPARTMENT_H

#include "Building.h"
#include "Department.h"
#include "Citizen.h"

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

		std::vector<Residential*> residents;

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
		void addBuilding(Residential* b);

		/**
		 * @brief Removes a building from the vector of residential buildings.
		 * @param b Pointer to the building.
		 */
		void removeBuilding(Residential* b);

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

		  /**
         * @brief Attaches a Citizen as an observer to receive notifications.
         * @param c Pointer to the Citizen to attach.
         */
        void attachCitizen(Citizen* c); 

        /**
         * @brief Detaches a Citizen from receiving notifications.
         * @param c Pointer to the Citizen to detach.
         */
        void detachCitizen(Citizen* c);

        /**
         * @brief Sets the load-shedding status and notifies citizens if changed.
         * @param status Boolean indicating whether load-shedding is active.
         * @param startTime Start time of load-shedding, if active.
         * @param endTime End time of load-shedding, if active.
         */
        void setLoadShedding(bool status, const std::string& startTime, const std::string& endTime);

        /**
         * @brief Notifies all observing citizens with a specified message.
         * @param message Notification message to send to all citizens.
         */
        void notifyCitizens(const std::string& message);

		void notifyNewHousing();

		void houseNewCitizens();

		int emptyRooms();

		void consumeDailyResources();

		~ResidentialDepartment();
};

#endif
