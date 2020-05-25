#ifndef RENDERER_H
#define RENDERER_H

#include "constants.h"
#include "debris.h"
#include "entity.h"
#include "explosion.h"
#include "star.h"
#include "texture.h"
#include "highscore.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <memory>
#include <string>

class Renderer {
public:
  Renderer();
  ~Renderer();
  Renderer(const Renderer &source) = delete;
  Renderer &operator=(const Renderer &source) = delete;
  Renderer(Renderer &&source);
  Renderer &operator=(Renderer &&source);

  void PrepareScene();
  void PresentScene();
  void UpdateWindowTitle(const int &fps);
  void Render(const Entity *entity);
  void Render(const Debris *debris);
  void Render(const Explosion *explosion);
  void Render(const Stars &stars);
  void RenderBackground();
  void DrawHud(const int &score, const int &highscore);
  void PrintHighscore(const HighScore &highscore);
  SDL_Texture *LoadTexture(const std::string &filename) const;

private:
  void DrawText(const int &x, const int &y, const int &r, const int &g,
                const int &b, const std::string &text);
  void UpdateBackground();
  void BlitRect(SDL_Texture *texture, const SDL_Rect *src, const int &x,
                const int &y);

  std::unique_ptr<Texture> background_texture;
  std::unique_ptr<Texture> font_texture;

  int backgroundX{0};

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  int screen_width;
  int screen_height;
};

#endif
