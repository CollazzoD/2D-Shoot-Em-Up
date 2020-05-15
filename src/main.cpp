#include <iostream>
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{1280};
  constexpr std::size_t kScreenHeight{720};

  Renderer renderer(kScreenWidth, kScreenHeight);
  char c;
  std::cin >> c; 
  return 0;
}
