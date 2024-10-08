# include "scene.h"

Scene* newScene()
{
	Scene* scene = calloc(1, sizeof(struct SCENE_STRUCT));

	scene->content = initDynamicList(sizeof(struct CONTENT_STRUCT));

	return scene;
}

void addContentToScene(Scene* scene, Content* c)
{
	appendItemToDynamicList(scene->content, c);
}

void initSceneContent(Scene* scene)
{
	for (unsigned int i = 0; i < scene->content->size; i++)
	{
		Content* c = (Content*) scene->content->items[i];

		if (c->update)
			c->init(c);
	}
}

void updateSceneContent(Scene* scene)
{
	for (unsigned int i = 0; i < scene->content->size; i++)
	{
		Content* c = (Content*) scene->content->items[i];

		if (c->update)
			c->update(c);
	}
}

void updateSceneContent(Scene* scene)
{
	for (unsigned int i = 0; i < scene->content->size; i++)
	{
		Content* c = (Content*) scene->content->items[i];

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

Scene* getCurrentScene(SceneManager* sceneM)
{
	return (Scene*) sceneM->scenes->items[sceneM->sceneIndex];
}