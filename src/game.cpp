#include "game.h"
#include <SDL2/SDL.h>
#include <functional>
#include <iostream>

Game::Game(Renderer &renderer) {
  player_texture =
      std::make_unique<Texture>(renderer.LoadTexture("../gfx/player.png"));
  bullet_texture = std::make_unique<Texture>(
      renderer.LoadTexture("../gfx/playerBullet.png"));
  player = std::make_unique<Player>(player_texture->GetTexture(),
                                    bullet_texture->GetTexture(), bullets);
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

    for (auto const &bullet : bullets)
      if (bullet->GetHealth() == 1)
        renderer.RenderTexture(bullet.get());

    renderer.RenderTexture(player.get());
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

void Game::Update() {
  player->Update();

  for (const auto &bullet : bullets) {
    if (!bullet && bullet->GetHealth() == 0)
      bullets.remove(bullet);
    else
      bullet->Update();
  }
}