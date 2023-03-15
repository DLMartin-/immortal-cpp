#include <SDL3/SDL.h>
#include <cstdlib>

#include "appmain.h"

int main(int const argc, char const *const argv[]) {

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    return -1;
  std::atexit(SDL_Quit);

  return app_main();
}
