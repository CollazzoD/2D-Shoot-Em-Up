#include "controller.h"
#include <iostream>
#include <SDL2/SDL.h>

void Controller::HandleInput(bool &running) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          break;

        case SDLK_DOWN:
          break;

        case SDLK_LEFT:
          break;

        case SDLK_RIGHT:
          break;
      }
    }
  }
}