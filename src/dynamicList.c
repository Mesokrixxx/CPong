# include "dynamicList.h"
# include <stdlib.h>

DynamicList* initDynamicList(unsigned int itemSize)
{
	DynamicList* dList = calloc(1, sizeof(struct DYNAMIC_LIST_STRUCT));

	dList->size = 0;
	dList->itemSize = itemSize;

	return dList;
}

void appendItemToDynamicList(DynamicList* dList, void* item)
{
	dList->size++;
	dList->items = realloc(dList->items, (dList->size + 1) * dList->itemSize);
	dList->items[dList->size - 1] = item;
}

void freeDynamicList(DynamicList* dList)
{
	free(dList->items);
	free(dList);
}