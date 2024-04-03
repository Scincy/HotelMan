
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


void Initialize()
{
    Initialize(&roomManager);
}

//화면에서 한 줄을 삭제
void RemoveLine()
{
	printf("\033[1A\033[0J");
	fflush(stdout);  // 변경 사항을 즉시 적용
}

void SetPrintColor(TextColor color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
}

TextColor GetRoomColorForGrade(RoomGrade grade)
{
	switch (grade)
	{
	case A:
		return Yellow;
	case B:
		return SkyBlue;
	case C:
		return Green;
	default:
		return White;
	}
}

int GetIntInput()
{
	int result = 0;
	scanf("%d",&result);
	return result;
}

void PrintMenu()
{

}

void Show()
{
	//윗줄 그리기
	printf("┌");
	for (int i = 0; i < 74; i++)
	{
		printf("─");
	}
	printf("┐\n");
	
	//층별 방 그리기
	
	for(int floor = (floorInBuilding-1); floor >= 0; floor--)
	{
		printf("│ %dF ", floor+1);
		for (int i = 0; i < 20; i++)
		{
			RoomGrade grade = roomManager.rooms[floor][i].grade;
			bool occupy = roomManager.rooms[floor][i].occupy;
			char roomIcon = occupy ? "■" : "□";
			if(!occupy)
				SetPrintColor(GetRoomColorForGrade(grade));
			else SetPrintColor(White);
			
			printf("%4s %c ", GetRoomIDString(roomManager.rooms[floor][i]),roomIcon );
			if(i == 9)
			{
				printf("│\n│    ");
			}
		}
		printf("│\n");

		printf("%c", floor == 0 ? "└" : "├");
		for(int i = 0; i < 74; i++){
			printf("─");
		}
		printf("%c", floor == 0 ? "┘" : "┤");
		
	}

}

