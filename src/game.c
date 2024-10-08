# include "game.h"

int main(int argc, char *argv[])
{
	printf("Program Started\n");

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
	for (int i = 0; i < 100; i++)
	{
		updateSceneContent(actualScene);
		renderSceneContent(actualScene);
	}

	return 0;
}