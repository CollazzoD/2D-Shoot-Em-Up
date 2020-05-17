#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(Renderer &r)
    : Entity(r, "../gfx/player.png", PLAYER_INITIAL_X, PLAYER_INITIAL_Y,
             PLAYER_SPEED), renderer(r), bullet(nullptr) {}

Player::Player(Player &&source) : Entity(std::move(source)), renderer(source.renderer) {
  direction = source.direction;
  bullet = std::move(source.bullet);
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
  renderer = std::move(source.renderer);
  bullet = std::move(source.bullet);
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
  UpdateBullet();
  UpdatePosition();
}

void Player::UpdateBullet() {
  if ((bullet != nullptr) && (bullet->health == 1)) {
    bullet->Update();
  }
}

void Player::Fire() {
  if (bullet != nullptr) {
    if (bullet->health == 0) {
      bullet->health = 1;
      bullet->x = this->x;
      bullet->y = this->y;
    }
  } else {
    bullet = std::make_unique<Bullet>(renderer, this->x, this->y);
  }
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