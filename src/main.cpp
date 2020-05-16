#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"

// TODO Implement Rule of five
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  Game game;
  game.Run(kMsPerFrame);
  return 0;
}
