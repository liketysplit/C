#include <stdio.h>

int main(){
	signed int i=-1;
	unsigned u=-1;

	if (i>>1 == u>>1)
		printf("Zeros are shifted in for >>.\n");
	else
		printf("Signed bits are shifted in for >>.\n");
	return 0;
}
