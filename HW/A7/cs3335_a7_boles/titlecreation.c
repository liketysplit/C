#include "globalv.h"

void titleCreation(int selection, int width) {
    int temp = 3*width;
    int i;

    if(temp%2 != 0)
        temp+=1;

    if(selection==1){
        printf("\n");

        //Top Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        printf("\n");
        //MyLine pt1
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("Welcome to Rick's Game of Life");
        //MyLine pt2
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("\n");
        //ConwaysLine pt1
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("Credited to Conway");
        //ConwaysLine pt2
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("\n");
        //GameSettings pt1
        for(i =0; i< temp/2-8;i++){
            printf("*");
        }
        printf("Default Gameplay");
        //GameSettings pt2
        for(i =0; i< temp/2-8;i++){
            printf("*");
        }
        printf("\n");
        //Bottom Line
        for(i =0; i< temp;i++){
            printf("*");
        }



    }
    if(selection==2){
        printf("\n");

        //Top Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        printf("\n");
        //MyLine pt1
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("Welcome to Rick's Game of Life");
        //MyLine pt2
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("\n");
        //ConwaysLine pt1
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("Credited to Conway");
        //ConwaysLine pt2
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("\n");
        //GameSettings pt1
        for(i =0; i< temp/2-6;i++){
            printf("*");
        }
        printf("Custom Spawn");
        //GameSettings pt2
        for(i =0; i< temp/2-6;i++){
            printf("*");
        }
        printf("\n");
        //Bottom Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        
    }
    if(selection==3){
        printf("\n");

        //Top Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        printf("\n");
        //MyLine pt1
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("Welcome to Rick's Game of Life");
        //MyLine pt2
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("\n");
        //ConwaysLine pt1
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("Credited to Conway");
        //ConwaysLine pt2
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("\n");
        //GameSettings pt1
        for(i =0; i< temp/2-6;i++){
            printf("*");
        }
        printf("Custom Grid");
        //GameSettings pt2
        for(i =0; i< temp/2-5;i++){
            printf("*");
        }
        printf("\n");
        //Bottom Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        
    }
    if(selection==4){
        printf("\n");

        //Top Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        printf("\n");
        //MyLine pt1
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("Welcome to Rick's Game of Life");
        //MyLine pt2
        for(i =0; i< temp/2-15;i++){
            printf("*");
        }
        printf("\n");
        //ConwaysLine pt1
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("Credited to Conway");
        //ConwaysLine pt2
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("\n");
        //GameSettings pt1
        for(i =0; i< temp/2-10;i++){
            printf("*");
        }
        printf("Custom Spawn & Grid");
        //GameSettings pt2
        for(i =0; i< temp/2-9;i++){
            printf("*");
        }
        printf("\n");
        //Bottom Line
        for(i =0; i< temp;i++){
            printf("*");
        }
        
    }

    printf("\n");

}

