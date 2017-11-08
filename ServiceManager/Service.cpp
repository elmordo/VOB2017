#include "Service.h"


Service::Service()
{
	locator = NULL;
}


Service::~Service()
{
}

void Service::setServiceLocator(const ServiceLocator *locator)
{
	if (locator != NULL)
		throw "Unable to reassign service locator";

	this->locator = locator;
}

const ServiceLocator *Service::getServiceLocator() const
{
	return locator;
}

void Service::initialize()
{
}
