#include <string_view>

#include <fmt/core.h>
#include <fmt/color.h>

#include <SDL3/SDL.h>

struct SdlWindowContext {
  SDL_Window* window;
  SDL_Renderer* renderer;

  ~SdlWindowContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
};

[[nodiscard]] SdlWindowContext create_window_context(std::string_view title, int w,
                                            int h, int window_flags,
                                            int renderer_flags) noexcept {
  auto window = SDL_CreateWindow(title.data(), w, h, window_flags);
  auto renderer = SDL_CreateRenderer(window, nullptr, renderer_flags);

  return SdlWindowContext{window, renderer};
}

[[nodiscard]] int app_main() noexcept {
  auto [window, renderer] =
      create_window_context("The Immortal", 640, 480, 0, 0);

  if (window == nullptr || renderer == nullptr) {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, 
        "There has been an error creating a Window or Renderer:\n");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, 
        "{}\n", SDL_GetError());
    return -1;
  }

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
