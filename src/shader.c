# include "include/shader.h"
# include "include/graphics.h"
# include "include/utils.h"
# include <stdlib.h>
# include <stdio.h>

char* SHADER_PATH = "src/res/shaders/";

Shader* newShader(char* name, char* fragmentShaderFileName, char* vertexShaderFileName)
{
	// Create a shader program
    int success;
    char infoLog[512];
	
	// Vertex shader part
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	char* vertexShaderPath = strCat(SHADER_PATH, vertexShaderFileName);
	const char* vertexShaderSource = readFile(vertexShaderPath);
    
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Failed to compile vertex shader %s of the %s shader\n", vertexShaderPath, name);

        if (vertexShaderPath)
        	free(vertexShaderPath);
        
        return NULL;
    }

    free(vertexShaderPath);

    // Fragment shader part
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    char* fragmentShaderPath = strCat(SHADER_PATH, fragmentShaderFileName);
	const char* fragmentShaderSource = readFile(fragmentShaderPath);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("Failed to compile fragment shader %s of the %s shader\n", fragmentShaderPath, name);

        if (fragmentShaderPath)
        	free(fragmentShaderPath);
        
        return NULL;
    }

    free(fragmentShaderPath);

    // Create the program
    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Failed to make a shader program of the %s shader\n", name);

        return NULL;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

	// Actually init the shader
	Shader* shader = calloc(1, sizeof(struct SHADER_STRUCT));

	shader->name = name;
	shader->program = shaderProgram;

	return shader;
}

ShaderManager* newShaderManager()
{
	ShaderManager* shaderM = calloc(1, sizeof(struct SHADER_MANAGER_STRUCT));

	shaderM->shaders = initDynamicList(sizeof(struct SHADER_STRUCT));

	return shaderM;
}

void addShaderToShaderManager(ShaderManager* shaderM, Shader* shader)
{
	addItemToDynamicList(shaderM->shaders, shader);
}

Shader* getShader(ShaderManager* shaderM, char* name)
{
	for (int i = 0; i < shaderM->shaders->size; i++)
	{
		Shader* shader = (Shader*) shaderM->shaders->items[i];

		if (strCmp(shader->name, name) == 0)
			return shader;
	}

	printf("Not able to find the shader called %s\n", name);
	return NULL;
}
