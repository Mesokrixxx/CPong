# include "include/entity.h"
# include <stdlib.h>
# include <stdio.h>

Entity* initEntity(float x, float y, float z)
{
	Entity* self = calloc(1, sizeof(struct ENTITY_STRUCT));

	return entityConstructor(self, x, y , z, entityInit, entityUpdate, entityDraw);
}

Entity* entityConstructor(Entity* self, float x, float y, float z, void (*init)(void* vSelf), void (*update)(void* vSelf), void (*draw)(void* vSelf))
{
	Content* cSelf = (Content*) self;

	contentConstructor(cSelf, entityInit, entityUpdate, entityDraw);

	self->x = x;
	self->y = y;
	self->z = z;

	return self;
}

void entityInit(void* vSelf) {}

void entityUpdate(void* vSelf) {}

void entityDraw(void* vSelf)
{
	Entity* self = (Entity*) vSelf;

	glGenBuffers(1, &self->VBO);
	glGenBuffers(1, &self->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, self->VBO);

	float verticles[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	Shader* shader = newShader("default", "fragmentDefault.glsl", "vertexDefault.glsl");

	glUseProgram(shader->program);
}
