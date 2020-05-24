#ifndef GAME_H
#define GAME_H


#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "alienBullet.h"
#include "texture.h"
#include "star.h"
#include "constants.h"
#include "explosion.h"
#include "debris.h"
#include <SDL2/SDL.h>
#include <memory>
#include <list>

class Game {
public:
  Game(Renderer &renderer);
  ~Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> enemy_random_pos;
  std::uniform_int_distribution<int> enemy_random_speed;
  std::uniform_int_distribution<int> zero_to_4;
  std::uniform_int_distribution<int> zero_to_10;
  std::uniform_int_distribution<int> zero_to_32;
  std::uniform_int_distribution<int> zero_to_fps;

  // I create the textures only once, so as to refer to the same texture
  std::unique_ptr<Texture> player_texture;
  std::unique_ptr<Texture> bullet_texture;
  std::unique_ptr<Texture> enemy_texture;
  std::unique_ptr<Texture> enemy_bullet_texture;
  std::unique_ptr<Texture> explosion_texture;

  std::unique_ptr<Player> player;
  std::list<std::unique_ptr<Entity>> bullets;
  std::list<std::unique_ptr<Entity>> enemies;
  std::list<std::unique_ptr<Entity>> enemies_bullets;
  std::list<std::unique_ptr<Explosion>> explosions;
  std::list<std::unique_ptr<Entity>> space_debris;

  Stars game_stars;
  
  int enemy_spawn_timer{ENEMY_SPAWN_TIMER};
  int reset_stage_timer{RESET_STAGE_TIMER};
  int score{0};
  
  void Update();
  void UpdateEntities(std::list<std::unique_ptr<Entity>> &list);
  void UpdateEntities(std::list<std::unique_ptr<Explosion>> &list);

  void SpawnEnemy();
  void CheckCollision();
  bool Collision(const Entity* e1, const Entity* e2);
  void ResetStage();
  void RenderGameEntities(Renderer &renderer);
  void AddExplosions(const int &x, const int &y, const int &num);
};

#endif