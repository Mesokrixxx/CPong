# include "include/main.h"
# include <stdio.h>

// Global variables (Do not change) 
SceneManager* MAIN_SCENE_M;
ShaderManager* MAIN_SHADER_M;
char* SHADER_PATH = "src/res/shaders/";

// Parameters
int DEBUG = TRUE;
int DEBUG_VIEW = FALSE;

int main(int argc, char *argv[])
{
	// Window setup
	GLFWwindow* window = setupWindow();
	if (window == NULL)
		return -1;

	// Default Variables for tests
	MAIN_SCENE_M = newSceneManager();
	MAIN_SHADER_M = newShaderManager();

	Scene* defaultScene = newScene();
	Entity* defaultEntity = initEntity(0.0f, 0.0f, 0.0f);
	addContentToScene(defaultScene, defaultEntity);
	addSceneToSceneManager(MAIN_SCENE_M, defaultScene);

	Shader* defaultShader = newShader("default", "fragmentDefault.fs.glsl", "vertexDefault.vs.glsl");
	Shader* defaultShaderTransform = newShader("defaultTransform", "fragmentDefault.fs.glsl", "vertexDefaultTransform.vs.glsl");
	addShaderToShaderManager(MAIN_SHADER_M, defaultShader);
	addShaderToShaderManager(MAIN_SHADER_M, defaultShaderTransform);

	// Main loop
	initScenesContent(MAIN_SCENE_M);
	
	MAIN_SCENE_M->sceneIndex = 0;
	Scene* actualScene = getCurrentScene(MAIN_SCENE_M);

	viewMode();
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(48.0f / 255.0f, 48.0f / 255.0f, 48.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Rendering Game
		updateSceneContent(actualScene);
		renderSceneContent(actualScene);

	    glfwSwapBuffers(window);
	    glfwPollEvents();    
	}

	glfwTerminate();

	return 0;
}