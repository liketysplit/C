#include "globalv.h"
#include "neighborvalue.h"

//Runs a count on all of the neighbors 
int neighborCount(int row, int coloum, int length, int width) {
    int neighbor =0;
    extern TableType table;
    
    neighbor += getNeighborValue(row, coloum + 1, length, width);
    neighbor += getNeighborValue(row, coloum - 1, length, width);
    neighbor += getNeighborValue(row + 1, coloum, length, width);
    neighbor += getNeighborValue(row - 1, coloum, length, width);
    neighbor += getNeighborValue(row + 1, coloum - 1, length, width);
    neighbor += getNeighborValue(row - 1, coloum + 1, length, width); 
    neighbor += getNeighborValue(row + 1, coloum + 1, length, width);
    neighbor += getNeighborValue(row - 1, coloum - 1, length, width);
    
    return neighbor;
}



