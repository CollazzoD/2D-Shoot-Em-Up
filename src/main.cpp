#include <iostream>
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};

  Renderer renderer(kScreenWidth, kScreenHeight);
  char c;
  std::cin >> c; 
  return 0;
}
