# include "include/ball.h"
# include "include/player.h"
# include "include/enemy.h"

ball_t* ball;

extern enemy_t* enemy;
extern player_t* player;

static int frontCollision(Vec2 bpos, f32 radius) {
	// Player front Collision
	Vec2 ppos = player->pos;
	Vec2 psize = (Vec2) {player->playerW, player->playerH};

	if ((bpos.x - radius <= ppos.x + psize.x) && (ppos.y <= bpos.y + radius && bpos.y - radius <= ppos.y + psize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;
		return 1;
	}

	// Enemy front collision
	Vec2 epos = enemy->pos;
	Vec2 esize = (Vec2) {enemy->enemyW, enemy->enemyH};

	if ((bpos.x + radius >= epos.x) && (epos.y <= bpos.y + radius && bpos.y - radius <= epos.y + esize.y)) {
		ball->dir.x *= -1;
		ball->vel.x *= -1;
		return 1;
	}

	return 0;
}

static int topCollision(Vec2 bpos, f32 radius) {
	// Player top collision

	// Enemy top collision

	return 0;
}

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

	if (!topCollision(bpos, radius)) 
		frontCollision(bpos, radius);
}

void ballInit() {
	ball = calloc(1, sizeof(struct ball_s));

	ball->speed = 1.0f;
	ball->radius = 8.0f / 2.0f;
	ball->friction = 0.2f;

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

	f32 radius = ball->radius;
	ASSERT(
		!(ball->pos.x - radius / 4 < 0
			|| ball->pos.x + radius / 4 > MapWidth
			|| ball->pos.y + radius / 4 > MapHeight
			|| ball->pos.y - radius / 4 < 0),
		"Ball out of bounds\n");
}

void ballDraw(u32 pixels[]) {
	f32 radius = ball->radius;

	for (int x = ball->pos.x - radius; x < (int) (ball->pos.x + radius); x++)
		for (int y = ball->pos.y - radius; y < (int) (ball->pos.y + radius); y++)
			pixels[(y * MapWidth) + x] = ball->color;
}
