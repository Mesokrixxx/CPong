# include "include/scene.h"
# include "include/graphics.h"
# include "include/content.h"
# include <stdlib.h>

Scene* newScene()
{
	Scene* scene = calloc(1, sizeof(struct SCENE_STRUCT));

	scene->contents = initDynamicList(sizeof(struct CONTENT_STRUCT));

	glGenVertexArrays(1, &scene->VAO);

	return scene;
}

void addContentToScene(Scene* scene, void* content)
{
	addItemToDynamicList(scene->contents, content);
}

void initSceneContent(Scene* scene)
{
	glBindVertexArray(scene->VAO);

	for (unsigned int i = 0; i < scene->contents->size; i++)
	{
		Content* c = (Content*) scene->contents->items[i];

		if (c->update)
			c->init(c);
	}

	glBindVertexArray(0);
}

void updateSceneContent(Scene* scene)
{
	for (unsigned int i = 0; i < scene->contents->size; i++)
	{
		Content* c = (Content*) scene->contents->items[i];

		if (c->update)
			c->update(c);
	}
}

void renderSceneContent(Scene* scene)
{
	glBindVertexArray(scene->VAO);

	for (unsigned int i = 0; i < scene->contents->size; i++)
	{
		Content* c = (Content*) scene->contents->items[i];

		if (c->update)
			c->draw(c);
	}

	glBindVertexArray(0);
}

SceneManager* newSceneManager()
{
	SceneManager* sceneM = calloc(1, sizeof(struct SCENE_MANAGER_STRUCT));

	sceneM->sceneIndex = 0;
	sceneM->scenes = initDynamicList(sizeof(struct SCENE_STRUCT));

	return sceneM;
}

void addSceneToSceneManager(SceneManager* sceneM, Scene* scene)
{
	addItemToDynamicList(sceneM->scenes, scene);
}

void initScenesContent(SceneManager* sceneM)
{
	for (unsigned int i = 0; i < sceneM->scenes->size; i++)
		initSceneContent((Scene*) sceneM->scenes->items[i]);
}

Scene* getCurrentScene(SceneManager* sceneM)
{
	return (Scene*) sceneM->scenes->items[sceneM->sceneIndex];
}