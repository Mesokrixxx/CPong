# include "include/player.h"

player_t* player;

static void resolveCollision() {
	Vec2 size = player->size, pos = player->pos;

	if (pos.y + size.y > MapHeight) {
		player->pos.y = MapHeight - size.y;
		player->vel.y *= -1;
	}

	if (pos.y < 0) {
		player->pos.y = 0;
		player->vel.y *= -1;
	}
}

void playerInit() {
	player = calloc(1, sizeof(struct player_s));

	player->acceleration = 2.0f;
	player->friction = 0.3f;

	player->size = (Vec2) {8.0f, 32.0f};
	player->pos = (Vec2) {3.0f, 1.0f};
	player->vel = (Vec2) {0.0f, 0.0f};

	player->color = WHITE;
}

void playerUpdate() {
	const u8 *keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_W])
		player->vel.y += player->acceleration;
	if (keyState[SDL_SCANCODE_S])
		player->vel.y -= player->acceleration;

	player->vel.y *= (1.0f - player->friction);

	player->pos.y += player->vel.y;

	resolveCollision();

	// If collision did not work properlly
	Vec2 size = player->size;
	ASSERT(
		!(player->pos.y + size.y / 2 < 0
			|| player->pos.y - size.y / 2 > MapHeight),
		"Player out of bounds\n");
}

void playerDraw(u32 pixels[]) {
	Vec2 size = player->size, pos = player->pos;

	for (int x = pos.x; x < (int) (pos.x + size.x); ++x)
		for (int y = pos.y; y < (int) (pos.y + size.y); ++y) 
			pixels[(y * MapWidth) + x] = player->color;
}
