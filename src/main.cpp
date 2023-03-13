#include <SDL3/SDL.h>
#include <cstdlib>

SDL_Window *window;
SDL_Renderer *renderer;

int main(int const argc, char const *const argv[]) {
  void register_onexit();

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return -1;
  register_onexit();

  window = SDL_CreateWindow("The Immortal", 640, 480, 0);
  renderer = SDL_CreateRenderer(window, nullptr, 0);

  if (window == nullptr || renderer == nullptr)
    return -1;

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  SDL_Event event;
  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}

void register_onexit() {
  std::atexit([]() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  });
}
