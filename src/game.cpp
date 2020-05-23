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

void Game::ResetStage() {
  bullets.erase(begin(bullets), end(bullets));
  enemies.erase(begin(enemies), end(enemies));
  enemies_bullets.erase(begin(enemies_bullets), end(enemies_bullets));
  player->Init();
  enemy_spawn_timer = ENEMY_SPAWN_TIMER;
  reset_stage_timer = RESET_STAGE_TIMER;
}

void Game::RenderGameEntities(Renderer &renderer) {
  if (player->GetHealth() == 1)
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
}

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
    RenderGameEntities(renderer);

    renderer.PresentScene();

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    if (player->GetHealth() <= 0) {
      reset_stage_timer--;
      if (reset_stage_timer <= 0)
        ResetStage();
    }

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
  enemy_spawn_timer--;
  if (enemy_spawn_timer <= 0) {
    AlienBullet alien_bullet_forge =
        AlienBullet(enemy_bullet_texture->GetTexture(), 0, 0);
    auto enemy = std::make_unique<Enemy>(
        enemy_texture->GetTexture(), kScreenWidth, enemy_random_pos(engine),
        enemy_random_speed(engine), std::move(alien_bullet_forge),
        enemies_bullets, player.get());
    enemies.push_front(std::move(enemy));
    enemy_spawn_timer = ENEMY_SPAWN_TIMER;
  }
}

void Game::UpdateBullets() {
  for (auto bullet = begin(bullets); bullet != end(bullets);) {
    if (!*bullet) {
      bullet = bullets.erase(bullet);
    } else if ((*bullet)->GetHealth() == 0) {
      bullet = bullets.erase(bullet);
    } else {
      (*bullet)->Update();
      bullet++;
    }
  }
}

void Game::UpdateEnemies() {
  for (auto enemy = begin(enemies); enemy != end(enemies);) {
    if (!*enemy) {
      enemy = enemies.erase(enemy);
    } else if ((*enemy)->GetHealth() == 0) {
      std::cout << "Remove no health enemy" << std::endl;
      enemy = enemies.erase(enemy);
      std::cout << "Enemy removed" << std::endl;
    } else {
      (*enemy)->Update();
      enemy++;
    }
  }
}

void Game::UpdateEnemiesBullets() {
  for (auto bullet = begin(enemies_bullets); bullet != end(enemies_bullets);) {
    if (!*bullet) {
      bullet = enemies_bullets.erase(bullet);
    } else if ((*bullet)->GetHealth() == 0) {
      bullet = enemies_bullets.erase(bullet);
    } else {
      (*bullet)->Update();
      bullet++;
    }
  }
}

void Game::Update() {
  // Update player
  player->Update();

  SpawnEnemy();
  UpdateBullets();
  UpdateEnemies();
  UpdateEnemiesBullets();

  CheckCollision();
}

bool Game::Collision(const Entity *e1, const Entity *e2) {
  int max_x = std::max<int>(e1->GetX(), e2->GetX());
  int min_xw =
      std::min<int>(e1->GetX() + e1->GetWidth(), e2->GetX() + e2->GetWidth());

  int max_y = std::max<int>(e1->GetY(), e2->GetY());
  int min_yh =
      std::min<int>(e1->GetY() + e1->GetHeight(), e2->GetY() + e2->GetHeight());

  return (max_x < min_xw) && (max_y < min_yh);
}

void Game::CheckCollision() {
  // Player bullet's enemies collision
  for (const auto &enemy : enemies)
    for (const auto &bullet : bullets)
      if (Collision(enemy.get(), bullet.get())) {
        enemy->Hit();
        bullet->Hit();
      }

  // Enemies bullet's Player collision
  for (const auto &bullet : enemies_bullets)
    if (Collision(player.get(), bullet.get())) {
      player->Hit();
      bullet->Hit();
    }
}
