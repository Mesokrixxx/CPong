# ifndef PONG_ENTITY_H
# define PONG_ENTITY_H
# include "content.h"
# include "graphics.h"
# include "shader.h"

typedef struct ENTITY_STRUCT {
	Content base;
	float x;
	float y;
	float z;
	unsigned int VBO;
} Entity;

Entity* initEntity(float x, float y, float z);
Entity* entityConstructor(Entity* self, float x, float y, float z, void (*init)(void* vSelf), void (*update)(void* vSelf), void (*draw)(void* vSelf));
void initEntityRenderMethod(Entity* self);

void entityInit(void* vSelf);
void entityUpdate(void* vSelf);
void entityDraw(void* vSelf);

# endif