# ifndef PONG_BALL_H
# define PONG_BALL_H
# include "main.h"

typedef struct ball_s {
	// Utils
	f32 speed, radius, friction;
	Vec2 pos, dir, vel;
	// Graphics
	u32 color;
} ball_t;

void ballInit();
void ballUpdate();
void ballDraw(u32 pixels[]);

# endif