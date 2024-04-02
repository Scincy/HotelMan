#pragma once
#include "Room.h"

const int floorInBuilding = 4;
typedef struct
{
	Room rooms[floorInBuilding][20];
}RoomManager;


Room* GetRoomsAtFloor(RoomManager* manager, int floor);


/// 특정 방 번호를 가진 빙에 서비스를 추가합니다.
void AddService(RoomNumber number);