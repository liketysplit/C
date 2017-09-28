// How to compile: gcc testsin.c -lm -o testsin

#include <stdio.h>
#include <math.h>

#define RADIANS( degrees ) ( degrees * M_PI / 180 )

int main(void){
	double angle;	

	printf("Please provide angle in degree: ");
	while(scanf("%lf", &angle)!=EOF){
		printf("sine of %lf degrees is %lf\n", angle, sin(RADIANS(angle)) );	
		printf("Please provide angle in degree: ");
	}
	return 0;
}
