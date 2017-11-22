#pragma once

#include <vector>

#include "IPool.h"

using namespace std;


class DynamicPool : public IPool
{

	typedef vector<Room *> RoomList;

	RoomList rooms;

public:

	DynamicPool();

	virtual ~DynamicPool();

	virtual Room *acquireRoom();

	virtual void releaseRoom(Room *room);

	virtual IPool *clone() const;

};
