#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 	10

#define STACK_FULL      -2
#define STACK_EMPTY 	-1
#define NORMAL          0

int myerror = NORMAL;

void push(double [],	// input/ouput - the stack
	  double,	// input - data being pushed onto the stack
	  double **,	// input/output - pointer to pointer to the top of stack
	  int);		// constant - maximum capacity of stack

double			// output - data being popped out from the stack
     pop(double [],	// input/output - the stack
	 double **);	// input/output - pointer to pointer to top of stack
	 
void push(double stack[],
	double item,
	double **top,
	int max_size){

	// Your code here...
}

double pop(double stack[],
	double **top){

	// Your code here...
	return 0.0;
}

int main(){
        double s[STACK_SIZE];
        double *s_top = NULL;

        srand(time(NULL));

        // Keep pushing doubles equivalent to chars randomly picked between '!'(33) and '~'(126) 
	// to the stack until it is full.
        // Print each double before each pushing.

        // Keep popping out doubles from the stack until it is empty
        // Print each double after each popping.

	// Repeat above until the user says 'no'.

	// Your code here...
	
        return 0;
}
