#include "Room.h"
#include <string.h>
#include <stdio.h>
#include "RoomService.h"
void Initialize(Room* room, RoomNumber newRoomNumber, RoomGrade newGrade)
{
    room->number = newRoomNumber;
    room->grade = newGrade;
}
char* GetRoomIDString(RoomNumber number)
{
    char* roomNumber = (char*)malloc(5 * sizeof(char)); // 최대 4자리 수 + 널 종료 문자('\0')를 저장하기 위해 5개의 문자 공간 할당

    // 방 번호를 문자열로 변환
    sprintf(roomNumber, "%d%d%d", number.floor / 10, number.floor % 10, number.order);

    return roomNumber;
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
	int serviceCount = room->RoomServiceList.count;
	if (serviceCount <= 0) return 0;

	for (int i = 0; i < serviceCount; i++)
	{
		int singleServicePrice = room->RoomServiceList.items[i].servicePrice;
		int provideCount = room->RoomServiceList.items[i].privideCount;
		servicePriceTotal += singleServicePrice * provideCount;
	}

	return servicePriceTotal;
}

