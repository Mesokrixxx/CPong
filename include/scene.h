# ifndef PONG_SCENE_H
# define PONG_SCENE_H
# include "dynamicList.h"

typedef struct SCENE_STRUCT {
	DynamicList* content;
} Scene;

Scene* newScene();
void addContentToScene(Scene* scene, Content* content);
void initSceneContent(Scene* scene);
void updateSceneContent(Scene* scene);
void renderSceneContent(Scene* scene);

typedef struct SCENE_MANAGER_STRUCT {
	unsigned int sceneIndex;
	DynamicList* scenes;
} SceneManager;

SceneManager* newSceneManager();
void addSceneToSceneManager(SceneManager* sceneM, Scene* scene);
Scene* getCurrentScene(SceneManager* sceneM);

# endif