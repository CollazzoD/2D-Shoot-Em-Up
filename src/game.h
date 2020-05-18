#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include "controller.h"
#include "player.h"
#include "renderer.h"
#include "texture.h"
#include <SDL2/SDL.h>
#include <memory>

class Game {
public:
  Game(Renderer &renderer);
  ~Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

private:
  // I create the textures only once, so as to refer to the same texture
  std::unique_ptr<Texture> player_texture;
  std::unique_ptr<Texture> bullet_texture;

  std::unique_ptr<Player> player;
  void Update();
};

#endif