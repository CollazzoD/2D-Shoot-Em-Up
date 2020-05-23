#ifndef GAME_H
#define GAME_H


#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "alienBullet.h"
#include "texture.h"
#include <SDL2/SDL.h>
#include <memory>
#include <list>

constexpr int ENEMY_SPAWN_TIMER = 120;
constexpr int RESET_STAGE_TIMER = 300;

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

  // I create the textures only once, so as to refer to the same texture
  std::unique_ptr<Texture> player_texture;
  std::unique_ptr<Texture> bullet_texture;
  std::unique_ptr<Texture> enemy_texture;
  std::unique_ptr<Texture> enemy_bullet_texture;

  std::unique_ptr<Player> player;
  std::list<std::unique_ptr<Bullet>> bullets;
  std::list<std::unique_ptr<Enemy>> enemies;
  std::list<std::unique_ptr<AlienBullet>> enemies_bullets;
  
  int enemy_spawn_timer{ENEMY_SPAWN_TIMER};
  int reset_stage_timer{RESET_STAGE_TIMER};
  
  void Update();
  void UpdateBullets();
  void UpdateEnemies();
  void UpdateEnemiesBullets();
  void SpawnEnemy();
  void CheckCollision();
  bool Collision(const Entity* e1, const Entity* e2);
  void ResetStage();
  void RenderGameEntities(Renderer &renderer);
};

#endif