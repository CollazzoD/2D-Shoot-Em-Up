#ifndef ENEMY_H
#define ENEMY_H

#include "alienBullet.h"
#include "constants.h"
#include "entity.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <memory>
#include <random>

class Enemy : public Entity {
public:
  Enemy(Texture *texture, const float &x, const float &y, const int &speed,
        Texture *bullet_texture,
        std::list<std::unique_ptr<Entity>> &enemy_bullets,
        const Player *player);
  ~Enemy() = default;
  Enemy(const Enemy &source) = delete;
  Enemy &operator=(const Enemy &source) = delete;
  Enemy(Enemy &&source) = default;
  Enemy &operator=(Enemy &&source) = default;

  void Update() override;

private:
  void CheckPosition();
  void Fire();
  void CalcSlope(float &dx, float &dy);

  float bullet_dx;
  float bullet_dy;
  const Player *player;

  Texture *bullet_texture; // used to create other bullets
  std::list<std::unique_ptr<Entity>> &enemy_bullets;
  int reload;
};

#endif