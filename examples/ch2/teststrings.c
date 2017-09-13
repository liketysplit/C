#include <stdio.h>
#include <string.h>

int main(){
	char x[][4]={"ab","cde","f"};

	int i=0;
	for (i=0; i<3; i++){
		printf("x[%d]=%s\n", i, x[i]);
	}
	return 0;
}
