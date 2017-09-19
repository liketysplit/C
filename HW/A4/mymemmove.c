#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mymemmove(void *, const void *, size_t);

int main(int argc, char *argv[])
{
  char x[30] = "That's not what I said.";
  char a[30] = "The original contents of a.";

  // "src" does not overlap "to"
  mymemmove(a, x, 24);
  puts(a); // prints "That's not what I said."

  // end of "to" overlaps beginning of "src"
  mymemmove(a+7, a+11, 13);
  puts(a); // prints "That's what I said."

  // end of "src" overlaps beginning of "to" 
  mymemmove(a+11, a+7, 13);
  puts(a); // prints "That's whatwhat I said."

  // "src" does not overlap "to"
  mymemmove(a+7, "not ", 4);
  puts(a); // prints "That's not what I said."

  double y[10], y_verify[10]; 

  int i; 
  for (i=0; i<10; i++){
    y[i] = (double)i/2;
    y_verify[i] = (double)i/2;
  }
  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }

  printf("--------\n");

  // "src" does not overlap "to"
  mymemmove(y, y+6, sizeof(double) * 3);
  memmove(y_verify, y_verify+6, sizeof(double) * 3);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: \"src\" does not overlap \"to\"\n");
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: \"src\" does not overlap \"to\"\n"); // Expected output
  printf("--------\n");

  // end of "to" overlaps beginning of "src"
  mymemmove(y+2, y+4, sizeof(double) * 4);
  memmove(y_verify+2, y_verify+4, sizeof(double) * 4);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: end of \"to\" overlaps beginning of \"src\"\n"); 
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: end of \"to\" overlaps beginning of \"src\"\n"); // Expected output
  printf("--------\n");

  // end of "src" overlaps beginning of "to" 
  mymemmove(y+4, y+2, sizeof(double) * 4);
  memmove(y_verify+4, y_verify+2, sizeof(double) * 4);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: end of \"src\" overlaps beginning of \"to\"\n"); 
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: end of \"src\" overlaps beginning of \"to\"\n"); // Expected output

  getchar();
  return 0;
}

void *mymemmove(void *to, const void *src, size_t n){
  return memmove(to, src, n);
  // Replece the return statement above with your implementation of the function...
}

