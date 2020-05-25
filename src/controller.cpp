#include "controller.h"
#include <SDL2/SDL.h>
#include <iostream>

void Controller::doKeyUp(Player *player, const SDL_Keycode &key) const {
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

  if (state[SDL_SCANCODE_SPACE])
    player->Fire();
  else
    player->StopFire();
}

void Controller::doKeyDown(Player *player, const SDL_Keycode &key, bool &playing) const {
  const Uint8 *state = SDL_GetKeyboardState(NULL);
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
  }

  if (state[SDL_SCANCODE_ESCAPE])
    playing = false;

  if (state[SDL_SCANCODE_SPACE])
    player->Fire();
  else
    player->StopFire();
}

void Controller::HandleInput(bool &running, bool &playing, Player *player) const {
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
      doKeyDown(player, e.key.keysym.sym, playing);
      break;
    }
  }
}

void Controller::HandleInput(bool &running, bool &playing) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      running = false;
      break;

    default:
      if (e.key.keysym.sym == SDLK_SPACE)
        playing = true;
      break;
    }
  }
}