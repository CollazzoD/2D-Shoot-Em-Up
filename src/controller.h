#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"

/*
 * Class Controller handles all the input from keyboard and update the Player's Spaceship accordingly
*/
class Controller {
public:
  void HandleInput(bool &running, Player *player) const;

private:
  void doKeyUp(Player *player, const SDL_Keycode& key) const;
  void doKeyDown(Player *player, const SDL_Keycode& key) const;
};

#endif