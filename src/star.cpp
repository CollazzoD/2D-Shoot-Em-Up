#include "star.h"

Stars::Stars() : stars(MAX_STARS) {
  engine = std::mt19937(dev());
  x_random_pos = std::uniform_int_distribution<int>(0, kScreenWidth);
  y_random_pos = std::uniform_int_distribution<int>(0, kScreenHeight);
  speed_random = std::uniform_int_distribution<int>(0, MAX_STAR_SPEED);
  InitStars();
}

void Stars::Update() {
  for (auto &star : stars) {
    star.x -= star.speed;
    if (star.x < 0)
      star.x += kScreenWidth;
  }
}

void Stars::InitStars() {
  for (auto &star : stars) {
    star.x = x_random_pos(engine);
    star.y = y_random_pos(engine);
    star.speed = speed_random(engine);
  }
}