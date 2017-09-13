#include <stdio.h>

typedef union quantity_type {
	short count;
	float weight;
	float volume;
} quantity;

typedef struct fruit_order_type {
	const char *name;
	const char *state;
	quantity amount;
} fruit_order;

int main(){
	fruit_order apples = {"apples", "CA", .amount.weight=4.2};	
	fruit_order oranges = {"oranges", "GA", .amount.count=5};	
	
	/*printf("sizeof(apples.amount.count) = %li\n", sizeof(apples.amount.count));
	printf("sizeof(apples.amount.weight) = %li\n", sizeof(apples.amount.weight));
	printf("sizeof(apples.amount) = %li\n", sizeof(apples.amount));
	printf("sizeof(apples.name) = %li\n", sizeof(apples.name));
	printf("sizeof(fruit_order) = %li\n", sizeof(fruit_order));*/
	printf("sizeof(apples) = %li\n", sizeof(apples));
	return 0;
}
