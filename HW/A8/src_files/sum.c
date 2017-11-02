#include "sum.h"
#include "globals.h"
double sum()
{
    extern TableType table;
    extern int count;

    double sum = 0.0;
    int i;

    for(i=0; i<count; ++i)
    {
        sum += table[i];
    }


    return sum;
}
