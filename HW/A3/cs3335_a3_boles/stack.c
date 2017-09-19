#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1

void push(char [], // input/ouput - the stack
	  char,	   // input - data being pushed onto the stack
	  int *,   // input/output - pointer to the ***index*** of the top of stack
	  int);    // constant - maximum size of stack

char		   // output - data being popped out from the stack
     pop(char [],  // input/output - the stack
	 int *);   // input/output - pointer to the ***index*** of the top of stack

void push(char stack[], char item, int *top, int max_size){
	if(*top < max_size-1){
		stack[*top+1] = item;
		*top += 1;
	}

	// Your code here ...
	// Push item to the top of stack if it's not full. 
	// Update the top pointer s/t it points to the index of the new top element on the stack.
}

char pop(char stack[], int *top){
	if(*top != -1){
		*top -= 1;
		return stack[*top+1];
	}
		
	else
		return STACK_EMPTY;

	// Your code here ...
	// Pop out the top item on the stack and return it if the stack is not emtpy.
	// Update the top pointer s/t it points to the index of the new top element on the stack. 
	// 
	// Return STACK_EMPTY if the stack is empty. 
}

int main(){
	char s[STACK_SIZE];
	int s_top = STACK_EMPTY; // The ***index*** of the top of the stack
	char temp = 'x';
	srand(time(NULL));

	
	for(int i = 0; i < STACK_SIZE; i++){
		temp = (rand()%94+33) + 0;
		printf("\nPushing: %1c", temp);
		push( s, temp, &s_top, STACK_SIZE);
	}
	// push( s, temp, &s_top, STACK_SIZE);

	// printf("\n%1c", s[s_top]);
	// Your code here ...
	// (Using a loop) Keep pushing chars randomly picked between '!'(33) and '~'(126) to the stack
	// until it is full. You will find the function rand() useful here. In case you are not familiar
    // with it, man it.
	// Print each char before each pushing.

	for(int i = 0; i < STACK_SIZE; i++){
		printf( "\nPopping: %1c" ,pop( s, &s_top));
	}

	// printf("\n-----------\n");

	// printf( "%1c" , pop( s, &s_top));

	// printf("\n%1c", s[s_top]);

	// Your code here ...
	// (Using a loop) Keep popping out chars from the stack until it is empty
	// Print each char after each popping. 



	return 0;
}

	//test code for output problem 1

	// int SIZE = 100;
	// char a[SIZE], *p=a;
	// int i;


	// for (i = 0; i < SIZE; i++)
	// a[i] = i;


	// int tempx = sizeof(char);
	// printf("%d\n", tempx);
	// tempx = sizeof(int);
	// printf("%d\n", tempx);
	// tempx = sizeof(double);
	// printf("%d\n", tempx);
	// tempx = sizeof(long double);
	// printf("%d\n", tempx);

	// printf( "%d\n", *(p+3) );
	// printf( "%d\n", *(char *)((int *)p+3) );
	// printf( "%d\n", *(char *)((double *)p+3) );
	// printf( "%d\n", *(char *)((long double *)p+3) );


