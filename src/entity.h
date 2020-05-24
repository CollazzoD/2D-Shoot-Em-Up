#ifndef ENTITY_H
#define ENTITY_H

#include "texture.h"
#include <SDL2/SDL.h>
#include <string>

class Entity {
public:
  Entity(Texture *texture, const float &x = 0, const float &y = 0,
         const int &speed = 0, const float &dx = 0, const float &dy = 0, const int &health = 1);
  ~Entity();
  Entity(const Entity &source) = default;
  Entity &operator=(const Entity &source) = default;
  Entity(Entity &&source);
  Entity &operator=(Entity &&source);

  int GetWidth() const { return width; }
  int GetHeight() const { return height; }
  float GetX() const { return x; }
  float GetY() const { return y; }
  int GetHealth() const { return health; }
  Texture *GetTexture() const { return texture; }

  virtual void Update() = 0;
  void Hit();

protected:
  float x;
  float y;
  float dx;
  float dy;
  int speed;
  int health;
  int width;
  int height;
  Texture *texture;
};

#endif