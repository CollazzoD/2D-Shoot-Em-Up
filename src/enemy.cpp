#include "enemy.h"
#include <iostream>

Enemy::Enemy(SDL_Texture *texture, const int &x, const int &y, const int &speed,
             AlienBullet bullet_forge,
             std::list<std::unique_ptr<AlienBullet>> &enemy_bullets,
             const Player *player)
    : Entity(texture, x, y, speed), bullet_forge(std::move(bullet_forge)),
      enemy_bullets(enemy_bullets), reload(ENEMY_RELOAD), player(player) {
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
  float dx, dy;
  CalcSlope(dx, dy);
  dx *= ALIEN_BULLET_SPEED;
  dy *= ALIEN_BULLET_SPEED;

  // I shoot the player only if he's alive and not behind me
  if ((player->GetHealth() > 0) && (dx < 0)) {
    auto bullet = std::make_unique<AlienBullet>(bullet_forge);
    bullet->SetX(this->x);
    bullet->SetY(this->y + (this->height / 2) - (bullet->GetHeight() / 2));
    bullet->SetDx(dx);
    bullet->SetDy(dy);
    enemy_bullets.push_front(std::move(bullet));
  }
  reload = ENEMY_RELOAD;
}

void Enemy::CheckPosition() {
  if (x < -width)
    health = 0;
}

void Enemy::CalcSlope(float &dx, float &dy) {
  int x1 = player->GetX() + (player->GetWidth() / 2);
  int y1 = player->GetY() + (player->GetHeight() / 2);

  int steps = std::max(std::abs(x1 - x), std::abs(y1 - y));

  if (steps == 0) {
    dx = dy = 0;
    return;
  }

  dx = (x1 - x);
  dx /= steps;

  dy = (y1 - y);
  dy /= steps;
}