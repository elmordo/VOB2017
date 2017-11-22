#include "DynamicPool.h"



DynamicPool::DynamicPool()
{
}

DynamicPool::~DynamicPool()
{
	for (RoomList::iterator p = rooms.begin(); p != rooms.end(); ++p)
	for (Room *r : rooms) 
		delete r;
}

Room *DynamicPool::acquireRoom()
{
	if (rooms.size() == 0)
		rooms.push_back(new Room());

	Room *result = rooms.back();
	rooms.pop_back();
	return result;
}

void DynamicPool::releaseRoom(Room *room)
{
	rooms.push_back(room);
}

IPool *DynamicPool::clone() const
{
	DynamicPool *result = new DynamicPool();

	for (size_t i = 0; i < rooms.size(); ++i)
		result->rooms.push_back(new Room());

	return result;
}