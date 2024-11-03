#ifndef TRANSPORTCOMMAND_H
#define TRANSPORTCOMMAND_H

#include "Transportation.h"

class TransportCommand
{
	public:
		//Transportation* Transport; //= new Transportation();
		
		virtual void execute(Transportation* Transport ) = 0;

		virtual bool getStatus() = 0;

		virtual ~TransportCommand() {};
	};

class OpenBusiness : public TransportCommand
{
	public:
		bool open;

		void execute(Transportation* Transport );

		bool getStatus();
};

class CloseBusiness : public TransportCommand
{
	public:
		bool close;

		void execute(Transportation* Transport );

		bool getStatus();
};


#endif
