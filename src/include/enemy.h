# ifndef PONG_ENEMY_H
# define PONG_ENEMY_H
# include "main.h"

typedef struct enemy_s {
	// Utils
	f32 acceleration, friction; 
	Vec2 size, pos, vel;
	// Graphics
	u32 color;
	// AI
	u32 strenght;
} enemy_t;

void enemyInit();
void enemyUpdate();
void enemyDraw(u32 pixels[]);

# endif