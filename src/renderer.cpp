#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer()
    : screen_width(kScreenWidth), screen_height(kScreenHeight) {
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
  if ((initted & img_flags) != initted) {
    std::cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    std::cerr << "IMG_Init: " << IMG_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  IMG_Quit();
  SDL_DestroyWindow(sdl_window);
  SDL_DestroyRenderer(sdl_renderer);
  SDL_Quit();
}

Renderer::Renderer(Renderer &&source) {
  sdl_window = source.sdl_window;
  source.sdl_window = nullptr;
  sdl_renderer = source.sdl_renderer;
  sdl_renderer = nullptr;
  screen_width = source.screen_width;
  screen_height = source.screen_height;
}

Renderer &Renderer::operator=(Renderer &&source) {
  if (this == &source)
    return *this;

  SDL_DestroyWindow(sdl_window);
  SDL_DestroyRenderer(sdl_renderer);

  sdl_window = source.sdl_window;
  source.sdl_window = nullptr;
  sdl_renderer = source.sdl_renderer;
  sdl_renderer = nullptr;
  screen_width = source.screen_width;
  screen_height = source.screen_height;

  return *this;
}

void Renderer::PrepareScene() {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 96, 128, 255, 255);
  SDL_RenderClear(sdl_renderer);
}

void Renderer::PresentScene() { SDL_RenderPresent(sdl_renderer); }

void Renderer::UpdateWindowTitle(const int &x, const int &y, const int &fps) {
  std::string title{"X : " + std::to_string(x) + ", Y : " + std::to_string(y) + ", FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

SDL_Texture *Renderer::LoadTexture(const std::string &filename) const {
  // The final texture
  SDL_Texture *newTexture = NULL;

  // Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(filename.c_str());
  if (loadedSurface == NULL) {
    std::cerr << "Unable to load image " << filename
              << "! SDL_image Error: " << IMG_GetError() << "\n";
  } else {
    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(sdl_renderer, loadedSurface);
    if (newTexture == NULL) {
      std::cerr << "Unable to create texture from " << filename
                << "! SDL Error: " << SDL_GetError() << "\n";
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}

void Renderer::RenderTexture(const Entity *entity) {
  SDL_Rect dest;
  dest.x = entity->GetX();
  dest.y = entity->GetY();
  dest.w = entity->GetTextureWidth();
  dest.h = entity->GetTextureHeight();
  SDL_RenderCopy(sdl_renderer, entity->GetTexture(), NULL, &dest);
}
