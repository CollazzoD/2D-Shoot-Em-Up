#ifndef STAR_H
#define STAR_H

#include "constants.h"
#include <random>
#include <vector>

class Stars {
public:
  struct Star {
    int x;
    int y;
    int speed;
  };

  Stars();
  void InitStars();
  void Update();

  std::vector<Star> stars;

private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> x_random_pos;
  std::uniform_int_distribution<int> y_random_pos;
  std::uniform_int_distribution<int> speed_random;
};

#endif