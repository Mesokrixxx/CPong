# include "include/enemy.h"
# include "include/ball.h"

enemy_t* enemy;

extern ball_t* ball;

static void resolveCollision() {
	Vec2 pos = enemy->pos, size = enemy->size;

	if (pos.y + size.y > MapHeight) {
		enemy->pos.y = MapHeight - size.y;
		enemy->vel.y *= -1;
	}

	if (pos.y < 0) {
		enemy->pos.y = 0;
		enemy->vel.y *= -1;
	}
}

void enemyInit() {
	enemy = calloc(1, sizeof(struct enemy_s));

	enemy->acceleration = 1.0f;
	enemy->friction = 0.3f;

	enemy->size = (Vec2) {8.0f, 32.0f};
	enemy->pos = (Vec2) {MapWidth - 3 - enemy->size.x, 1.0f};
	enemy->vel = (Vec2) {0.0f, 0.0f};

	enemy->color = WHITE;

	enemy->strenght = 0;
}

void enemyUpdate() {
	Vec2 bpos = ball->pos;
	Vec2 size = enemy->size, pos = enemy->pos;

	if (bpos.y > pos.y + size.y / 2)
		enemy->vel.y += enemy->acceleration;
	if (bpos.y < pos.y + size.y / 2)
		enemy->vel.y -= enemy->acceleration;

	enemy->vel.y *= (1.0f - enemy->friction);

	enemy->pos.y += enemy->vel.y;

	resolveCollision();

	// If collision did not work properlly
	ASSERT(
		!(enemy->pos.y + size.y / 2 < 0
			|| enemy->pos.y - size.y / 2 > MapHeight),
		"Enemy out of bounds\n");
}

void enemyDraw(u32 pixels[]) {
	Vec2 pos = enemy->pos, size = enemy->size;

	for (int x = pos.x; x < (int) (pos.x + size.x); x++)
		for (int y = pos.y; y < (int) (pos.y + size.y); y++)
			pixels[(y * MapWidth) + x] = enemy->color;
}
