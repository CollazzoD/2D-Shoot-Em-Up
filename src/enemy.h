#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "player.h"
#include "alienBullet.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <memory>
#include <random>

class Enemy : public Entity {
public:
  Enemy(SDL_Texture *texture, const int &x, const int &y, const int &speed,
        AlienBullet bullet_forge,
        std::list<std::unique_ptr<AlienBullet>> &enemy_bullets, const Player* player);
  ~Enemy() = default;
  Enemy(const Enemy &source) = delete;
  Enemy &operator=(const Enemy &source) = delete;
  Enemy(Enemy &&source) = default;
  Enemy &operator=(Enemy &&source) = default;

  void Update() override;
  void TargetPosition(Entity* e);

private:
  void CheckPosition();
  void Fire();
  void CalcSlope(float &dx, float &dy);

  int bullet_dx;
  int bullet_dy;
  const Player* player;

  AlienBullet bullet_forge; // used to create other bullets
  std::list<std::unique_ptr<AlienBullet>> &enemy_bullets;
  int reload;
};

#endif