#pragma once
#include "ServiceList.h"
/// 리스트 초기화
void Initialize(ServiceList* array) {
    array->count = 0;

    array->items = (RoomService*)malloc(sizeof(RoomService) * array->count + 1);
}
void Initialize(ServiceList* array, int capa) {
    array->count = 0;

    array->items = (RoomService*)malloc(sizeof(RoomService) * array->count + 1);
}

/// 특정 서비스가 리스트에 이미 존재하고 있는지 검사합니다.
ArraySearchResult IsServiceExist(ServiceList* array, char* compareName)
{
    ArraySearchResult result;
    Initialize(&result);

    if (array->items == NULL || array->count <= 0)
        return result;

    for (int i = 0; i < array->count; i++)
    {
        if (strcmp(array->items[i].serviceName, compareName) == 0)
        {
            AddFoundIndex(&result, i);
            return result;
        }
    }
    return result;
}

/// 새로운 룸 서비스 추가
void AddRoomService(ServiceList* array, RoomService item)
{
    //서비스가 배열에 이미 있는지 검사, 있으면 서비스 갯수 추가
    ArraySearchResult checking;
    Initialize(&checking);
    checking = IsServiceExist(array, item.serviceName);
    if (checking.result)//추가 대상 서비스가 이미 등록된 서비스라면
    {
        //서비스 제공 횟수만 올리고 종료
        array[checking.foundIndex].count += item.privideCount;
        return;
    }
    array->items = (RoomService*)realloc(array->items, sizeof(RoomService) * (array->count + 1));
    array->items[array->count++] = item;
}
/// 룸 서비스 제거
bool RemoveRoomService(ServiceList* array, char* name, int count)
{
    ArraySearchResult checking = IsServiceExist(array, name);
    if (!checking.result) return false;

    // 룸서비스를 제거할 때 제거대상의 양 보다 더 많은 서비스가 요청들어가 있으면?
    if (array->items[checking.foundIndex].privideCount - count <= 0)
    {
        //완전 제거, 덮어 쓰는 방식으로 제거
        for (int i = checking.foundIndex; i < array->count; i++)//제거 대상 위치의 뒤의 요소를 앞으로 당겨서 제거
        {
            array->items[i] = array->items[i + 1];
        }
        array->count--;
    }
    else
    {
        //서비스 수 줄이기
        array->items[checking.foundIndex].privideCount -= count;
    }
}