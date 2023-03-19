#include "titlescreen.h"

#include <fmt/core.h>
#include <fmt/color.h>

#include "../screenmanager.h"

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
      fmt::print(fg(fmt::color::blue), "A Key Pressed\n");
      screen.screen_manager->change_screen<OverworldScreen>();
    }
  }
}
