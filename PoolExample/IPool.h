#pragma once

#include "Room.h"


class IPool
{

public:

	IPool();

	virtual ~IPool();

	virtual Room *acquireRoom() = 0;

	virtual void releaseRoom(Room *room) = 0;

	virtual IPool *clone() const = 0;

};
