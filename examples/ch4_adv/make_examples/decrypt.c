#include "decrypt.h"
#include "encrypt.h"

extern int num_of_function_calls;
// static int num_of_function_calls;

void decrypt(char *message){
	encrypt(message);
	num_of_function_calls ++;
}
