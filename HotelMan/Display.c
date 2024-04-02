
#include <stdio.h>
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




void Initialize()
{

}

void RemoveLine()
{
	printf("\033[1A\033[0J");
	fflush(stdout);  // 변경 사항을 즉시 적용
}

void Show()
{
	//윗줄 그리기
	printf("┌");
	for (int i = 0; i < 10; i++)
	{
		printf("─");
	}
	printf("┐\n");
	
	//층별 방 그리기
	printf("│");
	for (int i = 0; i < 10; i++)
	{

		printf("%c", )
	}

}

