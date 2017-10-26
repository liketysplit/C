#include <stdio.h>
#include "encrypt.h" // This can be skipped since it is included in decrypt.h
#include "decrypt.h"

int main(){
	char msg[80];

	while(fgets(msg, 80, stdin)){
		encrypt(msg);
		printf("%s\n", msg);
		decrypt(msg);
		printf("%s\n", msg);
	}
}

