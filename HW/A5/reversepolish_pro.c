#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

# define MAX 1000
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0 
#define RADIANS( degrees ) ( degrees * M_PI / 180 )

char input[MAX];
double stack[MAX];
int myerror = NORMAL;

int top = -1;
double *s_top = NULL;
double lv;
double count;

void push(double [], double, double **, int);
double pop(double [], double **); 
void valueCalc(); 

bool valid = true;
bool ops = true;
   
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
  if(*top <= stack)
      myerror = STACK_EMPTY;

  return item;
}


void valueCalc(){

  // printf("\nEnter a Postfix Expression: ");
  // fgets(input , MAX, stdin);
  count = 0;
  char* s;
  strcat(input," ");
  s = strtok (input, " ");

  while (myerror!= STACK_EMPTY)
      pop(stack, &s_top);


    while (s != NULL){
      valid = true;
      //push(stack, *s, &s_top, MAX);
      char *endptr;
      double temp = strtod(s,&endptr);
      double order;
      ops=true;
      if (s != endptr && *endptr == '\0'){
        //printf("%lf\n", temp);
        push(stack, temp, &s_top, MAX);
        count++;
      }
      
  
      else if(strcmp(s, "sin")==0){
           order = pop(stack, &s_top);
           push(stack, sin(RADIANS(order)), &s_top, MAX);
           ops = false;
           break;
      }
      else if(strcmp(s, "cos")==0){
           push(stack, cos(RADIANS(pop(stack, &s_top))), &s_top, MAX);
           ops = false;
           break;
      }
      else if(strcmp(s, "tan")==0){
           push(stack, tan(RADIANS(pop(stack, &s_top))), &s_top, MAX);
           ops = false;
           break;
      }
      else if(strcmp(s, "log")==0){
           order = pop(stack, &s_top);
           if(order!=0){
           push(stack, log(order), &s_top, MAX);
           ops = false;
           }
           else{
             printf("%s\n", "Error: Cannot Take Log of 0");
             valid = false;
             break;
           }
           break;
      }
         
        else{


        if(count>1){
        switch (*s) {

            case '+':
              push(stack, (pop(stack, &s_top) + pop(stack, &s_top)), &s_top, MAX);
              count--;
              break;
            case '*':
              push(stack, (pop(stack, &s_top) * pop(stack, &s_top)), &s_top, MAX);
              count--;
              break;
            case '-':
              order = pop(stack, &s_top);
              push(stack, (pop(stack, &s_top) - order), &s_top, MAX);
              count--;
              break;
            case '$':
              order = pop(stack, &s_top);
              push(stack, (pow(pop(stack, &s_top), order)), &s_top, MAX);
              count--;
              break;
            case '^':
              order = pop(stack, &s_top);
              push(stack, (pow(pop(stack, &s_top), order)), &s_top, MAX);
              count--;
              break;  
            case '/':
              order = pop(stack, &s_top);
              count--;
              if (order != 0.0)
              push(stack, (pop(stack, &s_top) / order), &s_top, MAX);
              else{
                   printf("\nError: Cannot divide by Zero");
                   valid = false;
                 }
              break;

            default:
              printf("\nError: Unknown Argument: %s", s);
              valid = false;
              break;
        }
      }
      else if(ops){
        valid = false;
        printf("%s\n", "Too Many Operators");
        break;
      }
      
      }

      s = strtok(NULL, " ");
    }

    if(myerror != STACK_EMPTY){
      lv = pop(stack, &s_top);
    }
    if(count != 1 && valid){
      printf("\n%s", "Error: Operands Left Over On The Stack");
      valid = false;
    }

    if(valid)
      printf("\nValue Calculated: %lf", lv);
    
 }   

 
 
int main(){

        printf("\nEnter a Postfix Expression - Operators Are (^ $ * + - / log sin cos tan): ");
        fgets(input , sizeof(input)/sizeof(char), stdin);
        input[strlen(input)-1] = '\0';

      while(strcmp(input,"")){
        valueCalc();
        printf("\nEnter a Postfix Expression - Operators Are (^ $ * + - / log sin cos tan): ");
        fgets(input , sizeof(input), stdin);
        input[strlen(input)-1] = '\0';
        
      }
      
      printf("\n");



      return 0;
}