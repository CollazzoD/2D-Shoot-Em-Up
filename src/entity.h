#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <SDL2/SDL.h>

class Entity {
public:
  Entity(SDL_Texture* texture, const int &x, const int &y, const int &speed);
  Entity(SDL_Texture* texture, const int &x, const int &y, const int &speed, const float &dx, const float &dy);
  ~Entity();
  Entity(const Entity &source) = default;
  Entity &operator=(const Entity &source) = default;
  Entity(Entity &&source);
  Entity &operator=(Entity &&source);

  int GetWidth() const {return width;}
  int GetHeight() const {return height;}
  int GetX() const {return x;}
  int GetY() const {return y;}
  int GetHealth() const {return health;}
  SDL_Texture* GetTexture() const {return texture;}

  virtual void Update() = 0;
  void Hit();
protected:
  int x;
  int y;
  float dx;
  float dy;
  int speed;
  int health;
  int width;
  int height;
  SDL_Texture *texture;
};

#endif