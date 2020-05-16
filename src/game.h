#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "controller.h"
#include "renderer.h"
#include "player.h"

class Game {
 public:
  Game();
  void Run(std::size_t target_frame_duration);
  
 private:
  Renderer renderer;
  Controller controller;
  Player player;
};

#endif