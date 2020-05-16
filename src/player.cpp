#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(Renderer &r) : x(100), y(100), speed(4) {
  texture = r.loadTexture("../gfx/player.png");
  if (texture == NULL)
    std::cerr << "Unable to load Player's texture\n";
}

Player::~Player() {
  if (texture != NULL)
    SDL_DestroyTexture(texture);
}

Player::Player(Player &&source) {
  x = source.x;
  y = source.y;
  texture = source.texture;
  source.texture = NULL;
}

Player &Player::operator=(Player &&source) {
  if (this == &source)
    return *this;

  if (texture != NULL)
    SDL_DestroyTexture(texture);

  x = source.x;
  y = source.y;
  texture = source.texture;
  source.texture = NULL;
  return *this;
}

void Player::Update() {
  switch (direction) {
  case Direction::kUp:
    y -= speed;
    break;

  case Direction::kDown:
    y += speed;
    break;

  case Direction::kLeft:
    x -= speed;
    break;

  case Direction::kRight:
    x += speed;
    break;

  case Direction::kStop:
    break;
  }
}