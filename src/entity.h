#ifndef ENTITY_H
#define ENTITY_H

#include "renderer.h"
#include <string>
#include <SDL2/SDL.h>

class Entity {
public:
  Entity(Renderer& r, const std::string &texture_image, const int &x, const int &y, const int &speed);
  ~Entity();
  Entity(const Entity &source) = delete;
  Entity &operator=(const Entity &source) = delete;
  Entity(Entity &&source);
  Entity &operator=(Entity &&source);

  int x;
  int y;
  int dx;
  int dy;
  int speed;
  int health;
  SDL_Texture *texture;

  virtual void Update() = 0;
  int GetTextureWidth() {return texture_width;}
  int GetTextureHeight() {return texture_height;}

protected:
  virtual void UpdatePosition() = 0;
  int texture_width;
  int texture_height;
};

#endif