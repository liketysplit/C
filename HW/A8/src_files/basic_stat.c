#include <string.h>
#define MAX_ITEM 8
#include "globals.h"
#include "sum.h"
#include "mean.h"
#include "stdev.h"
TableType table;
int count = 0;    

int main()
{

    int i;
    double sumv, meanv, stdevv;
    printf("Enter 8 numbers or less seperated by spaces: ");
    char input[1000];
    fgets(input , sizeof(input), stdin);

    input[strlen(input)-1] = '\0';

    char* s;
    s = strtok (input, " ");

    while (s != NULL){
        char *endptr;
        double temp = strtod(s,&endptr);
        double order;
        if (s != endptr && *endptr == '\0' && count < 8){
            table[count] = temp;
            count++;
        }
        else if (count > 8)
            printf("\nExtra Argument: %s", s);
        else
            printf("\nInvalid Argument: %s", s);

        s = strtok(NULL, " ");           
    }


    sumv = sum();
    meanv = mean(sumv);
    stdevv = stdev(meanv, sumv);

    printf("\n\nUsing the valid Arguments of : ");

    for(i=0; i < count; ++i){
        printf("%.2lf ", table[i]);
    }

    printf("\n\nSum = %.2lf", sumv);
    printf("\nMean = %.2lf", meanv);
    printf("\nStandard Deviation = %.2f\n", stdevv);
    printf("\nTable of difference between items and mean");
    printf("\n---------------------------------------------");
    printf("\n%-15s%-15s%-15s", "Index", "Item", "Difference");
    for(i=0; i < count; ++i){
        printf("\n%-15d%-15.2lf%-15.2lf", i, table[i], table[i]-meanv);
    }
    printf("\n");
return 0;

}
