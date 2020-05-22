#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(SDL_Texture *texture, Bullet bullet_forge,
               std::list<std::unique_ptr<Bullet>> &bullets)
    : Entity(texture, PLAYER_INITIAL_X, PLAYER_INITIAL_Y, PLAYER_SPEED),
      bullet_forge(std::move(bullet_forge)), bullets(bullets), reload(0) {}

void Player::Init() {
  x = PLAYER_INITIAL_X;
  y = PLAYER_INITIAL_Y;
  speed = PLAYER_SPEED;
  reload = 0;
}

void Player::Update() {

  dx = dy = 0;

  if (reload > 0)
    reload--;
  switch (direction) {
  case Direction::kUp:
    dy = -speed;
    break;

  case Direction::kDown:
    dy = speed;
    break;

  case Direction::kLeft:
    dx = -speed;
    break;

  case Direction::kRight:
    dx = speed;
    break;

  case Direction::kStop:
    break;
  }

  x += dx;
  y += dy;
  CheckPosition();

  if (fire && (reload == 0))
    FireBullet();
}

void Player::Fire() { fire = true; }

void Player::StopFire() { fire = false; }

void Player::FireBullet() {
  if (health > 0) {
    auto bullet = std::make_unique<Bullet>(bullet_forge);
    bullet->SetX(this->x);
    bullet->SetY(this->y + (this->height / 2) - (bullet->GetHeight() / 2));
    bullets.push_front(std::move(bullet));
    reload = 8;
  }
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