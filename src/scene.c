# include "include/scene.h"
# include <stdlib.h>

Scene* newScene()
{
	Scene* scene = calloc(1, sizeof(struct SCENE_STRUCT));

	scene->contents = initDynamicList(sizeof(struct CONTENT_STRUCT));

	return scene;
}

void addContentToScene(Scene* scene, Content* content)
{
	appendItemToDynamicList(scene->contents, content);
}

void initSceneContent(Scene* scene)
{
	for (unsigned int i = 0; i < scene->contents->size; i++)
	{
		Content* c = (Content*) scene->contents->items[i];

		if (c->update)
			c->init(c);
	}
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
	for (unsigned int i = 0; i < scene->contents->size; i++)
	{
		Content* c = (Content*) scene->contents->items[i];

		if (c->update)
			c->draw(c);
	}
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
	appendItemToDynamicList(sceneM->scenes, scene);
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