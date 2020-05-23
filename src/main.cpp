#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "game.h"
#include "constants.h"

int main() {
  Renderer renderer;
  Controller controller;
  Game game(renderer);
  game.Run(controller, renderer, kMsPerFrame);
  return 0;
}
