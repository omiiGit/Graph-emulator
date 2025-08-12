#include <stdio.h>
#include "state.h"

int main()
{
    State window = createState("Graph emulator",WIN_WIDTH,WIN_HEIGHT);

    printf("%d\n",WIN_WIDTH/GRAPH_SCALE);

    initState(&window);
    updateState(&window);
    closeState(&window);

    return 0;
}
