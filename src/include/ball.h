# ifndef PONG_BALL_H
# define PONG_BALL_H
# include "main.h"

typedef struct ball_s {
	// Utils
	f32 speed, friction;
	Vec2 size, pos, dir, vel;
	// Graphics
	u32 color;
} ball_t;

void ballInit();
void ballUpdate();
void ballDraw(u32 pixels[]);

# endif