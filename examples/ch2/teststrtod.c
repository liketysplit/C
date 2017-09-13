// http://pubs.opengroup.org/onlinepubs/007904975/functions/strtod.html
#include <stdio.h>
#include <stdlib.h>

int main(void){
	char s[]="10.002";
	
	char *endptr;
	double temp = strtod(s,&endptr);
    	if (s != endptr && *endptr == '\0')
		printf("%lf\n", temp);
	else
		printf("Error\n");
	return 0;
}
