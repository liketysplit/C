#include <stdio.h>

typedef union {
	float weight;
	int count;
} cupcake;

int main(){
	cupcake order = {.weight = 2};
printf("sizeof(float)=%ld, sizeof(int)=%ld\n", sizeof(float), sizeof(int));
	// cupcake order = {2}; // This sets the value for the first feild.
	printf("Cupcake quantity: %i\n", order.count);
	
	return 0;
}
