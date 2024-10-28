#ifndef UTILITYCOMMAND_H
#define UTILITYCOMMAND_H

#include "UtilitiesDepartment.h"

class UtilityCommand
{
	public:
		UtilitiesDepartment* UtilitiesDepart = new UtilitiesDepartment();

		virtual void execute() = 0;

		virtual bool getStatus() = 0;
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
