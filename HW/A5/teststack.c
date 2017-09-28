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
	 
void push(double stack[],
	double item,
	double **top,
	int max_size){

	if(*top < stack + (max_size-1)){
        if (*top==NULL)
            *top = stack;
        else
            ++(*top);
		**top = item;
		myerror = NORMAL;
	}
	else
		myerror = STACK_FULL;
}

double pop(double stack[],
	double **top){

	double item;
	if (*top != NULL){
		item = **top;
        if (*top == stack)
            *top = NULL;
        else
            --(*top);
		myerror = NORMAL; 
	}
	else{
		item = STACK_EMPTY; // not used when myerror is not NORMAL
		myerror = STACK_EMPTY;
	}

	return item;
}

int main(){
        double s[STACK_SIZE];
        double *s_top = NULL;

        srand(time(NULL));

        // (Using a loop) Keep pushing doubles equivalent to chars randomly picked between '!'(33) and '~'(126) to the stack
        // until it is full.
        // Print each double before each pushing.
    
    char cont[] = "y";
    do{
        //printf("--------------First Round-----------\n");
        double temp = (double)33; //'!'
        do{
                double c = (double)(temp+rand()%94);
                printf("Push: %lf\n", c);
                push(s, c, &s_top, STACK_SIZE);
        } while(myerror != STACK_FULL);

        printf("--------------Last item didn't get pushed into the stack because it was full.-----------\n");

        // (Using a loop) Keep popping out doubles from the stack until it is empty
        // Print each double after each popping.
        double t;
        do{
                t=pop(s, &s_top);
                if(myerror!=STACK_EMPTY)
                        printf("Pop: %lf\n", t);
        }while(myerror!=STACK_EMPTY);
        
        printf("Continue (y/n)? ");
        scanf("%1s",cont);
    }while (cont[0]=='y');
    

        return 0;
}
