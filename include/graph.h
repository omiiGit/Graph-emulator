#ifndef GRAPH_H
#define GRAPH_H

#include "SDL2/SDL.h"
#include "Macro.h"

typedef struct 
{
    int scale;
}Grid;

typedef struct 
{
    int scale;
    Grid grid;

}Graph;

Grid createGrid(int scale);
void drawGrid(SDL_Renderer* renderer,Grid* grid);

Graph createGraph(int scale);
void drawGraph(SDL_Renderer* renderer,Graph* graph);

#endif 
