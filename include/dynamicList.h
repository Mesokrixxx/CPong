# ifndef PONG_DYNAMIC_LIST_H
# define PONG_DYNAMIC_LIST_H

typedef struct DYNAMIC_LIST_STRUCT {
	unsigned int size;
	unsigned int itemSize;
	void** items;
} DynamicList;

DynamicList* initDynamicList(unsigned int itemSize);
void appendItemToDynamicList(DynamicList* dList, void* item);
void freeDynamicList(DynamicList* dList);

# endif