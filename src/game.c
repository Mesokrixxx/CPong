# include "game.h"

int main(int argc, char *argv[])
{
	printf("Program Started\n");

	// Window setup
	GLFWwindow* window = setupWindow();
	if (window == NULL)
		return -1;

	// Default Variables for tests
	SceneManager* defaultSceneM = newSceneManager();
	Scene* defaultScene = newScene();
	Content* defaultContent = initContent();

	addContentToScene(defaultScene, defaultContent);

	addSceneToSceneManager(defaultSceneM, defaultScene);

	// Main loop
	initScenesContent(defaultSceneM);
	
	defaultSceneM->sceneIndex = 0;
	Scene* actualScene = getCurrentScene(defaultSceneM);
	
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