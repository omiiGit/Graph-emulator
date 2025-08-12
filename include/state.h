#ifndef STATE_H 
#define STATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_image.h>
#include "Macro.h"
#include "graph.h"

typedef struct 
{
    const char* title;
    int w,h;

    SDL_Window* window;
    SDL_Renderer* renderer;

    Graph graph;

}State;

State createState(const char* tilte,int width,int height);
void initState(State* state);
void updateState(State* obj);
void closeState(State* state);

#endif 
