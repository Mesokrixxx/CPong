# include "include/entity.h"
# include "include/utils.h"
# include "include/scene.h"
# include "include/shader.h"
# include "include/graphics.h"
# include "include/pmath.h"
# include <stdlib.h>
# include <stdio.h>

extern ShaderManager* MAIN_SHADER_M;
extern SceneManager* MAIN_SCENE_M;

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

void entityInit(void* vSelf)
{
	Entity* self = (Entity*) vSelf;

	glGenBuffers(1, &self->VBO);
	glGenBuffers(1, &self->EBO);

	float vertices[] = {
	    -0.5f, -0.5f, 0.0f,
	     0.5f, -0.5f, 0.0f,
	     0.5f,  0.5f, 0.0f,
	     -0.5f, 0.5f, 0.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3
	};

    glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void entityUpdate(void* vSelf) {}

void entityDraw(void* vSelf)
{
	

	glUseProgram(getShaderProgram(MAIN_SHADER_M, "defaultTransform"));

	Mat4 mat = mat4(1.0f);
	mat = rotateMat4(mat, (float)glfwGetTime(), vec3(0.0f, 1.0f, 0.0f));
	mat = scaleMat4(mat, vec3(0.5f, 0.5f, 0.5f));

    unsigned int transformLoc = glGetUniformLocation(getShaderProgram(MAIN_SHADER_M, "defaultTransform"), "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, (const GLfloat*) mat.m); 

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
