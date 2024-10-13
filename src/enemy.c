# include "include/enemy.h"
# include "include/ball.h"

enemy_t* enemy;

extern ball_t* ball;

static void resolveCollision() {
	if (enemy->pos.y + enemy->enemyH > MapHeight) {
		enemy->pos.y = MapHeight - enemy->enemyH;
		enemy->vel.y *= -1;
	}

	if (enemy->pos.y < 0) {
		enemy->pos.y = 0;
		enemy->vel.y *= -1;
	}
}

void enemyInit() {
	enemy = calloc(1, sizeof(struct enemy_s));

	enemy->enemyW = 8;
	enemy->enemyH = 32;

	enemy->acceleration = 1.0f;
	enemy->friction = 0.3f;

	enemy->pos = (Vec2) {MapWidth - 3 - enemy->enemyW, 1.0f};
	enemy->vel = (Vec2) {0.0f, 0.0f};

	enemy->color = 0xFFFFFFFF;

	enemy->strenght = 0;
}

void enemyUpdate() {
	Vec2 bpos = ball->pos;

	if (bpos.y > enemy->pos.y + enemy->enemyH / 2)
		enemy->vel.y += enemy->acceleration;
	if (bpos.y < enemy->pos.y + enemy->enemyH / 2)
		enemy->vel.y -= enemy->acceleration;

	enemy->vel.y *= (1.0f - enemy->friction);

	enemy->pos.y += enemy->vel.y;

	resolveCollision();

	ASSERT(
		!(enemy->pos.y + enemy->enemyH / 2 < 0
			|| enemy->pos.y - enemy->enemyH / 2 > MapHeight),
		"Enemy out of bounds\n");
}

void enemyDraw(u32 pixels[]) {
	for (int x = enemy->pos.x; x < (int) (enemy->pos.x + enemy->enemyW); x++)
		for (int y = enemy->pos.y; y < (int) (enemy->pos.y + enemy->enemyH); y++)
			pixels[(y * MapWidth) + x] = enemy->color;
}
