#include "TransportCommand.h"

void OpenBusiness::execute()
{
	Transport->open();
}

bool OpenBusiness::getStatus()
{
	return open;
}

void CloseBusiness::execute()
{
	Transport->close();
}

bool CloseBusiness::getStatus()
{
	return close;
}
