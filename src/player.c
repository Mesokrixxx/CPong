# include "include/player.h"

struct {
	// Utils
	u32 playerW, playerH;
	f32 acceleration, friction; 
	Vec2 pos, vel;
	// Graphics
	u32 color;
} player;

static void resolveCollision() {
	if (player.pos.y + player.playerH > MapHeight) {
		player.pos.y = MapHeight - player.playerH;
		player.vel.y *= -1;
	}

	if (player.pos.y < 0) {
		player.pos.y = 0;
		player.vel.y *= -1;
	}
}

void playerInit() {
	player.playerW = 8;
	player.playerH = 32;

	player.acceleration = 2.0f;
	player.friction = 0.3f;

	player.pos = (Vec2) {3.0f, 1.0f};
	player.vel = (Vec2) {0.0f, 0.0f};

	player.color = 0xFFFFFFFF;
}

void playerUpdate() {
	const u8 *keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_W])
		player.vel.y += player.acceleration;
	if (keyState[SDL_SCANCODE_S])
		player.vel.y -= player.acceleration;

	player.vel.y *= (1.0f - player.friction);

	player.pos.y += player.vel.y;

	resolveCollision();
}

void playerDraw(u32 pixels[]) {
	for (int x = player.pos.x; x < (int) (player.pos.x + player.playerW); ++x)
		for (int y = player.pos.y; y < (int) (player.pos.y + player.playerH); ++y) 
			pixels[(y * MapWidth) + x] = player.color;
}