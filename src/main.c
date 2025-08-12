#include <stdio.h>
#include "utils.h" 
#include "state.h"

int main()
{
    State window = createState("Graph emulator",WIN_WIDTH,WIN_HEIGHT);

    printf("%d\n",WIN_WIDTH/GRAPH_SCALE);

    initState(&window);
    updateState(&window);
    closeState(&window);

    return 0;

    /*float num = 1.5;
    char s[8];

    f_toa(num,s);

    printf("%s",s);*/
}
