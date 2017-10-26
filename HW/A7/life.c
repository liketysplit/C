#include "globalv.h"
#include "liferule.h"
#include "printboard.h"
#include "organismcalc.h"
#include "randomspawn.h"
#include "titlecreation.h"

TableType table; //Just make typing this out simpler

//Main Game loops utilizing argc with a swithc to determine corret number of args
int main(int argc, char *argv[]) {

    int generation = 0, numOfOrganismsToSpawn, randomOrganisms, organismsInput,length,width, totalArea;

    switch(argc){
    	//No Args Defaults 
        case 1:
        	numOfOrganismsToSpawn=organismsCalculator(10,30 ,30);
            randomSpawner(numOfOrganismsToSpawn, 30 ,30);

            while(1){
                titleCreation(1, 30);
                printBoard(30, 30);
                lifeRules(30, 30);
                printf("Generation %d\n", ++generation);

                fflush(stdout);
                usleep(200000);
                system("clear");
            }
            break;

        //One Arg for Rate
        case 2:
            organismsInput = atoi(argv[1]);
            numOfOrganismsToSpawn=organismsCalculator(organismsInput ,30 ,30);
            randomSpawner(numOfOrganismsToSpawn ,30 ,30);

            while(1){
                titleCreation(2, 30);
                printBoard(30, 30);
                lifeRules(30, 30);
                printf("Generation %d\n", ++generation);

                fflush(stdout);
                usleep(200000);
                system("clear");
            }
            break;

        //Two Args for Grid
        case 3:
            length = atoi(argv[1]);
            width = atoi(argv[2]);
            numOfOrganismsToSpawn=organismsCalculator(10, length, width);
            randomSpawner(numOfOrganismsToSpawn, length, width);

            while(1){   
                titleCreation(3, width);
                printBoard(length, width);
                lifeRules(length, width);
                printf("Generation %d\n", ++generation);

                fflush(stdout);
                usleep(200000);
                system("clear");
            }
            
            break;

        //Three Args for Grid & Rate    
        case 4:
            organismsInput = atoi(argv[1]);
            length = atoi(argv[2]);
            width = atoi(argv[3]);
            numOfOrganismsToSpawn=organismsCalculator(organismsInput, length, width);
            randomSpawner(numOfOrganismsToSpawn ,length ,width);
            while(1){
                titleCreation(4, width);
                printBoard(length, width);
                lifeRules(length, width);
                printf("Generation %d\n", ++generation);

                fflush(stdout);
                usleep(200000);
                system("clear");
            }
            
            break;

        default:

            break;
    }

    return 0;
}

