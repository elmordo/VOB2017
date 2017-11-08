#pragma once

#include <cstddef>

#include "Service.h"
#include "IServiceFactory.h"


class ServiceContainer
{

	IServiceFactory *factory;

	bool isShared;

	Service *instance;

	Service *createInstanceAndInitialize(const ServiceLocator *serviceLocator);

public:
	ServiceContainer();

	ServiceContainer(IServiceFactory *factory, bool isShared);

	virtual ~ServiceContainer();

	Service *getInstance(const ServiceLocator *serviceLocator);
};
