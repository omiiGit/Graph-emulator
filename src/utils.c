#include "utils.h" 

static void itoa(int num,char* s,int* i)
{
    if(num < 0)
    {
        s[(*i)++] = '-';
        num = -num;
    }

    if(num / 10)
    {
        itoa(num/10,s,i);
        s[(*i)++] = num % 10 + '0';
    }
    else
    {
        s[(*i)++] = num % 10 + '0';
    }
}

void i_toa(int num,char* s)
{
    int i = 0;

    itoa(num,s,&i);

    s[i] = '\0';

}

int getRandom(int upper,int lower)
{
    return rand() % (upper - lower + 1) + lower;
}
