#include "graph.h" 

Grid createGrid(int scale) {return(Grid){.scale = scale};}

void drawGrid(SDL_Renderer* renderer,Grid* grid)
{
    SDL_SetRenderDrawColor(renderer,128,128,128,255);


    for(int i = 0,x = grid->scale;i < WIN_WIDTH/grid->scale;i++)
    {
        SDL_Rect line = {x,0,1,WIN_HEIGHT};

        SDL_RenderFillRect(renderer,&line);
        x += grid->scale;
    }

    for(int i = 0,y = grid->scale;i < WIN_HEIGHT/grid->scale;i++)
    {
        SDL_Rect line = {0,y,WIN_WIDTH,1};

        SDL_RenderFillRect(renderer,&line);
        y += grid->scale;
    }

}




Graph createGraph(int scale)
{
    return(Graph)
    {
        .scale = scale,
        .grid = createGrid(scale),
    };
}

void drawGraph(SDL_Renderer* renderer,Graph* graph)
{
    //draw_grid on graph
    drawGrid(renderer,&graph->grid); 


    //draw x-y axis line
    SDL_SetRenderDrawColor(renderer,255,0,0,255);

    SDL_Rect yLine = {WIN_WIDTH/2,0,3,WIN_HEIGHT};
    SDL_RenderFillRect(renderer,&yLine);


    SDL_Rect xLine = {0,WIN_HEIGHT/2,WIN_WIDTH,3};
    SDL_RenderFillRect(renderer,&xLine);

    //draw ruler on x-y line
    for(int i = 0,x = graph->scale;i < WIN_WIDTH/graph->scale;i++)
    {
        SDL_Rect line = {x,WIN_HEIGHT/2,2,7};

        SDL_RenderFillRect(renderer,&line);
        x += graph->scale;
    }
    
    for(int i = 0,y = graph->scale;i < WIN_HEIGHT/graph->scale;i++)
    {
        SDL_Rect line = {WIN_WIDTH/2,y,7,2};

        SDL_RenderFillRect(renderer,&line);
        y += graph->scale;
    }



    SDL_RenderPresent(renderer);
}
