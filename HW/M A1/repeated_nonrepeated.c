#include <stdio.h>

int main(){
	// Change the elements in the following array
	// to test your program
	//int digits[]={1,2,3,2,3,4,5};
	//int digits[]={1,5,3,28,3,4,5};
	//int digits[]={1,1,1,1,1,1,1};
	int digits[]={1,56,45,2,12,1,5};
	int i;
	int j;
	int counter[100] = {};
	int count = 0;
	
	int firstNonRep = -1;
	int lastNonRep =-1;
	int firstRep =-1;
	int lastRep = -1;
	
	

	printf("In the array of ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n");	

	
	
	
	
	
	
	
	
	
	for(i = 0; i<sizeof(counter)/sizeof(int); i++)
		counter[i]= 0;
		
		
		
	for(i = 0; i<sizeof(digits)/sizeof(int); i++){
		
		counter[digits[i]] += 1;
	}
	
		//find repeated and non repeated
	for(i = 0; i<sizeof(digits)/sizeof(int); i++){
		
			if(counter[digits[i]] == 1 && firstNonRep == -1){
				firstNonRep = digits[i];
			}
			if(counter[digits[i]] >= 2 && firstRep == -1){
				firstRep = digits[i];
			}
		}
		// find last repeated and nonrepeated
		for(i = 0; i<sizeof(digits)/sizeof(int); i++){
		
			if(counter[digits[i]] == 1 ){
				lastNonRep = digits[i];
			}
			if(counter[digits[i]] >= 2 ){
				lastRep = digits[i];
			}
		}
	

	

	
		

	
	if((firstNonRep == -1) && (lastNonRep == -1)){
		printf("%s\n", "There isn't any non-repeated digit");
	}
	else{
		printf("%s%d\n","The first non-repeated digit is " , firstNonRep);
		printf("%s%d\n","The last non-repeated digit is " , lastNonRep);
	}
	
	
	if((firstRep == -1) && (lastRep == -1)){
		printf("%s\n","There isn't any repeated digit ");
	}
	else{
		printf("%s%d\n","The first repeated digit is " , firstRep);
		printf("%s%d\n","The last repeated digit is " , lastRep);
	}
	
	
	
	
	
	
	

	return 0;

}
