#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

# define MAX 10000
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0 
#define RADIANS( degrees ) ( degrees * M_PI / 180 )

char input[MAX];
double stack[MAX];
int myerror = NORMAL;

int top = -1;
double *s_top = NULL;

void push(double [], double, double **, int);
double pop(double [], double **); 
void valueCalc(); 
   
void push(double stack[], double item, double **top, int max_size){

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

double pop(double stack[], double **top){

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


void valueCalc(){
  char* s;
  s = strtok (input, " ");

    while (s != NULL){

      //push(stack, *s, &s_top, MAX);
      char *endptr;
      double temp = strtod(s,&endptr);
      double order;
      if (s != endptr && *endptr == '\0'){
        //printf("%lf\n", temp);
        push(stack, temp, &s_top, MAX);
      }
        
      else if(strcmp(s, "sin")==0){
           push(stack, sin(RADIANS(pop(stack, &s_top))), &s_top, MAX);
           break;
      }
      else if(strcmp(s, "cos")==0){
           push(stack, cos(RADIANS(pop(stack, &s_top))), &s_top, MAX);
           break;
      }
      else if(strcmp(s, "tan")==0){
           push(stack, tan(RADIANS(pop(stack, &s_top))), &s_top, MAX);
           break;
      }
      else if(strcmp(s, "log")==0){
           order = pop(stack, &s_top);
           order = log(order);
           push(stack, order, &s_top, MAX);
           break;
          }
         
        else{

        switch (*s) {

            case '+':
              push(stack, (pop(stack, &s_top) + pop(stack, &s_top)), &s_top, MAX);
              break;
            case '*':
              push(stack, (pop(stack, &s_top) * pop(stack, &s_top)), &s_top, MAX);
              break;
            case '-':
              order = pop(stack, &s_top);
              push(stack, (pop(stack, &s_top) - order), &s_top, MAX);
              break;
            case '$':
              order = pop(stack, &s_top);
              push(stack, (pow(pop(stack, &s_top), order)), &s_top, MAX);
              break;
            case '^':
              order = pop(stack, &s_top);
              push(stack, (pow(pop(stack, &s_top), order)), &s_top, MAX);
              break;   
            case '/':
              order = pop(stack, &s_top);
              push(stack, (pop(stack, &s_top) / order), &s_top, MAX);

              break;

            default:
              printf("\nError Unknown Argument Found: %s", s);
              break;
        }
      
      }

      s = strtok(NULL, " ");
    }
    printf("\nValue Calculated: %lf", pop(stack, &s_top));

 }   


int main(){

        printf("\nEnter a Postfix Expression - Operators Are (^ $ * + - / log sin cos tan): ");
        printf("\nYou will need a space after each value entered including the last entered for");
        printf("\nsin cos tan and log:");
        fgets(input , sizeof(input)/sizeof(char), stdin);

      while(strcmp(input,"")){
        valueCalc();
        printf("\nEnter a Postfix Expression - Operators Are (^ $ * + - / log sin cos tan): ");
        printf("\nYou will need a space after each value entered including the last entered for");
        printf("\nsin cos tan and log:");
        fgets(input , sizeof(input)/sizeof(char), stdin);

        
      }
      
      printf("\n");



      return 0;
}
