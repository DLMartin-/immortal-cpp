#ifndef IMMORTAL_SCREENS_TITLE_SCREEN_H_
#define IMMORTAL_SCREENS_TITLE_SCREEN_H_
#include <SDL3/SDL.h>

class ScreenManager;

struct TitleScreen { ScreenManager* screen_manager; };
void display(TitleScreen &screen);
void update_tic(TitleScreen &screen);
void handle_event(TitleScreen &screen, SDL_Event const &event);

#endif

