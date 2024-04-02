#pragma once
#include "Room.h"

const int floorInBuilding = 4;
typedef struct
{
	Room rooms[floorInBuilding][20];
}RoomManager;


Room* GetRoomsAtFloor(RoomManager* manager, int floor);
