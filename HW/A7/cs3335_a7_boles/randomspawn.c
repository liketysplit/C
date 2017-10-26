#include "globalv.h"

//Puts in random data in a non-life cell
void randomSpawner(int numOfOrganismsToSpawn, int length, int width) {
    
    srand(time(NULL));
    int i,j,count;
    extern TableType table;

    count = 0;

    while(count < numOfOrganismsToSpawn){
        i=rand()%length;
        j=rand()%width;

        if(table[i][j] != LIFE_YES){
            table[i][j] = LIFE_YES;
            count++;
        }
    }
}

