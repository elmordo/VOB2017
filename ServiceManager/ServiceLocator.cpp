#include "ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
}


ServiceLocator::~ServiceLocator()
{
}

Service *ServiceLocator::getService(const string &serviceName) const
{
	ServiceLocator *self = const_cast<ServiceLocator *>(this);
	ContainerMap::iterator pos = self->services.find(serviceName);
	Service *service = NULL;

	if (pos != self->services.end())
		service = pos->second.getInstance(this);

	return service;
}

bool ServiceLocator::hasService(const string &serviceName) const
{
	return services.find(serviceName) != services.cend();
}

void ServiceLocator::registerService(const string &serviceName, IServiceFactory *factory, bool isShared)
{
	if (hasService(serviceName))
		throw 666;

	services[serviceName] = ServiceContainer(factory, isShared);
}

void ServiceLocator::unregisterService(const string &serviceName)
{
	ContainerMap::iterator pos = services.find(serviceName);

	if (pos != services.end())
		services.erase(pos);
}

