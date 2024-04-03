#pragma once
#include <stdbool.h>
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
	ServiceList RoomServiceList;
	bool occupy;
}Room;


void Initialize(Room* room, RoomNumber roomNumber, RoomGrade grade);
char* GetRoomIDString(RoomNumber room);


int GetRoomRecept(Room* room);

int CalcRoomCharge(Room* room);
int CalcServiceCharge(Room* room);