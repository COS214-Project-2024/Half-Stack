#ifndef TRANSPORTCOMMAND_H
#define TRANSPORTCOMMAND_H

#include "Transportation.h"

class TransportCommand
{
	public:
		Transportation* Transport; //= new Transportation();
		
		virtual void execute() = 0;

		virtual bool getStatus() = 0;
	};

class OpenBusiness : public TransportCommand
{
	public:
		bool open;

		void execute();

		bool getStatus();
};

class CloseBusiness : public TransportCommand
{
	public:
		bool close;

		void execute();

		bool getStatus();
};


#endif
