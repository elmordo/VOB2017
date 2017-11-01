#pragma once

#include "Service.h"

class IServiceFactory
{

public:

	IServiceFactory();

	virtual ~IServiceFactory();

	virtual Service *createServiceInstance() const = 0;

};

