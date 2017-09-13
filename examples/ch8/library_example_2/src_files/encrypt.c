#include "encrypt.h"

void encrypt(char *message){
	char c;
	while (*message){
		*message = *message ^ 15;
		message++;
	}
}
