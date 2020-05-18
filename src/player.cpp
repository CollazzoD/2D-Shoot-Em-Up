#include "player.h"
#include <iostream>

// Renderer is needed in order to load the texture
Player::Player(SDL_Texture *texture)
    : Entity( texture, PLAYER_INITIAL_X, PLAYER_INITIAL_Y,
             PLAYER_SPEED) {}

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

// void Player::Fire() {
//   if (bullet != nullptr) {
//     if (bullet->health == 0) {
//       bullet->health = 1;
//       bullet->x = this->x;
//       bullet->y = this->y;
//       bullet->y += (this->texture_height / 2) - (bullet->GetTextureHeight() / 2);
//     }
//   } else {
//     bullet = std::make_unique<Bullet>(renderer, this->x, this->y);
//     bullet->y += (this->texture_height / 2) - (bullet->GetTextureHeight() / 2);
//   }
// }

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