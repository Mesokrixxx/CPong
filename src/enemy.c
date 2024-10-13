#include "include/enemy.h"

struct {
	// Utils
	u32 enemyW, enemyH;
	f32 acceleration, friction; 
	Vec2 pos, vel;
	// Graphics
	u32 color;
	// AI
	u32 strenght;
} enemy;

void enemyInit() {
	enemy.enemyW = 8;
	enemy.enemyH = 32;

	enemy.acceleration = 1.0f;
	enemy.friction = 0.3f;

	enemy.pos = (Vec2) {MapWidth - 3 - enemy.enemyW, 1.0f};
	enemy.vel = (Vec2) {0.0f, 0.0f};

	enemy.color = 0xFFFFFFFF;

	enemy.strenght = 0;
}

void enemyUpdate() {

}

void enemyDraw(u32 pixels[]) {
	for (int x = enemy.pos.x; x < (int) (enemy.pos.x + enemy.enemyW); x++)
		for (int y = enemy.pos.y; y < (int) (enemy.pos.y + enemy.enemyH); y++)
			pixels[(y * MapWidth) + x] = enemy.color;
}
