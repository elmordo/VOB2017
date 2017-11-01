#include "ServiceContainer.h"


ServiceContainer::ServiceContainer()
{
	factory = NULL;
	isShared = false;
	instance = NULL;
}

ServiceContainer::ServiceContainer(IServiceFactory *factory, bool isShared)
{
	this->factory = factory;
	this->isShared = isShared;
	this->instance = NULL;
}

ServiceContainer::~ServiceContainer()
{
	delete factory;
	
	if (instance)
		delete instance;
}

Service *ServiceContainer::getInstance()
{
	if (isShared)
	{
		if (instance == NULL)
			instance = factory->createServiceInstance();
		return instance;
	}
	else
	{
		return factory->createServiceInstance();
	}
}