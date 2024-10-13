# include "include/ball.h"
# include "include/player.h"
# include "include/enemy.h"

ball_t* ball;

extern enemy_t* enemy;
extern player_t* player;

static void resolveCollision() {
	Vec2 bpos = ball->pos;
	f32 radius = ball->radius;

	// Window edge collision
	if (bpos.y + radius > MapHeight) {
		ball->pos.y = MapHeight - radius;
		ball->vel.y *= -1;
		ball->dir.y *= -1;
	}

	if (bpos.y - radius < 0) {
		ball->pos.y = radius;
		ball->vel.y *= -1;
		ball->dir.y *= -1;
	}

	// Player collision
	Vec2 ppos = player->pos;
	Vec2 psize = (Vec2) {player->playerW, player->playerH};

	if ((bpos.x - radius <= ppos.x + psize.x && bpos.x - radius >= ppos.x) && (ppos.y <= bpos.y + radius && bpos.y - radius <= ppos.y + psize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;
	}

	// Enemy collision
	Vec2 epos = enemy->pos;
	Vec2 esize = (Vec2) {enemy->enemyW, enemy->enemyH};

	if ((bpos.x + radius >= epos.x) && (epos.y <= bpos.y + radius && bpos.y - radius <= epos.y + esize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;
	}
}

void ballInit() {
	ball = calloc(1, sizeof(struct ball_s));

	ball->speed = 1.0f;
	ball->radius = 8.0f / 2.0f;
	ball->friction = 0.6f;

	ball->pos = (Vec2) {MapWidth / 2, MapHeight / 2};
	ball->dir = (Vec2) {-1.0f, 1.0f};
	ball->vel = (Vec2) {0.0f, 0.0f};

	ball->color = 0xFFFFFFFF;
}

void ballUpdate() {
	ball->vel.x = ball->speed * ball->dir.x;
	ball->vel.y = ball->speed * ball->dir.y;

	ball->vel.x *= (1.0f - ball->friction);
	ball->vel.y *= (1.0f - ball->friction);

	ball->pos.x += ball->vel.x;
	ball->pos.y += ball->vel.y;

	resolveCollision();
}

void ballDraw(u32 pixels[]) {
	for (int x = ball->pos.x - ball->radius; x < (int) (ball->pos.x + ball->radius); x++)
		for (int y = ball->pos.y - ball->radius; y < (int) (ball->pos.y + ball->radius); y++)
			pixels[(y * MapWidth) + x] = ball->color;
}
