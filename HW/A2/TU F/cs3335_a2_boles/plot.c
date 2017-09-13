#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

int f(int);

int main(void){
	int i, t, funval;
	
    // Make sure to change low and high when testing your program
	int low=-3, high=11;
	for (t=low; t<=high;t++){
		printf("f(%2d)=%3d\n",t,f(t));
    }

    //---------------------------------------------My Code---------------------------------------------

    //My Variables
    int max = high;
    int min = low;
	int n =  abs(max) + abs(min);
	int tabSpace =7;
	int temp = 0;
	int xCount =0;
	int yCount = 0;

	//Arrays for storing values in/out
	int a[n+1];
	int b[n+1];
	int c[n+1];
	
	//lower and higher Y bounds
	int maxY = INT_MIN;
	int minY = INT_MAX;

	//Used to calculate functions without nest for loop
	int count = min;

	//Get lower and higher Y bounds
	for (int i =min; i<=max;i++){
		if (maxY<f(i))
			maxY = f(i);
		if (minY>f(i))
			minY = f(i);
	}

	//tabSpace loop 1 calculator for X values
	temp = max;
	while (temp != 0){
		temp /= 10;
		tabSpace++;
		xCount++;
	}

	//tabSpace loop 2 calculator for Y values
	temp = maxY;
	while (temp != 0){
		temp /= 10;
		tabSpace++;
		yCount++;
	}

	//String Builder for top of graph / Y bar
	for (int i =minY; i<=maxY+5;i+=5){
		if(i==minY)
			printf("%*d", tabSpace, i);
		else
			printf("%*d", 5, i);
	}

	//Build output array
	for (int i =0; i<=n;i++){
		a[i]=f(count);
		count++;
	}

	//Build input array
	count = min;
	for (int i =0; i<=n;i++){
		c[i]=count;
		count++;
	}

	//Set vaules of b array relative to lowest Y value && set lowest Y value to left hand bounds of graph
	for (int i =0; i<=n;i++){
		if (a[i]==minY)
			b[i]=6;
	else
		b[i]=6+(abs(minY - a[i]));
	}

	//Print X->Y values in the b array
	for (int i =0; i<=n;i++){
		printf("\nf(%*d)=%*d%*s",xCount+1,c[i],yCount+1,f(c[i]), b[i]-5 , "*");
	}

	//Test Code for Error Checking

	// //Output Array
	// printf("\n");
	// printf("\n--------------------------Test Code--------------------------");
	// printf("\nOutput Array");
	// for(int i=0; i<sizeof(a)/sizeof(int); i++){
	// 	printf("%3d%1s",a[i],",");
	// }

	// //Output Array Modified
	// printf("\nModified Output Array");
	// for(int i=0; i<sizeof(b)/sizeof(int); i++){
	// 	printf("%3d%1s",b[i],",");
	// }

	// // Input Array
	// printf("\nInput Array");
	// for(int i=0; i<sizeof(c)/sizeof(int); i++){
	// 	printf("%3d%1s",c[i],",");
	// }

	// printf("\nMin Y%4d",minY);
	// printf("\nMax Y%4d",maxY);
	// printf("\nTab Space: %-4d",tabSpace);


	return 0;
}


int f(int t){
    // example 1
	//return (t*t-4*t+5);
    
    return ((t*t)+(2*t)-8);
    // example 2
     //return (-t*t+4*t-1);
    
    // example 3
    // return (sin(t)*10);
    
    // example 4
	// if (t>0)
	//	return t*2;
	// else
	//	return t*8;
}
