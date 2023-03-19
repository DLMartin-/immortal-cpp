#ifndef IMMORTAL_OVERWORLD_SCREEN_H_
#define IMMORTAL_OVERWORLD_SCREEN_H_
#include <SDL3/SDL.h>

class ScreenManager;

struct OverworldScreen { ScreenManager* screen_manager; };
void display(OverworldScreen &screen);
void update_tic(OverworldScreen &screen);
void handle_event(OverworldScreen &screen, SDL_Event const &event);

#endif

