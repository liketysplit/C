#include "globalv.h"
#include "neighborcount.h"
//Game Rule Conditions
void lifeRules(int length, int width) {
    TableType temp;
    int count, i, j;
    extern TableType table;
    
    //Calcualte New Values and store them in temp
    for (i = 0; i < length; i++) {
        for  (j = 0; j < width; j++) {
            count = neighborCount(i, j, length, width);

            if (count==3) {
                temp[i][j] = LIFE_YES;
            } else if (count == 2 && table[i][j] == LIFE_YES) {
                temp[i][j] = LIFE_YES;
            } else {
                temp[i][j] = LIFE_NO;
            }
        }
    }

    //Store temp in table
    for (i = 0; i < length; i++) {
        for( j = 0; j < width; j++) {
            table[i][j] = temp[i][j];
        }
    }

}