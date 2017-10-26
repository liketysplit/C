#include <stdio.h>
#include <math.h>
#include "encrypt.h"
#include "decrypt.h"

int num_of_function_calls;

int main(){
	char msg[80];

	num_of_function_calls = 1;
	while(fgets(msg, 80, stdin)){
		encrypt(msg);
		printf("%s\n", msg);
		printf("num_of_function_calls = %d\n", num_of_function_calls);
		decrypt(msg);
		printf("%s\n", msg);
		printf("num_of_function_calls = %d\n", num_of_function_calls);
	}
	printf("This is just to show how to use math functions. log(num_of_function_calls)=%f\n",
                log(num_of_function_calls));
        return 0;
}

