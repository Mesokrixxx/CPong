# include "include/ball.h"

struct {
	// Utils
	f32 speed, radius, friction;
	Vec2 pos, dir, vel;
	// Graphics
	u32 color;
} ball;

static void resolveCollision() {
	if (ball.pos.y + ball.radius > MapHeight) {
		ball.pos.y = MapHeight - ball.radius;
		ball.vel.y *= -1;
		ball.dir.y *= -1;
	}

	if (ball.pos.y - ball.radius < 0) {
		ball.pos.y = ball.radius;
		ball.vel.y *= -1;
		ball.dir.y *= -1;
	}
}

void ballInit() {
	ball.speed = 1.0f;
	ball.radius = 8.0f / 2.0f;
	ball.friction = 0.1f;

	ball.pos = (Vec2) {MapWidth / 2, MapHeight / 2};
	ball.dir = (Vec2) {1.0f, 1.0f};
	ball.vel = (Vec2) {0.0f, 0.0f};

	ball.color = 0xFFFFFFFF;
}

void ballUpdate() {
	ball.vel.x = ball.speed * ball.dir.x;
	ball.vel.y = ball.speed * ball.dir.y;

	ball.vel.x *= (1.0f - ball.friction);
	ball.vel.y *= (1.0f - ball.friction);

	ball.pos.x += ball.vel.x;
	ball.pos.y += ball.vel.y;

	resolveCollision();
}

void ballDraw(u32 pixels[]) {
	for (int x = ball.pos.x - ball.radius; x < (int) (ball.pos.x + ball.radius); x++)
		for (int y = ball.pos.y - ball.radius; y < (int) (ball.pos.y + ball.radius); y++)
			pixels[(y * MapWidth) + x] = ball.color;
}
