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
        .numbers = createText("res/dina.ttf",15,0,0,0),
        .points = createList(),
    };
}

void drawRuler(SDL_Renderer* renderer,Graph* graph)
{
    SDL_SetRenderDrawColor(renderer,255,0,0,255);


    int n = graph->scale*((WIN_WIDTH/graph->scale)/2);
    SDL_Rect yLine = {n,0,3,WIN_HEIGHT};
    SDL_RenderFillRect(renderer,&yLine);


    int k = graph->scale*((WIN_HEIGHT/graph->scale)/2);
    SDL_Rect xLine = {0,k,WIN_WIDTH,3};
    SDL_RenderFillRect(renderer,&xLine);

    //draw ruler on x-y line
    char num[3];
    for(int i = 0,x = graph->scale;i < WIN_WIDTH/graph->scale;i++)
    {
        SDL_Rect line = {x,k,2,7};

        int o = (WIN_WIDTH/graph->scale)/2;
        if(i != o-1)
        {
            int value = (i+1) - o;
            i_toa(value,num);
            drawText(renderer,&graph->numbers,num,x,k+9);
        }
        else 
        {
            i_toa(0,num);
            drawText(renderer,&graph->numbers,num,x+4,k+5);
        }
        SDL_RenderFillRect(renderer,&line);
        x += graph->scale;
    }
    

    for(int i = 0,y = WIN_HEIGHT-graph->scale;i < WIN_HEIGHT/graph->scale;i++)
    {
        SDL_Rect line = {n,y,7,2};

        int o = (WIN_HEIGHT/graph->scale)/2;
        if(i != o-1)
        {
            int value = (i+1) - o;
            char num[3]; i_toa(value,num);
            drawText(renderer,&graph->numbers,num,n+9,y);
        }
        SDL_RenderFillRect(renderer,&line);
        y -= graph->scale;
    }
}

void drawGraph(SDL_Renderer* renderer,Graph* graph)
{
    //draw_grid on graph
    drawGrid(renderer,&graph->grid); 

    //draw_ruler on graph
    drawRuler(renderer,graph);
    drawPoint(renderer,-1.7f,3.2f);
    drawPoint(renderer,2.5f,1.5f);

}

void drawPoint(SDL_Renderer* renderer,float x,float y)
{
    Point point = {x,y,createText("res/dina.ttf",18,0,0,255)};
    SDL_SetRenderDrawColor(renderer,0,0,255,255);

    float px = (float)ORIGIN_X + (GRAPH_SCALE*point.x);
    float py = (float)ORIGIN_Y - (GRAPH_SCALE*point.y);

    SDL_Rect p = {px-2,py-1,4,4};

    char* inf = NULL;

    char q[5]; f_toa(point.x,q);
    char b[5] = ",";
    char c[5]; f_toa(point.y,c);

    appendStr(&inf,q);appendStr(&inf,b);appendStr(&inf,c);

    SDL_RenderFillRect(renderer,&p);
    drawText(renderer,&point.info,inf,px-7,py-20);

    TTF_CloseFont(point.info.font);

    free(inf);
}


