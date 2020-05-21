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
#include <forward_list>

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
  std::forward_list<std::unique_ptr<Bullet>> bullets;
  std::forward_list<std::unique_ptr<Enemy>> enemies;
  std::forward_list<std::unique_ptr<AlienBullet>> enemies_bullets;
  void Update();
  void SpawnEnemy();
  int enemySpawnTimer{120};
};

#endif