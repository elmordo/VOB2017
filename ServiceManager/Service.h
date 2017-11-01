#pragma once

#include <cstddef>

class ServiceLocator;


class Service
{

	const ServiceLocator *locator;

public:

	Service();

	virtual ~Service();

	void setServiceLocator(const ServiceLocator *locator);

	const ServiceLocator *getServiceLocator() const;

};

