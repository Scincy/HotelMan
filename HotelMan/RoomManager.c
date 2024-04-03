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
    return roomManager.rooms[number.floor-1][number.order-1];
}

void AddService(RoomNumber number, RoomService service)
{
    AddRoomService(&(GetRoom(number).RoomServiceList), service);
 
}

RoomGrade configGradeAuto(int floor)
{
    switch (floor)
    {
    case 1:
    case 0:
        return C;
    case 2:
        return B;
    case 3:
        return A;
    default:
        return C;
    }
}


void InitRoomManager()
{
    for(int i = 0; i < FLOOR_IN_BUILDING; i++)
    {
        for(int j = 0; j < ROOMS_IN_1_FLOOR; j++)
        {
            RoomNumber number = {i+1,j+1};
            RoomGrade grade = configGradeAuto(i);
            Initialize(&(roomManager.rooms[i][j]), number, grade);
        }
    }
}