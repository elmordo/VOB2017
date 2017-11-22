#include "stdafx.h"
#include "FixedPool.h"


FixedPool::FixedPool()
{
}

FixedPool::FixedPool(size_t numberOfRooms)
{
	for (size_t i = 0; i < numberOfRooms; ++i)
		rooms.push_back(new Room());
}

FixedPool::~FixedPool()
{
	for (Room *r : rooms)
		delete r;
}

Room *FixedPool::acquireRoom()
{
	if (rooms.size() == 0)
		throw 1;

	Room *result = rooms.back();
	rooms.pop_back();
	return result;
}

void FixedPool::releaseRoom(Room *room)
{
	rooms.push_back(room);
}

IPool *FixedPool::clone() const
{
	FixedPool *result = new FixedPool();

	for (size_t i = 0; i < rooms.size(); ++i)
		result->rooms.push_back(new Room());

	return result;
}
