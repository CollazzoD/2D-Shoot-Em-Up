#include "enemy.h"
#include <iostream>

Enemy::Enemy(SDL_Texture *texture, const int &x, const int &y, const int &speed,
             AlienBullet bullet_forge,
             std::list<std::unique_ptr<AlienBullet>> &enemy_bullets)
    : Entity(texture, x, y, speed), bullet_forge(std::move(bullet_forge)),
      enemy_bullets(enemy_bullets), reload(ENEMY_RELOAD) {
  dx = -speed;
}

void Enemy::Update() {
  if (reload > 0)
    reload--;

  x += dx;
  y += dy;
  CheckPosition();

  if (reload == 0)
    Fire();
}

void Enemy::Fire() {
  auto bullet = std::make_unique<AlienBullet>(bullet_forge);
  bullet->SetX(this->x);
  bullet->SetY(this->y + (this->height / 2) - (bullet->GetHeight() / 2));
  enemy_bullets.push_front(std::move(bullet));
  reload = ENEMY_RELOAD;
}

void Enemy::CheckPosition() {
  if (x < - width)
    health = 0;
}