#include "input.h"

void detectInput(SDL_Event& e) {
  switch (e.key.keysym.sym) {
  case SDLK_UP:
    printf("up \n");
    break;
  case SDLK_DOWN:
    printf("down \n");
    break;

  case SDLK_LEFT:
    printf("left \n");
    break;

  case SDLK_RIGHT:
    printf("right \n");
    break;
  }
}
