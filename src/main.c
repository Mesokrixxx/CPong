# include "include/main.h"
# include "include/player.h"
# include "include/enemy.h"
# include "include/ball.h"

struct MAIN_S {
	SDL_Window* window;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	u32 pixels[MapWidth * MapHeight];

	Bool quit;
} state;

static void init() {
	ballInit();
	enemyInit();
	playerInit();
}

static void update() {
	ballUpdate();
	enemyUpdate();
	playerUpdate();
}

static void render() {
	ballDraw(state.pixels);
	enemyDraw(state.pixels);
	playerDraw(state.pixels);
}

int main(int argc, char *argv[]) {
	ASSERT(
		!SDL_Init(SDL_INIT_VIDEO),
		"Failed to initialize SDL: %s\n",
		SDL_GetError());

	state.window = 
		SDL_CreateWindow(
			"C PONG",
			SDL_WINDOWPOS_CENTERED_DISPLAY(1), SDL_WINDOWPOS_CENTERED_DISPLAY(1),
			WindowWidth, WindowHeight,
			SDL_WINDOW_ALLOW_HIGHDPI);
	ASSERT(state.window, "Failed to create SDL window: %s\n", SDL_GetError());

	state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_PRESENTVSYNC);
	ASSERT(state.renderer, "Failed to create SDL renderer: %s\n", SDL_GetError());

	state.texture = 
		SDL_CreateTexture(
			state.renderer,
			SDL_PIXELFORMAT_ABGR8888,
			SDL_TEXTUREACCESS_STREAMING,
			MapWidth, MapHeight);
	ASSERT(state.texture, "Failed to create SDL texture: %s\n", SDL_GetError());

	init();
	while (!state.quit) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					state.quit = true;
					break; 
			}
		}

		const u8 *keyState = SDL_GetKeyboardState(NULL);

		if (keyState[SDL_SCANCODE_ESCAPE])
			state.quit = true;

		memset(state.pixels, 0, sizeof(state.pixels));

		update();
		render();

		SDL_UpdateTexture(state.texture, NULL, state.pixels, MapWidth * 4);
		SDL_RenderCopyEx(
			state.renderer,
			state.texture,
			NULL, NULL,
			0.0,
			NULL,
			SDL_FLIP_VERTICAL);
		SDL_RenderPresent(state.renderer);
	}

	SDL_DestroyTexture(state.texture);
	SDL_DestroyRenderer(state.renderer);
	SDL_DestroyWindow(state.window);
	return 0;
}