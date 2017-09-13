#include <stdio.h>
#include <limits.h>

int main(){
	// Won't work
	// unsigned char c;

	// Will work. signed char, char will do too.
	int c;

	// To find out if char is signed or unsigned by default
	printf ("CHAR_MIN=%d\n", CHAR_MIN);

	printf("sizeof(EOF) = %ld\n", sizeof(EOF));

	do{
		c=getchar();
	}while (c!=EOF);

	return 0;
}
