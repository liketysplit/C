#include <stdio.h>
#include <math.h>
#include <string.h>
#include "encrypt.h"
#include "decrypt.h"
#include "checksum.h"

int main(){
	char msg[80];

	puts("Please enter a message: ");
	while(fgets(msg, 80, stdin)){
		printf("------\n");
		msg[strlen(msg)-1] = '\0';
		printf("Checksum of the original %s is %i\n", msg, checksum(msg));
		printf("------\n");
		encrypt(msg);
		printf("Checksum of the encrypt %s is %i\n", msg, checksum(msg));
		printf("------\n");
		decrypt(msg);
		printf("%s\n", msg);
		printf("Checksum of the decrypted %s is %i\n", msg, checksum(msg));
		printf("------\n");
		puts("Please enter a message: ");
	}
	printf("------\n");
        return 0;
}

