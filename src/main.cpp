#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  Renderer renderer;
  Controller controller;
  Game game(renderer);
  game.Run(controller, renderer, kMsPerFrame);
  return 0;
}
