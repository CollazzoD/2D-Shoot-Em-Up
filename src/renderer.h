#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

constexpr std::size_t kScreenWidth{1280};
constexpr std::size_t kScreenHeight{720};

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  Renderer(const Renderer &source) = delete;
  Renderer &operator=(const Renderer &source) = delete;
  Renderer(Renderer &&source);
  Renderer &operator=(Renderer &&source);

  void PrepareScene();
  void PresentScene();
  void UpdateWindowTitle(int fps);
  void RenderTexture(SDL_Texture *texture, int x, int y);
  SDL_Texture* LoadTexture(const std::string& filename) const;

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  std::size_t screen_width;
  std::size_t screen_height;
};

#endif
