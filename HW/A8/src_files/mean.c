#include "mean.h"
#include "globals.h"

double mean(double sum)
{
	extern TableType table;
	extern int count;
	
    return sum/count;
}
