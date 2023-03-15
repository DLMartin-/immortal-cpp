#include <SDL3/SDL.h>
#include <cstdlib>
#include <fmt/core.h>
#include <fmt/color.h>
#include "appmain.h"

int main(int const argc, char const *const argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, 
        "There has been an error while initializing SDL:\n");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, 
        "{}\n", SDL_GetError());
    return -1;
  }
  std::atexit(SDL_Quit);

  return app_main();
}
