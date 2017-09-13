#include <stdio.h>
#include "encrypt.h" // This can be skipped since it is included in decrypt.h
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
}

