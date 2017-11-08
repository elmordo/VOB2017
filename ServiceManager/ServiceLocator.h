#pragma once

#include <string>
#include <map>

#include "Service.h"	
#include "IServiceFactory.h"
#include "ServiceContainer.h"

using namespace std;


class ServiceLocator
{

	typedef map<string, ServiceContainer> ContainerMap;

	ContainerMap services;

public:

	ServiceLocator();

	virtual ~ServiceLocator();

	Service *getService(const string &serviceName) const;

	bool hasService(const string &serviceName) const;

	void registerService(const string &serviceName, IServiceFactory *factory, bool isShared);

	void unregisterService(const string &serviceName);

};

