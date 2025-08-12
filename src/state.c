#include <stdbool.h> 
#include "state.h"


State createState(const char* title,int width,int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_JPG);


    return(State)
    {
        .title = title,
        .w = width,
        .h = height,
        .window = NULL,
        .renderer = NULL,
        .graph = createGraph(GRAPH_SCALE),
    };
}

void initState(State* state)
{
    state->window = SDL_CreateWindow(
            state->title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            state->w,
            state->h,
            SDL_WINDOW_SHOWN
            ); 

    state->renderer = SDL_CreateRenderer(state->window,-1,
            SDL_RENDERER_ACCELERATED | 
            SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(state->renderer,255,255,255,255);
    SDL_RenderClear(state->renderer);

    SDL_RenderPresent(state->renderer);
    
}

void updateState(State* state)
{
    SDL_Event e;
    bool quit = false;

    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT: quit = true; break;
            }
        }
        drawGraph(state->renderer,&state->graph);
    }

}

void closeState(State* state)
{
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
