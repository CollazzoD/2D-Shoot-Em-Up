#include "entity.h"
#include <iostream>

Entity::Entity(Texture *texture, const float &x, const float &y,
               const int &speed, const float &dx, const float &dy,
               const int &health)
    : texture(texture), x(x), y(y), speed(speed), dx(dx), dy(dy), health(health),
      width(0), height(0) {
  if (texture != nullptr) {
    width = texture->GetTextureWidth();
    height = texture->GetTextureHeight();
  }
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