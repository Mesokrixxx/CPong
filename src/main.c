# include "include/main.h"

SceneManager* MAIN_SCENE_M;
ShaderManager* MAIN_SHADER_M;

char* SHADER_PATH = "src/res/shaders/";

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

	Shader* defaultShader = newShader("default", "fragmentDefault.glsl", "vertexDefault.glsl");
	addShaderToShaderManager(MAIN_SHADER_M, defaultShader);

	// Main loop
	initScenesContent(MAIN_SCENE_M);
	
	MAIN_SCENE_M->sceneIndex = 0;
	Scene* actualScene = getCurrentScene(MAIN_SCENE_M);
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