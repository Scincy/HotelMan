#include "Room.h"
#include <string.h>
#include <stdio.h>
#include "RoomService.h"
char* GetRoomIDString(Room room)
{
	return sprintf(room.number.floor, "%d%d%d", room.number.floor, room.number.order / 10, room.number.order % 10);
}

char* GetRoomIDString(RoomNumber roomNum)
{
	return sprintf(roomNum.floor, "%d%d%d", roomNum.floor, roomNum.order / 10, roomNum.order % 10);
}

int GetRoomRecept(Room* room)
{
	return CalcRoomCharge(room) + CalcServiceCharge(room);
}

int CalcRoomCharge(Room* room)
{
	int roomprice = 0;

	switch (room->grade)
	{
	case A:
		roomprice = 100000;
		break;
	case B:
		roomprice = 80000;
	case C:
		roomprice = 60000;
		break;
	default:
		roomprice = 10000;
		break;
	}

	return roomprice;
}
int CalcServiceCharge(Room* room)
{
	int servicePriceTotal = 0;
	int serviceCount = room->RoomService.count;
	if (serviceCount <= 0) return 0;

	for (int i = 0; i < serviceCount; i++)
	{
		int singleServicePrice = room->RoomService.items[i].servicePrice;
		int provideCount = room->RoomService.items[i].privideCount;
		servicePriceTotal += singleServicePrice * provideCount;
	}

	return servicePriceTotal;
}

