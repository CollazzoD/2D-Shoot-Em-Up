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

  // Try to create renderer with Hardware acceleration
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    // Try to create renderer without Hardware acceleration
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);
    if (nullptr == sdl_renderer) {
      std::cerr << "Renderer could not be created.\n";
      std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
  }

  // Initialize SDL Image library
  int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int initted = IMG_Init(img_flags);
  if ((initted & img_flags) != initted) {
    std::cerr << "IMG_Init: Failed to init required jpg and png support!\n";
    std::cerr << "IMG_Init: " << IMG_GetError() << "\n";
  }

  background_texture =
      std::make_unique<Texture>(LoadTexture("../gfx/background.png"));
  font_texture = std::make_unique<Texture>(LoadTexture("../gfx/font.png"));
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
  SDL_SetRenderDrawColor(sdl_renderer, 32, 32, 32, 255);
  SDL_RenderClear(sdl_renderer);
  RenderBackground();
  UpdateBackground();
}

void Renderer::PresentScene() { SDL_RenderPresent(sdl_renderer); }

void Renderer::UpdateWindowTitle(const int &fps) {
  std::string title{"FPS: " + std::to_string(fps)};
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

void Renderer::PrintHighscore(const HighScore &highscore) {
  int i = 1;
  int y = 150;
  DrawText(530, 70, 255, 255, 255, "HIGHSCORES");
  auto scores = highscore.GetScores();
  std::sort(begin(scores), end(scores), std::greater<int>());
  for (const int &score : scores) {
    if (i < 10)
      DrawText(425, y, 255, 255, 0,
               "#0" + std::to_string(i) + " ............. " +
                   std::to_string(score));
    else
      DrawText(425, y, 255, 255, 0,
               "#" + std::to_string(i) + " ............. " +
                   std::to_string(score));
    y += 50;
    i++;
  }
  y += 10;
  DrawText(450, y, 255, 255, 255, "PRESS FIRE TO PLAY!");
}

void Renderer::Render(const Entity *entity) {
  SDL_Rect dest;
  dest.x = entity->GetX();
  dest.y = entity->GetY();
  dest.w = entity->GetWidth();
  dest.h = entity->GetHeight();
  SDL_RenderCopy(sdl_renderer, entity->GetTexture()->GetTexture(), NULL, &dest);
}

void Renderer::Render(const Debris *debris) {
  SDL_Rect source, dest;
  dest.x = debris->GetX();
  dest.y = debris->GetY();
  dest.w = debris->GetWidth();
  dest.h = debris->GetHeight();
  source = debris->GetRect();
  SDL_RenderCopy(sdl_renderer, debris->GetTexture()->GetTexture(), &source,
                 &dest);
}

void Renderer::Render(const Explosion *explosion) {
  SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_ADD);
  SDL_SetTextureBlendMode(explosion->GetTexture()->GetTexture(),
                          SDL_BLENDMODE_ADD);
  SDL_SetTextureColorMod(explosion->GetTexture()->GetTexture(), explosion->r,
                         explosion->g, explosion->b);
  SDL_SetTextureAlphaMod(explosion->GetTexture()->GetTexture(), explosion->a);
  Render(dynamic_cast<const Entity *>(explosion));
  SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_NONE);
}

void Renderer::UpdateBackground() {
  backgroundX--;
  if (backgroundX < -kScreenWidth)
    backgroundX = 0;
}

void Renderer::RenderBackground() {
  SDL_Rect dest;
  for (int x = backgroundX; x < kScreenWidth; x += kScreenWidth) {
    dest.x = x;
    dest.y = 0;
    dest.w = kScreenWidth;
    dest.h = kScreenHeight;

    SDL_RenderCopy(sdl_renderer, background_texture->GetTexture(), NULL, &dest);
  }
}

void Renderer::DrawHud(const int &score, const int &highscore) {
  DrawText(10, 10, 255, 255, 255, "SCORE: " + std::to_string(score));
  if (score > highscore) {
    DrawText(960, 10, 0, 255, 0, "HIGH SCORE: " + std::to_string(score));
  } else {
    DrawText(960, 10, 255, 255, 255,
             "HIGH SCORE: " + std::to_string(highscore));
  }
}

void Renderer::DrawText(const int &x, const int &y, const int &r, const int &g,
                        const int &b, const std::string &text) {
  SDL_Rect rect;
  rect.w = GLYPH_WIDTH;
  rect.h = GLYPH_HEIGHT;
  rect.y = 0;

  SDL_SetTextureColorMod(font_texture->GetTexture(), r, g, b);

  int x_text = x;
  for (const char &c : text) {
    if (c >= ' ' && c <= 'Z') {
      rect.x = (c - ' ') * GLYPH_WIDTH;

      BlitRect(font_texture->GetTexture(), &rect, x_text, y);

      x_text += GLYPH_WIDTH;
    }
  }
}

void Renderer::Render(const Stars &stars) {
  int c;

  for (const auto &star : stars.stars) {
    c = 32 * star.speed;
    SDL_SetRenderDrawColor(sdl_renderer, c, c, c, 255);
    SDL_RenderDrawLine(sdl_renderer, star.x, star.y, star.x + 3, star.y);
  }
}

void Renderer::BlitRect(SDL_Texture *texture, const SDL_Rect *src, const int &x,
                        const int &y) {
  SDL_Rect dest;

  dest.x = x;
  dest.y = y;
  dest.w = src->w;
  dest.h = src->h;

  SDL_RenderCopy(sdl_renderer, texture, src, &dest);
}