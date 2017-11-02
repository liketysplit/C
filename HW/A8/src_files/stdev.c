#include "stdev.h"
#include "globals.h"

double stdev(double mean, double sum)
{
    extern TableType table;
    extern int count;
    double stDev = 0.0;

    int i;

    for(i=0; i<count; ++i)
        stDev += pow(table[i] - mean, 2);

    return sqrt((stDev/count));
}
