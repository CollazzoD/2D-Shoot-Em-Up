#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(Renderer &r) : Entity(PLAYER_INITIAL_X, PLAYER_INITIAL_Y, PLAYER_SPEED) {
  texture = r.LoadTexture("../gfx/player.png");
  if (texture == NULL)
    std::cerr << "Unable to load Player's texture\n";
  else {
    SDL_Rect dest;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    texture_height = dest.h;
    texture_width = dest.w;
  }
}

Player::~Player() {
  if (texture != NULL)
    SDL_DestroyTexture(texture);
}

Player::Player(Player &&source) : Entity(source.x, source.y, source.speed) {
  texture = source.texture;
  source.texture = NULL;
  direction = source.direction;
  texture_width = source.texture_width;
  texture_height = source.texture_height;
}

Player &Player::operator=(Player &&source) {
  if (this == &source)
    return *this;

  if (texture != NULL)
    SDL_DestroyTexture(texture);

  x = source.x;
  y = source.y;
  speed = source.speed;
  texture = source.texture;
  source.texture = NULL;
  direction = source.direction;
  texture_width = source.texture_width;
  texture_height = source.texture_height;
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
  UpdatePosition();
}

void Player::UpdatePosition() {
  if (y < 0)
    y = 0;
  if (y > (kScreenHeight - texture_height))
    y = kScreenHeight - texture_height;

  if (x < 0)
    x = 0;
  if (x > (kScreenWidth - texture_width))
    x = kScreenWidth - texture_width;
}