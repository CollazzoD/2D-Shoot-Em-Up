#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(SDL_Texture *texture, Bullet bullet_forge,
               std::forward_list<std::unique_ptr<Bullet>> &bullets)
    : Entity(texture, PLAYER_INITIAL_X, PLAYER_INITIAL_Y, PLAYER_SPEED),
      bullet_forge(std::move(bullet_forge)), bullets(bullets) {}

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

  if (fire)
    FireBullet();
}

void Player::Fire() {
  fire = true;
}

void Player::StopFire() {
  fire = false;
}

void Player::FireBullet() {
  auto bullet = std::make_unique<Bullet>(bullet_forge);
  bullet->SetX(this->x);
  bullet->SetY(this->y + (this->height / 2) - (bullet->GetHeight() / 2));
  bullets.push_front(std::move(bullet));
}

void Player::CheckPosition() {
  if (y < 0)
    y = 0;
  if (y > (kScreenHeight - height))
    y = kScreenHeight - height;

  if (x < 0)
    x = 0;
  if (x > (kScreenWidth - width))
    x = kScreenWidth - width;
}