#ifndef UTILITYCOMMAND_H
#define UTILITYCOMMAND_H

#include "UtilitiesDepartment.h"

class UtilitiesDepartment;

class UtilityCommand
{
	protected:
		UtilitiesDepartment* UtilitiesDepart; // = new UtilitiesDepartment();
	public:

		UtilityCommand();
		
		virtual void execute() = 0;

		virtual bool getStatus() = 0;

		virtual ~UtilityCommand() {};
};

class SupplyWater : public UtilityCommand
{
	private:
		int water;

	public:
		void execute();

		bool getStatus();
};

class SupplyPower : public UtilityCommand
{
	private:
		int energy;

	public:
		void execute();

		bool getStatus();
};

class ManageWaste : public UtilityCommand
{
	private:
		bool open;

	public:

		void execute();

		bool getStatus();
};

class ManageSewage : public UtilityCommand
{
	private:
		bool open;

	public:
		void execute();

		bool getStatus();
};

#endif
