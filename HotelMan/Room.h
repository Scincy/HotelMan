#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Room
{
    bool occupy;
    int grade;
    int floorLevel;
    int story;
}Room;
char* GetRoomNumber(Room room);