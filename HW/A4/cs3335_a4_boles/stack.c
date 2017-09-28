#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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
	 
void push(double stack[], double item, double **top, int max_size){

	if(*top < (stack + (max_size))){
		**top = item;
		*top += 1;
		
	}
	if(*top == (stack + max_size))
		myerror = STACK_FULL;
	
}

double pop(double stack[], double **top){
    double temp;
	if(*top >= stack){
		*top -= 1;
		temp = **top;
	if(*top == stack)
		myerror = STACK_EMPTY;
	}
	
	return temp;

}

int main(){
        double s[STACK_SIZE];
        double *s_top = s;
        double temp;
        srand(time(NULL));

        while(myerror != STACK_FULL){
		temp = (rand()%94+33) + 0;
		printf("\nPushing: %1.1lf", temp);
		push( s, temp, &s_top, STACK_SIZE);
		}

		// for(int x=0;x<sizeof(s)/sizeof(double);x++)
		// 	printf("\n%1.2lf", s[x]);

		while(myerror != STACK_EMPTY){
		printf( "\nPopping: %1.1lf" ,pop( s, &s_top));
		}
 
        // Keep pushing doubles equivalent to chars randomly picked between '!'(33) and '~'(126) 
		// to the stack until it is full.
        // Print each double before each pushing.

        // Keep popping out doubles from the stack until it is empty
        // Print each double after each popping.

		// Repeat above until the user says 'no'.

		// Your code here...
	
        return 0;
}
