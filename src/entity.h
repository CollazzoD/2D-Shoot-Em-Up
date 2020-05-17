#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

class Entity {
public:
  Entity(int x, int y, int speed) : x(x), y(y), speed(speed), texture(NULL) {};

  int x;
  int y;
  int speed;
  SDL_Texture *texture;

  virtual void Update() = 0;

private:
  virtual void UpdatePosition() = 0;
};

#endif