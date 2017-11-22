#pragma once

#include <vector>

#include "IPool.h"

using namespace std;


class FixedPool : public IPool
{
	typedef std::vector<Room *> RoomList;

	RoomList rooms;

public:
	FixedPool();

	FixedPool(size_t numberOfRooms);

	virtual ~FixedPool();

	virtual Room *acquireRoom();

	virtual void releaseRoom(Room *room);

	virtual IPool *clone() const;

};

