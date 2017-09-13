#include <stdio.h>

int main(){
	// Change the elements in the following array
	// to test your program
	int digits[]={2,0,38,2,3,1,3};
	//int digits[]={1,2,3,4,5,6,7};
	//int digits[]={1,1,1,1,1,1,1};
	int i;

	printf("In the array of ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n");	

	// Variables
	int count =0;

	int fRep = -1;
	int lRep = -1;
	int fNRep = -1;
	int lNRep = -1;

	int digitsCounted[100] = {};

	//Builds the digitsCounted Array

		for (int j=0; j<sizeof(digits)/sizeof(int);j++){
				digitsCounted[digits[j]] += 1;
		}

	//Checks for the first repeated/nonrepeated digits
		for (int j=0; j <= sizeof(digits)/sizeof(int)-1;j++){
			if((digitsCounted[digits[j]]==1) && (fNRep == -1))
				fNRep = digits[j];
			if((digitsCounted[digits[j]]>=2) && (fRep == -1))
				fRep = digits[j];
		}
	//Checks for the last digits repeated/nonrepeated
		for (int j=0; j <= sizeof(digits)/sizeof(int)-1;j++){
			if(digitsCounted[digits[j]]==1)
				lNRep = digits[j];
			if(digitsCounted[digits[j]]>=2)
				lRep = digits[j];
		}

	//Output Logic
			puts("");
		if ((fNRep == -1) && (lNRep == -1))
			printf("%s\n","There is no non-repeated number!");
		else{
			printf("%s%d\n","The first non-repeated number is:",fNRep);
			printf("%s%d\n","The last non-repeated number is ",lNRep);
		}

		if ((lRep == -1) && (fRep == -1))
			printf("%s\n","There is no repeated number!");
		else{
			printf("%s%d\n","The first repeated number is:",fRep);
			printf("%s%d\n","The last repeated number is:",lRep);
		}

		//Test Code to see how data is stored in digitsCounted array.
		// printf("In the array of ");	
		// for (i=0; i<sizeof(digitsCounted)/sizeof(int); i++)
		// printf("%d ", digitsCounted[i]);
		// printf("\n");


	return 0;
}
