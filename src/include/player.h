# ifndef PONG_PLAYER_H
# define PONG_PLAYER_H
# include "main.h"

typedef struct player_s{
	// Utils
	f32 acceleration, friction; 
	Vec2 size, pos, vel;
	// Graphics
	u32 color;
} player_t;

void playerInit();
void playerUpdate();
void playerDraw(u32 pixels[]);

# endif