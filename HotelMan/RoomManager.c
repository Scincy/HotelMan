#include "RoomManager.h"

RoomNumber ConvertStringToRoomNumber(const char* roomNumberStr)
{
    RoomNumber result = {
            (int)roomNumberStr[0]*10+(int)roomNumberStr[1],//floor
            (int)roomNumberStr[2]*10+(int)roomNumberStr[3]//order
    };
    return result;
}

Room* GetRoomsAtFloor(int floor)
{
	//TODO 특정 층에 있는 방을 반환하는 함수 구현
}

Room GetRoom(RoomNumber number)
{
    return roomManager.rooms[number.floor-1][number.order];
}

void AddService(RoomNumber number)
{
    roomManager.rooms
}

void Initialize(RoomManager manager)
{
    for(int i = 0; i < floorInBuilding; i++)
    {
        for(int j = 0; j < roomsIn1floor; j++)
        {
            RoomNumber number = {i,j};
            RoomGrade grade = ;
            Initialize(&manager.rooms[i][j], number, );
        }
    }
}