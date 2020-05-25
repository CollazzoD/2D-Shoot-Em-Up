#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"

/*
 * Class Controller handles all the input from keyboard and update the Player's Spaceship accordingly
*/
class Controller {
public:
  // Handles all the input
  void HandleInput(bool &running, bool &playing, Player *player) const;
  void HandleInput(bool &running, bool &playing) const;

private:
  // Handles the input when any key on the keyboard is released
  void doKeyUp(Player *player, const SDL_Keycode& key) const;
  // Handles the input when any key on the keyboard is pressed
  void doKeyDown(Player *player, const SDL_Keycode& key, bool &playing) const;
};

#endif