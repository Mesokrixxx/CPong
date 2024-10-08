# ifndef PONG_SHADER_H
# define PONG_SHADER_H
# include "dynamicList.h"

typedef struct SHADER_STRUCT {
	unsigned int program;
	char* name;
} Shader;

Shader* newShader(char* name, char* fragmentShaderFileName, char* vertexShaderFileName);

typedef struct SHADER_MANAGER_STRUCT {
	DynamicList* shaders;
} ShaderManager;

ShaderManager* newShaderManager();
void addShaderToShaderManager(ShaderManager* shaderM, Shader* shader);
Shader* getShader(ShaderManager* shaderM, char* name);

# endif 