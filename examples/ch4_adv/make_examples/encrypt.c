#include "encrypt.h"

extern int num_of_function_calls;

void encrypt(char *message){
	char c;
	while (*message){
		*message = *message ^ 31;
		message++;
	}
	num_of_function_calls ++;
}
