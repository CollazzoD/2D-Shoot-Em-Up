#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(SDL_Texture *texture, SDL_Texture *bullet_texture,
               std::forward_list<std::unique_ptr<Bullet>> &bullets)
    : Entity(texture, PLAYER_INITIAL_X, PLAYER_INITIAL_Y, PLAYER_SPEED),
      bullet_texture(bullet_texture), bullets(bullets) {}

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

// void Player::UpdateBullet() {
//   if ((bullet != nullptr) && (bullet->health == 1)) {
//     bullet->Update();
//   }
// }

void Player::Fire() {
  auto bullet_y = y + (this->texture_height / 2);
  auto bullet = std::make_unique<Bullet>(bullet_texture, x, y);
  bullets.push_front(std::move(bullet));
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