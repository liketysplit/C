#include "rcards.h"

int rCard(int hand[]) { 
    int i;
	srand(time(NULL));
	int found = 10;
	int temp;

	while(1){
	temp = (rand()%52)+2;
	found = 10;
		for(i=0;i<10;i++){
			if(hand[i] == temp){
				found = 11;
			}

		}

		if(found == 10){
				return temp;
		}
	} 
}