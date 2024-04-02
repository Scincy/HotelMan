#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "RoomService.h"
#include "ArraySearchResult.h"
typedef struct {
    RoomService* items;
    /// <summary>
    /// 현재 리스트에 존재하는 서비스의 갯수
    /// </summary>
    int count;
} ServiceList;


/// 리스트 초기화
void Initialize(ServiceList* array);
void Initialize(ServiceList* array, int capa);

/// 특정 서비스가 리스트에 이미 존재하고 있는지 검사합니다.
ArraySearchResult IsServiceExist(ServiceList* array, char* compareName);

/// 새로운 룸 서비스 추가
void AddRoomService(ServiceList* array, RoomService item);
/// 룸 서비스 제거
bool RemoveRoomService(ServiceList* array, char* name, int count);

