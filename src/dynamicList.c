# include "dynamicList.h"
# include <stdlib.h>

dynamicList* initDynamicList(unsigned int itemSize)
{
	dynamicList* dList = calloc(1, sizeof(struct DYNAMIC_LIST_STRUCT));

	dList->size = 0;
	dList->itemSize = itemSize;

	return dList;
}

void appendItemDynamicList(dynamicList* dList, void* item)
{
	dList->size++;
	dList->items = realloc(dList->items, (dList->size + 1) * dList->itemSize);
	dList->items[dList->size - 1] = item;
}