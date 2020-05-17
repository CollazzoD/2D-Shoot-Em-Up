#include "entity.h"
#include <iostream>

Entity::Entity(Renderer &r, const std::string &texture_image, const int &x,
               const int &y, const int &speed)
    : x(x), y(y), speed(speed), dx(0), dy(0), health(1), texture(NULL) {
  texture = r.LoadTexture(texture_image.c_str());
  if (texture == NULL)
    std::cerr << "Unable to load Entity's texture " << texture_image << "\n";
  else {
    SDL_Rect dest;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    texture_height = dest.h;
    texture_width = dest.w;
  }
};

Entity::~Entity() {
  if (texture != NULL)
    SDL_DestroyTexture(texture);
}

Entity::Entity(Entity &&source) {
  x = source.x;
  y = source.y;
  dx = source.dx;
  dy = source.dy;
  speed = source.speed;
  texture = source.texture;
  source.texture = NULL;
  texture_width = source.texture_width;
  texture_height = source.texture_height;
  health = source.health;
}

Entity &Entity::operator=(Entity &&source) {
  if (this == &source)
    return *this;

  if (texture != NULL)
    SDL_DestroyTexture(texture);

  x = source.x;
  y = source.y;
  dx = source.dx;
  dy = source.dy;
  speed = source.speed;
  texture = source.texture;
  source.texture = NULL;
  texture_width = source.texture_width;
  texture_height = source.texture_height;
  health = source.health;
  return *this;
}
