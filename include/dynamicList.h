# ifndef PONG_DYNAMIC_LIST_H
# define PONG_DYNAMIC_LIST_H

typedef struct DYNAMIC_LIST_STRUCT {
	unsigned int size;
	unsigned int itemSize;
	void** items;
} dynamicList;

dynamicList* initDynamicList(unsigned int itemSize);

void appendItemDynamicList(dynamicList* dList, void* item);

# endif