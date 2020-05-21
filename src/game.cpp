#include "game.h"
#include <SDL2/SDL.h>
#include <functional>
#include <iostream>
#include <random>

Game::Game(Renderer &renderer) {
  player_texture =
      std::make_unique<Texture>(renderer.LoadTexture("../gfx/player.png"));
  bullet_texture = std::make_unique<Texture>(
      renderer.LoadTexture("../gfx/playerBullet.png"));
  enemy_texture =
      std::make_unique<Texture>(renderer.LoadTexture("../gfx/enemy.png"));
  enemy_bullet_texture =
      std::make_unique<Texture>(renderer.LoadTexture("../gfx/alienBullet.png"));

  Bullet bullet_forge(bullet_texture->GetTexture(), 0, 0);
  player = std::make_unique<Player>(player_texture->GetTexture(),
                                    std::move(bullet_forge), bullets);

  engine = std::mt19937(dev());
  enemy_random_speed =
      std::uniform_int_distribution<int>(ENEMY_MIN_SPEED, ENEMY_MAX_SPEED);

  int enemy_max_pos = kScreenHeight - enemy_texture->GetTextureHeight();
  enemy_random_pos = std::uniform_int_distribution<int>(0, enemy_max_pos);
}

Game::~Game() {}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    renderer.PrepareScene();
    controller.HandleInput(running, player.get());

    Update();

    renderer.RenderTexture(player.get());

    for (auto const &bullet : bullets)
      if (bullet->GetHealth() == 1)
        renderer.RenderTexture(bullet.get());

    for (auto const &enemy : enemies)
      if (enemy->GetHealth() == 1)
        renderer.RenderTexture(enemy.get());

    for (auto const &bullet : enemies_bullets)
      if (bullet->GetHealth() == 1)
        renderer.RenderTexture(bullet.get());
    
    renderer.PresentScene();

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(player->GetX(), player->GetY(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


void Game::SpawnEnemy() {
  enemySpawnTimer--;
  if (enemySpawnTimer <= 0) {
    AlienBullet alien_bullet_forge = AlienBullet(enemy_bullet_texture->GetTexture(), 0, 0);
    auto enemy = std::make_unique<Enemy>(
        enemy_texture->GetTexture(), kScreenWidth, enemy_random_pos(engine),
        enemy_random_speed(engine), std::move(alien_bullet_forge), enemies_bullets);
    enemies.push_front(std::move(enemy));
    enemySpawnTimer = 120;
  }
}

void Game::Update() {
  // Update player
  player->Update();
  SpawnEnemy();
  for (const auto &bullet : bullets) {
    if (!bullet && bullet->GetHealth() == 0)
      bullets.remove(bullet);
    else
      bullet->Update();
  }

  for (const auto &enemy : enemies) {
    if (!enemy && enemy->GetHealth() == 0)
      enemies.remove(enemy);
    else
      enemy->Update();
  }

  for (const auto &bullet : enemies_bullets) {
    if (!bullet && bullet->GetHealth() == 0)
      enemies_bullets.remove(bullet);
    else
      bullet->Update();
  }
}