#include <stdio.h>
#include <switch.h>
#include <time.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int main() {

  // Initialize
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	romfsInit();

  // Create an SDL window & renderer
  SDL_Window* window = SDL_CreateWindow("Main-Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	// Create bg texture:
	SDL_Surface* bg_surface = IMG_Load("romfs:/resources/images/main.png");			// Read image as surface
	SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);	// Create texture from surface

	// Create font:
	TTF_Font* font = TTF_OpenFont("romfs:/resources/fonts/small_font.ttf", 24);
	SDL_Color color = {0, 0, 0};

	// Clear renderer:
	SDL_RenderClear(renderer);

	// Copy bg texture to renderer:
	SDL_RenderCopy(renderer, bg_texture, NULL, NULL);

	// Create text texture
	SDL_Surface* txt_surface = TTF_RenderText_Solid(font, "test", color);
	SDL_Texture* txt_texture = SDL_CreateTextureFromSurface(renderer, txt_surface);
	SDL_Rect txt_rect;
	txt_rect.x = 10;
	txt_rect.y = 10;
	txt_rect.w = txt_surface->w;
	txt_rect.h = txt_surface->h;

	// Copy text texture to renderer:
	SDL_RenderCopy(renderer, txt_texture, NULL, &txt_rect);

	// Render
	SDL_RenderPresent(renderer);						// Render renderer

	// Game loop:
	while (appletMainLoop()) {
    hidScanInput();
    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    if(kDown & KEY_PLUS) break;

	}

  SDL_Quit();				// SDL cleanup
	return EXIT_SUCCESS; 	// Clean exit to HBMenu
}
