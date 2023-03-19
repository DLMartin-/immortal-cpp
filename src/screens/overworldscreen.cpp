#include "overworldscreen.h"

#include <fmt/core.h>
#include <fmt/color.h>

#include "../screenmanager.h"

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
      fmt::print(fg(fmt::color::blue), "S Key Pressed\n");
      screen.screen_manager->change_screen<TitleScreen>();
    }
  }
}

