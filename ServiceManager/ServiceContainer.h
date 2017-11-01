#pragma once

#include <cstddef>

#include "Service.h"
#include "IServiceFactory.h"


class ServiceContainer
{

	IServiceFactory *factory;

	bool isShared;

	Service *instance;

public:
	ServiceContainer();

	ServiceContainer(IServiceFactory *factory, bool isShared);

	virtual ~ServiceContainer();

	Service *getInstance();

};

