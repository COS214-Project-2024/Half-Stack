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
		bool addBuilding(Residential* b);

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

		/**
 		 * @brief goes through the government's citizens vector and the buildings vector to find citizens without homes
		 * and assigns them a home if the building is not at max capacity  if a new building was added
 		 */
		void notifyNewHousing();

		/**
		 * @brief goes through the government's citizens vector and the buildings vector to find citizens without homes
		 * and assigns them a home if the building is not at max capacity if a new citizen was added
		 */
		void houseNewCitizens();

		/**
		* @brief goes through the buildings vector and determines the amount of available rooms for new citizens
		* @return Number of rooms not used.
		*/
		int emptyRooms();

		/**
		* @brief goes through the buildings vector and calls the consumeResources function on each
		*/
		void consumeDailyResources();

		/**
		* @brief destructor
		*/
		~ResidentialDepartment();
};

#endif
