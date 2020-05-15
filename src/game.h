#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "controller.h"
#include "renderer.h"

class Game {
 public:
  Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  
 private:
  
};

#endif