#ifndef GRAPH_H
#define GRAPH_H

#include "SDL2/SDL.h"
#include "Macro.h"
#include "font.h"
#include "utils.h"

typedef struct 
{
    int scale;
}Grid;

typedef struct 
{
    int scale;
    Grid grid;
    Text numbers;

}Graph;

Grid createGrid(int scale);
void drawGrid(SDL_Renderer* renderer,Grid* grid);

Graph createGraph(int scale);
void drawRuler(SDL_Renderer* renderer,Graph* graph);
void drawGraph(SDL_Renderer* renderer,Graph* graph);

#endif 
