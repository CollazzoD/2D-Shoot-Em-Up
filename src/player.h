#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "renderer.h"
#include "bullet.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <forward_list>

constexpr int PLAYER_SPEED{4};
constexpr int PLAYER_INITIAL_X{100};
constexpr int PLAYER_INITIAL_Y{330};

class Player : public Entity {
public:
  Player(SDL_Texture *texture, SDL_Texture *bullet_texture,
         std::forward_list<std::unique_ptr<Bullet>> &bullets);
  ~Player() = default;
  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source) = default;
  Player &operator=(Player &&source) = default;

  void Update() override;
  void Fire();

  enum class Direction { kUp, kDown, kLeft, kRight, kStop };
  Direction direction = Direction::kStop;

private:
  SDL_Texture *bullet_texture;
  std::forward_list<std::unique_ptr<Bullet>> &bullets;
  void UpdatePosition();
};

#endif