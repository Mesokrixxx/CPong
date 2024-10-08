# include "include/content.h"
# include <stdlib.h>
# include <stdio.h>

Content* initContent()
{
	Content* self = calloc(1, sizeof(struct CONTENT_STRUCT));

	return contentConstructor(self, contentInit, contentUpdate, contentDraw); 
}

Content* contentConstructor(Content* self, void (*init)(void* vSelf), void (*update)(void* vSelf), void (*draw)(void* vSelf))
{
	self->init = init;
	self->draw = draw;
	self->update = update;

	return self;
}

void contentInit(void* vSelf) {}
void contentUpdate(void* vSelf) {}
void contentDraw(void* vSelf) {}
