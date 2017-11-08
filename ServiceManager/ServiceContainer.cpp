#include "ServiceContainer.h"


Service *ServiceContainer::createInstanceAndInitialize(const ServiceLocator *serviceLocator)
{
	Service *instance = factory->createServiceInstance();
	instance->setServiceLocator(serviceLocator);
	instance->initialize();

	return instance;
}

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

Service *ServiceContainer::getInstance(const ServiceLocator *serviceLocator)
{
	if (isShared)
	{
		if (instance == NULL)
			instance = createInstanceAndInitialize(serviceLocator);

		return instance;
	}
	else
	{
		return createInstanceAndInitialize(serviceLocator);
	}
}