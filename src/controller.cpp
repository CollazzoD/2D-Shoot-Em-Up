#include "controller.h"
#include <SDL2/SDL.h>
#include <iostream>

void Controller::doKeyUp(Player *player, const SDL_Keycode& key) const {
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_UP])
    player->direction = Player::Direction::kUp;
  else if (state[SDL_SCANCODE_DOWN])
    player->direction = Player::Direction::kDown;
  else if (state[SDL_SCANCODE_LEFT])
    player->direction = Player::Direction::kLeft;
  else if (state[SDL_SCANCODE_RIGHT])
    player->direction = Player::Direction::kRight;
  else
    player->direction = Player::Direction::kStop;
}

void Controller::doKeyDown(Player *player, const SDL_Keycode& key) const {
  switch (key) {
    case SDLK_UP:
      player->direction = Player::Direction::kUp;
      break;

    case SDLK_DOWN:
      player->direction = Player::Direction::kDown;
      break;

    case SDLK_LEFT:
      player->direction = Player::Direction::kLeft;
      break;

    case SDLK_RIGHT:
      player->direction = Player::Direction::kRight;
      break;

    case SDLK_SPACE:
      player->Fire();
      break;
  }
}

void Controller::HandleInput(bool &running, Player *player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      running = false;
      break;

    case SDL_KEYUP:
      doKeyUp(player, e.key.keysym.sym);
      break;

    case SDL_KEYDOWN:
      doKeyDown(player, e.key.keysym.sym);
      break;
    }
  }
}