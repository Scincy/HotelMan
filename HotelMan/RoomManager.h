#pragma once
#include "Room.h"

#define FLOOR_IN_BUILDING 4
#define ROOMS_IN_1_FLOOR 20
typedef struct
{
	Room rooms[FLOOR_IN_BUILDING][ROOMS_IN_1_FLOOR];
}RoomManager;

static RoomManager roomManager;

void InitRoomManager();

Room* GetRoomsAtFloor(int floor);

/// 특정 방 번호를 가진 빙에 서비스를 추가합니다.
void AddService(RoomNumber number);

//방 등급을 자동 부여
RoomGrade configGradeAuto();
Room GetRoom(RoomNumber number);