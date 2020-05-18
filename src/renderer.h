#ifndef RENDERER_H
#define RENDERER_H

#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

constexpr std::size_t kScreenWidth{1280};
constexpr std::size_t kScreenHeight{720};

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
  void UpdateWindowTitle(const int &x, const int&y, const int &fps);
  void RenderTexture(const Entity *entity);
  SDL_Texture *LoadTexture(const std::string &filename) const;

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  std::size_t screen_width;
  std::size_t screen_height;
};

#endif
