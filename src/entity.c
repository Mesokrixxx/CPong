# include "include/entity.h"
# include "include/shader.h"
# include "include/utils.h"
# include "include/scene.h"
# include <stdlib.h>
# include <stdio.h>

extern ShaderManager* MAIN_SHADER_M;

Entity* initEntity(float x, float y, float z)
{
	Entity* self = calloc(1, sizeof(struct ENTITY_STRUCT));

	initEntityRenderMethod(self);

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

void initEntityRenderMethod(Entity* self)
{
	glGenBuffers(1, &self->VBO);

	float vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.0f,  0.5f, 0.0f
	};  
	
	glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void entityInit(void* vSelf) {}

void entityUpdate(void* vSelf) {}

void entityDraw(void* vSelf)
{
	glVertexAttribPointer(0, 3, GL_FLOAT, FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	glUseProgram(getShaderProgram(MAIN_SHADER_M, "default"));
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
