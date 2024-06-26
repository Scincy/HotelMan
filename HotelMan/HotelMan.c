﻿#define CONFIGFILE_NAME "sys.config"
#define RoomCountInAFloor 20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>
#include "Floor.h"
#include "Display.h"

typedef struct SysConfig
{
    int MaxFloor;
}SysConfig;

typedef struct Hotel
{
    char* name;
    Floor* allRooms;
}Hotel;

static SysConfig sysConfig = { 10 };
static Hotel ManageData;

void InitProgram()
{
    ManageData.allRooms = malloc(sizeof(Floor) * sysConfig.MaxFloor);
    // 호텔 건물속 모든 층의 데이터 초기화
    for (int newFloorLevel = 0; newFloorLevel < sysConfig.MaxFloor; newFloorLevel++)
    {
        ManageData.allRooms[newFloorLevel].level = newFloorLevel+1;
        ManageData.allRooms[newFloorLevel].rooms = malloc(sizeof(Room) * RoomCountInAFloor);

        // 층별 방 데이터 초기화
        for (int j = 0; j < RoomCountInAFloor; j++)
        {

            float a = ((float)newFloorLevel / (float)sysConfig.MaxFloor * 100.0);
            if (a < 60)
                ManageData.allRooms[newFloorLevel].rooms[j].grade = 1;
            else if (a < 80)
                ManageData.allRooms[newFloorLevel].rooms[j].grade = 2;
            else if (a >= 80)
                ManageData.allRooms[newFloorLevel].rooms[j].grade = 3;
            
            

            ManageData.allRooms[newFloorLevel].rooms[j].occupy = false;
            ManageData.allRooms[newFloorLevel].rooms[j].floorLevel = newFloorLevel+1;
            ManageData.allRooms[newFloorLevel].rooms[j].story = j + 1;
        }
    }
}



/// <summary>
/// 화면상에 한줄을 차지하는 표선을 그립니다.
/// </summary>
/// <param name="gap">표안의 여백 길이</param>
/// <param name="length">표선의 최대 길이</param>
/// <param name="start">표의 시작점의 문자</param>
/// <param name="carryon">표의 중간 선 모양</param>
/// <param name="middle">표의 중간 칸과 칸 사이 문자</param>
/// <param name="end">표의 끝점의 문자</param>
void DrawLine(int gap, int length, const char* start, const char* carryon, const char* middle, const char* end)
{
    printf("%s", start);

    for (int i = 0; i < length; i++)
    {
        if (i == 0) continue;
        printf("%s", i % gap == 0 ? middle : carryon);
    }
    printf("%s", end);
}
///콘솔에 출력된 내용에서 매개변수만큼 위의 줄을 제거
void ClearUpperLine(int removeCount)
{
    for (int i = 0; i < removeCount; i++)
    {
        // 커서를 한 줄 위로 올리고 현재 줄을 지움
        printf("\033[A\033[2K");
        // 출력 버퍼를 비워 즉시 변경사항이 적용되도록 함
        fflush(stdout);
    }
}

void SetTextBold()
{
    printf("\n\033[1m");
}

void SetTextUnderline()
{
    printf("\033[4m");
}

void SetTextDefault()
{
    printf("\033[0m");
}

void SetTextPrintColor(TextColor color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
}



TextColor GetColorForRoomGrade(Room room)
{
    switch (room.grade)
    {
    case 1:
        return White;
    case 2:
        return Yellow;
    case 3:
        return SkyBlue;
    default:
        break;
    }
}


void LookupFloor(Floor floor)
{
    printf("\033[1m\033[4m Room %dF     \033[0m\n", floor.level);
    DrawLine(8, 80, "┌", "─", "┬", "┐\n│");

    for (int i = 0; i < RoomCountInAFloor; i++)
    {
        if (i == 10) 
        {
            DrawLine(8, 80, "\n├", "─", "┼", "┤\n│");
        }

        SetTextPrintColor(GetColorForRoomGrade(floor.rooms[i]));
        printf("%4s ", GetRoomNumber(floor.rooms[i]));
        SetTextPrintColor(White);
        printf("%s │", floor.rooms[i].occupy ? "■" : "□");
    }
    DrawLine(8, 80, "\n└", "─", "┴", "┘");
}

void SaveConfig()
{
    FILE* configFile;
    configFile = fopen(CONFIGFILE_NAME, "w");
    fprintf(configFile, "MaxFloor:%d", sysConfig.MaxFloor);
    fclose(configFile);

}

bool IsConfigExist()
{
    FILE* configFile;
    configFile = fopen(CONFIGFILE_NAME, "r");
    if (configFile == NULL) //파일 존재 여부 검사하기
        return false;
    else return true;
    fclose(configFile);
}

void LoadConfig()
{
    FILE* configFile;
    configFile = fopen(CONFIGFILE_NAME, "r");
    if (configFile == NULL) //파일 존재 여부 검사하기
    {
        // 파일이 없으면?
        configFile = fopen(CONFIGFILE_NAME, "w");//새로 만들기
        fprintf(configFile, "MaxFloor:%d", 1); // 기본 설정 예시
        sysConfig.MaxFloor = 1;
    }
    else
    {
        // 파일이 존재하면 설정 읽기
        char buffer[100];
        if (fgets(buffer, 100, configFile) != NULL) {
            sscanf(buffer, "MaxFloor:%d", &sysConfig.MaxFloor);
            printf("설정 로드 완료: MaxFloor = %d\n", sysConfig.MaxFloor);
        }
    }
    fclose(configFile);
}

void PrintTitle()
{
    printf("       ────────────────────────────────────────────────────────────────────────────────\n");
    printf("      //■     ■   ■■■■■   ■■■■■■■  ■■■■■■■  ■        ■■    ■■    ■■■    ■■    ■    //  \n");
    printf("     // ■     ■  ■     ■     ■     ■        ■        ■ ■  ■ ■   ■   ■   ■ ■   ■   //   \n");
    printf("    //  ■■■■■■■  ■     ■     ■     ■■■■■■■  ■        ■  ■■  ■  ■■■■■■■  ■  ■  ■  //    \n");
    printf("   //   ■     ■  ■     ■     ■     ■        ■        ■      ■  ■     ■  ■   ■ ■ //     \n");
    printf("  //    ■     ■   ■■■■■      ■     ■■■■■■■  ■■■■■■■  ■      ■  ■     ■  ■    ■■//      \n");
    printf("────────────────────────────────────────────────────────────────────────────────       \n");
    printf("                             호 텔 전 문 관 리 프 로 그 램                               \n");

}
void StartConfig()
{
    //초기 안내문
    printf("┌─────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                  저희 HOTELMAN 프로그램을 선택해 주셔서 감사합니다                  │\n");
    printf("│                        초기 설정을 위해, 정보를 입력해 주세요.                      │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────────────┘\n");
    SetTextBold();
    SetTextUnderline();
    printf("시스템 설정\n\n");
    SetTextDefault();
    
    bool thereIsError = false;
    do
    {
        printf("건물 층수 : ");
        scanf("%d", &sysConfig.MaxFloor);
        
        if (sysConfig.MaxFloor >= 100 || sysConfig.MaxFloor <= 0)
        {
            
            SetTextPrintColor(Red);
            printf("\n입력에러: 이 프로그램이 지원하는 건물의 층수는 1층이상 ~ 100층 미만입니다.");
            printf("\n계속하시려면 엔터를 입력하세요...\n");
            SetTextPrintColor(White);
            getch();//입력 대기 함수
            ClearUpperLine(4);
            fflush(stdin);//입력 버퍼 초기화
            thereIsError = true;
        }
        else
        {
            SaveConfig();
            thereIsError = false;
        }
    } while (thereIsError);
    
    printf("\n설정이 완료되었습니다. 계속하시려면 엔터를 눌러 주세요.\n");
    getch();
    ClearUpperLine(10);
    fflush(stdin);
}




int MainMenu()
{
    int menuSelect = 0;
    printf("┌─────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                      어서오십시오. 원하시는 메뉴를 선택하세요.                      │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("1. 체크 인\n");
    printf("2. 체크 아웃, 요금 정산\n");
    printf("3. 부가 서비스\n");

    bool thereIsError = false;
    do {
        printf("입력 >> ");
        scanf("%d", &menuSelect);
        if (menuSelect > 3 || menuSelect <= 0)
        {
            SetTextPrintColor(Red);
            printf("\n입력 에러: %d는 메뉴가 아닙니다. 입력을 확인해 주세요.", menuSelect);
            printf("\n계속하시려면 엔터를 입력하세요...\n");
            SetTextPrintColor(White);
            getch();//입력 대기 함수
            thereIsError = true;
        }
        else
        {
            thereIsError = false;
        }
    } while (thereIsError);
    ClearUpperLine(7);
    fflush(stdin);//입력 버퍼 초기화
    return menuSelect;
}


void CheckInMenu()
{
    printf("┌─────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│                               체크인 과정을 시작합니다.                             │\n");
    printf("│                                 정보를 입력해 주세요.                               │\n");
    printf("└─────────────────────────────────────────────────────────────────────────────────────┘\n");


    printf("방 상태 조회\n");

    for (int i = 0; i < 10; i++)
    {
        LookupFloor(ManageData.allRooms[i]);
        printf("\n");
    }
}



void openMenu(int menuID)
{
    switch (menuID)
    {
    case 1:
        CheckInMenu();
        break;

    }
}

int main()
{
    PrintTitle();

    if (!IsConfigExist())
    {
        StartConfig();
    }
    
    InitProgram();
    switch (MainMenu())
    {
    case 1:
        CheckInMenu();
        break;
    }
    

    /*
    for (int i = 0; i < 10; i++)
    {
        LookupFloor(ManageData.allRooms[i]);
        printf("\n");
    }*/
}