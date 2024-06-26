#include "main.h"
#include "input.h"

#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// The window we'll be rendering to
SDL_Window *window = NULL;

// The surface contained by the window
SDL_Surface *screenSurface = NULL;

bool init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Failed to initialize the SDL2 library. SDL_Erorr: %s\n",
           SDL_GetError());
    return false;
  }

  return true;
}

bool createWindow() {
  // Create window
  window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void createSurface() {
  // Get window surface
  screenSurface = SDL_GetWindowSurface(window);
}

void draw() {
  // Fill the surface white
  SDL_FillRect(screenSurface, NULL,
               SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

  // Update the surface
  SDL_UpdateWindowSurface(window);
}

void exit() {
  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  printf("Goodbye!");
}

int main(int argc, char *args[]) {
  if (!init() || !createWindow())
    return -1;

  createSurface();

  draw();

  // Hack to get window to stay up
  SDL_Event e;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
        break;
      } else if (e.type == SDL_KEYDOWN) {
        detectInput(e);
      }
    }
  }

  exit();

  return 0;
}
