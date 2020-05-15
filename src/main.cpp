#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{1280};
  constexpr std::size_t kScreenHeight{720};

  Controller controller;
  Renderer renderer(kScreenWidth, kScreenHeight);
  Game game;
  game.Run(controller, renderer, kMsPerFrame);
  return 0;
}
