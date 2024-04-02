#pragma once
#include "ServiceList.h"
typedef enum 
{
	A = 'A', B = 'B', C = 'C'
}RoomGrade;
typedef struct 
{
	int floor;
	int order;
}RoomNumber;

typedef struct
{
	RoomNumber number;
	RoomGrade grade;
	ServiceList RoomService
}Room;



char* GetRoomIDString(RoomNumber room);
char* GetRoomIDString(Room room);


int GetRoomRecept(Room* room);

int CalcRoomCharge(Room* room);
int CalcServiceCharge(Room* room);