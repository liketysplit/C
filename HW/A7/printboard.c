#include "globalv.h"

//Prints out the board 3 values per space or *
void printBoard(int length, int width) {
    int i, j;
    extern TableType table;

    for (i = 0; i < length; i++) {    
        
        for (j = 0; j < width; j++) {
            if (table[i][j] == LIFE_YES) {
                printf(" * ");
            } else {
                printf("   ");
                
            }
        }
        printf("%-5d\n",i);
    }

    for(i=0; i< width; i++)
    {
        if(i<10)
        {
            printf("%d  ",i);
        }
        else
            printf("%d ",i);
    }
    

    printf("\n"); 
}
