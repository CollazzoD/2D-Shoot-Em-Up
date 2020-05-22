#include "entity.h"
#include <iostream>

Entity::Entity(SDL_Texture *texture, const int &x, const int &y,
               const int &speed)
    : texture(texture), x(x), y(y), speed(speed), dx(0), dy(0), health(1) {
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
};

Entity::Entity(SDL_Texture *texture, const int &x, const int &y,
               const int &speed, const float &dx, const float &dy)
    : texture(texture), x(x), y(y), speed(speed), dx(dx), dy(dy), health(1) {
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
};

Entity::~Entity() {}

Entity::Entity(Entity &&source) {
  x = source.x;
  y = source.y;
  dx = source.dx;
  dy = source.dy;
  speed = source.speed;
  texture = source.texture;
  source.texture = NULL;
  width = source.width;
  height = source.height;
  health = source.health;
}

Entity &Entity::operator=(Entity &&source) {
  if (this == &source)
    return *this;

  x = source.x;
  y = source.y;
  dx = source.dx;
  dy = source.dy;
  speed = source.speed;
  texture = source.texture;
  source.texture = NULL;
  width = source.width;
  height = source.height;
  health = source.health;
  return *this;
}

void Entity::Hit() { health--; }