# include "include/ball.h"
# include "include/player.h"
# include "include/enemy.h"

ball_t* ball;

extern enemy_t* enemy;
extern player_t* player;

static void rectCollision(Vec2 pos, Vec2 size, Vec2 rectPos, Vec2 rectSize) {

}

static void resolveCollision() {
	Vec2 bpos = ball->pos, bsize = ball->size;

	// Window edge collision
	if (bpos.y + bsize.y > MapHeight) {
		ball->pos.y = MapHeight - bsize.y;
		ball->vel.y *= -1;
		ball->dir.y *= -1;
	}

	if (bpos.y < 0) {
		ball->pos.y = 0;
		ball->vel.y *= -1;
		ball->dir.y *= -1;
	}

	// Player front Collision
	Vec2 ppos = player->pos;
	Vec2 psize = player->size;

	if ((bpos.x <= ppos.x + psize.x) && (ppos.y <= bpos.y + bsize.y && bpos.y <= ppos.y + psize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;

		if (bpos.x < ppos.x + psize.x)
			ball->pos.x += ppos.x + psize.x - bpos.x;
	}

	// Enemy front collision
	Vec2 epos = enemy->pos;
	Vec2 esize = enemy->size;

	if ((bpos.x + bsize.x >= epos.x) && (epos.y <= bpos.y + bsize.y && bpos.y <= epos.y + esize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;

		if (bpos.x > epos.x + epos.x)
			ball->pos.x -= epos.x + epos.x - bpos.x;
	}
}

void ballInit() {
	ball = calloc(1, sizeof(struct ball_s));

	ball->speed = 1.0f;
	ball->friction = 0.2f;

	ball->size = (Vec2) {8.0f, 8.0f};
	ball->pos = (Vec2) {MapWidth / 2, MapHeight / 2};
	ball->dir = (Vec2) {-1.0f, 1.0f};
	ball->vel = (Vec2) {0.0f, 0.0f};

	ball->color = WHITE;
}

void ballUpdate() {
	ball->vel.x = ball->speed * ball->dir.x;
	ball->vel.y = ball->speed * ball->dir.y;

	ball->vel.x *= (1.0f - ball->friction);
	ball->vel.y *= (1.0f - ball->friction);

	ball->pos.x += ball->vel.x;
	ball->pos.y += ball->vel.y;

	resolveCollision();

	// If collision did not work properlly
	Vec2 size = ball->size;
	ASSERT(
		!(ball->pos.x < 0
			|| ball->pos.x > MapWidth
			|| ball->pos.y > MapHeight
			|| ball->pos.y < 0),
		"Ball out of bounds\n");
}

void ballDraw(u32 pixels[]) {
	Vec2 size = ball->size, pos = ball->pos;

	for (int x = pos.x; x < (int) (pos.x + size.x); x++)
		for (int y = pos.y; y < (int) (pos.y + size.y); y++)
			pixels[(y * MapWidth) + x] = ball->color;
}
