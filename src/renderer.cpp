#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width), screen_height(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("2D Shoot'Em Up", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Initialize SDL Image library
  int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int initted = IMG_Init(img_flags);
  if ((initted & img_flags) != img_flags) {
    std::cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    std::cerr << "IMG_Init: " << IMG_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  IMG_Quit();
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::prepareScene() {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 96, 128, 255, 255);
  SDL_RenderClear(sdl_renderer);
}

void Renderer::presentScene() { SDL_RenderPresent(sdl_renderer); }

void Renderer::UpdateWindowTitle(int fps) {
  std::string title{"Score: 100 FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
