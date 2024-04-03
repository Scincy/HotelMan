#pragma once

#include <stdio.h>
#include <windows.h>
#include "RoomManager.h"
typedef enum
{
    Black = 0,
    DarkBlue = 1,
    DarkGreen = 2,
    DarkSkyBlue = 3,
    DarkRed = 4,
    DarkPurple = 5,
    DarkYellow = 6,
    Gray = 7,
    DarkGray = 8,
    Blue = 9,
    Green = 10,
    SkyBlue = 11,
    Red = 12,
    Purple = 13,
    Yellow = 14,
    White = 15
}TextColor;

static RoomManager roomManager;


void Initialize();

//화면에서 한 줄을 삭제
void RemoveLine();

void SetPrintColor(TextColor color);

TextColor GetRoomColorForGrade(RoomGrade grade);

int GetIntInput();

void PrintMenu();

void ShowDisplay();

