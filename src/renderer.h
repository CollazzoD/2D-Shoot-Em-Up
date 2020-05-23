#ifndef RENDERER_H
#define RENDERER_H

#include "entity.h"
#include "texture.h"
#include "constants.h"
#include "star.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>

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
  void UpdateWindowTitle(const int &x, const int &y, const int &fps);
  void RenderTexture(const Entity *entity);
  void RenderBackground();
  void RenderStars(const Stars &stars);
  SDL_Texture *LoadTexture(const std::string &filename) const;

private:
  void UpdateBackground();
  std::unique_ptr<Texture> background_texture;
  int backgroundX{0};

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  int screen_width;
  int screen_height;
};

#endif
