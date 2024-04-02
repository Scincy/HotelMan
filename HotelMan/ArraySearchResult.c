#pragma once
#include "ArraySearchResult.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Initialize(ArraySearchResult* item)
{
    item->intialized = true;
    item->result = false;
    item->foundIndex = -1;
}

void AddFoundIndex(ArraySearchResult* item, int newFoundIndex)
{
    item->result = true;
    item->foundIndex = newFoundIndex;
}