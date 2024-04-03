#pragma once
#include "Room.h"

const int floorInBuilding = 4;
const int roomsIn1floor = 20;
typedef struct
{
	Room rooms[floorInBuilding][roomsIn1floor];
}RoomManager;

static RoomManager roomManager;

void Initialize(RoomManager manager);

Room* GetRoomsAtFloor(int floor);

/// 특정 방 번호를 가진 빙에 서비스를 추가합니다.
void AddService(RoomNumber number);

RoomGrade configGradeAuto();