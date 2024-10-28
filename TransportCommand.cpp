#include "TransportCommand.h"

void OpenBusiness::execute()
{
	TransportDepart->openTransport();
}

bool OpenBusiness::getStatus()
{
	return open;
}

void CloseBusiness::execute()
{
	TransportDepart->closeTransport();
}

bool CloseBusiness::getStatus()
{
	return close;
}
