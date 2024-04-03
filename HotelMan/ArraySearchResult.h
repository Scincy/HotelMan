#pragma once
#include <stdbool.h>
typedef struct {
    bool intialized;
    /// <summary>
    /// 검색 결과가 참인지 거짓인지 여부
    /// </summary>
    bool result;
    /// <summary>
    /// 겸색해서 찾은 위치
    /// </summary>
    int foundIndex;
}ArraySearchResult;

void Initialize(ArraySearchResult* item);

void AddFoundIndex(ArraySearchResult* item, int newFoundIndex);