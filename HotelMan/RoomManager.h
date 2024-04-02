#pragma once
#include "Room.h"
typedef struct
{
	Room rooms[4][20];
}RoomManager;


Room* GetRoomsAtFloor(RoomManager* manager, int floor);
