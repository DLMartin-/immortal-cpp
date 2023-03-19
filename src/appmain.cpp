#include <string_view>
#include <tuple>
#include <variant>

#include <fmt/color.h>
#include <fmt/core.h>

#include <SDL3/SDL.h>

struct SdlWindowContext {
  SDL_Window *window;
  SDL_Renderer *renderer;

  ~SdlWindowContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
};

struct TitleScreen {};
void display(TitleScreen &screen);
void update_tic(TitleScreen &screen);
void handle_event(TitleScreen &screen, SDL_Event const &event);

struct OverworldScreen {};
void display(OverworldScreen &screen);
void update_tic(OverworldScreen &screen);
void handle_event(OverworldScreen &screen, SDL_Event const &event);

using GameScreen = std::variant<TitleScreen*, OverworldScreen*>;
using GameScreens = std::tuple<TitleScreen, OverworldScreen>;

GameScreens screen_states{};
GameScreen current_screen = &std::get<TitleScreen>(screen_states);

void display(TitleScreen &screen) {
  fmt::print(fg(fmt::color::indigo), "TitleScreen::display()\n");
}
void update_tic(TitleScreen &screen) {
  fmt::print(fg(fmt::color::indigo), "TitleScreen::update_tic()\n");
}
void handle_event(TitleScreen &screen, SDL_Event const &event) {
  fmt::print(fg(fmt::color::indigo), "TitleScreen::handle_event()\n");
  if(event.type == SDL_EVENT_KEY_DOWN) {
    if(event.key.keysym.scancode == SDL_SCANCODE_A) {
      current_screen = &std::get<OverworldScreen>(screen_states);
    }
  }
}

void display(OverworldScreen &screen) {
  fmt::print(fg(fmt::color::lime), "OverworldScreen::display()\n");
}
void update_tic(OverworldScreen &screen) {
  fmt::print(fg(fmt::color::lime), "OverworldScreen::process_tic()\n");
}
void handle_event(OverworldScreen &screen, SDL_Event const &event) {
  fmt::print(fg(fmt::color::lime), "OverworldScreen::handle_event()\n");
  if(event.type == SDL_EVENT_KEY_DOWN) {
    if(event.key.keysym.scancode == SDL_SCANCODE_S) {
      current_screen = &std::get<TitleScreen>(screen_states);
    }
  }
}

[[nodiscard]] SdlWindowContext
create_window_context(std::string_view title, int w, int h, int window_flags,
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
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "{}\n",
               SDL_GetError());
    return -1;
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  SDL_Event event{};
  while (1) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;
      std::visit([&event](auto &&screen) { handle_event(*screen, event); },
                 current_screen);
    }

    std::visit([](auto &&screen) { update_tic(*screen); }, current_screen);
    std::visit([](auto &&screen) { display(*screen); }, current_screen);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  return 0;
}
