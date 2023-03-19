#ifndef IMMORTAL_SCREEN_MANAGER_H_
#define IMMORTAL_SCREEN_MANAGER_H_
#include <tuple>
#include <variant>

#include "screens/titlescreen.h"
#include "screens/overworldscreen.h"

class ScreenManager {
  public: 

    std::variant<TitleScreen*, OverworldScreen*>* current_screen() { return &current_screen_; }
    template<typename T> void change_screen() { current_screen_ = &std::get<T>(available_screens_); }
  private:
    std::tuple<TitleScreen, OverworldScreen> available_screens_ { TitleScreen{this}, OverworldScreen{this}};
    std::variant<TitleScreen*, OverworldScreen*> current_screen_ = &std::get<TitleScreen>(available_screens_);
};

#endif

