#include <stdio.h>

int sum(int [][5]);
int sum2(int [][5], int);

int sum (int x[][5]){
	int i, j, sum=0;
	// for (i=0; i<3; i++)
	// The following won't work due to "pointer decay".
 	for(i=0; i<sizeof(x)/sizeof(*x);i++)

        	// for (j=0; j<5; j++)
		// The following is fine
		 for(j=0; j<sizeof(*x)/sizeof(int);j++)
			sum+=x[i][j];
	return sum;
}

int sum2 (int x[][5], int m){
	int i, j, sum=0;

	for (i=0; i<m; i++)
		for(j=0; j<sizeof(*x)/sizeof(int);j++)
			sum+=x[i][j];
	return sum;
}
int main(){
	int a[3][5];
	printf("sizeof(a) = %ld\n", sizeof(a));
	printf("sizeof(*a) = %ld\n", sizeof(*a));
	printf("sizeof(a[0]) = %ld\n", sizeof(a[0]));

	int i, j;
	// for(i=0; i<3;i++)
 //		for(j=0; j<5;j++)
	 for(i=0; i<sizeof(a)/sizeof(*a);i++)
		for(j=0; j<sizeof(*a)/sizeof(int);j++)
			a[i][j] = i+j;

	for(i=0; i<sizeof(a)/sizeof(*a);i++){
		for(j=0; j<sizeof(*a)/sizeof(int);j++)
			printf("a[%d][%d]=%d ", i, j, a[i][j]);
			// printf("a[%d][%d]=%d ", i, j, *((*(a+i))+j));
			// printf("a[%d][%d]=%d ", i, j, *(&a[0][0]+5*i+j));
		printf("\n");
	}

	printf("Sum of all elements in a = %d\n", sum(a));
	printf("Sum of all elements in a = %d\n", sum2(a, 3));
	return 0;
}

