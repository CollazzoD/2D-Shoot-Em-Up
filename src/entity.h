#ifndef ENTITY_H
#define ENTITY_H

#include "texture.h"
#include <string>
#include <SDL2/SDL.h>

class Entity {
public:
  Entity(Texture* texture, const float &x, const float &y, const int &speed);
  Entity(Texture* texture, const float &x, const float &y, const int &speed, const float &dx, const float &dy);
  ~Entity();
  Entity(const Entity &source) = default;
  Entity &operator=(const Entity &source) = default;
  Entity(Entity &&source);
  Entity &operator=(Entity &&source);

  int GetWidth() const {return width;}
  int GetHeight() const {return height;}
  float GetX() const {return x;}
  float GetY() const {return y;}
  int GetHealth() const {return health;}
  Texture* GetTexture() const {return texture;}

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