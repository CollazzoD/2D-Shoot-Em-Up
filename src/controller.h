#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"

class Controller {
public:
  void HandleInput(bool &running, Player &player) const;

private:
  void doKeyUp(Player &player, const SDL_Keycode& key) const;
  void doKeyDown(Player &player, const SDL_Keycode& key) const;
};

#endif