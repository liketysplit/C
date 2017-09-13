// http://pubs.opengroup.org/onlinepubs/007904975/functions/strtod.html
#include <stdio.h>
#include <string.h>

int main(void){
	char s[]="What a nice whether!";
	char delim[]=" ";   // delimiter
	// char s[]="What  a \tnice \n whether!";
	// char delim[]=" \t\n";   // delimiter
	char *c;

	c = strtok(s, delim);

	while (c!=NULL){
		printf("Token: %s\n", c);
		c = strtok(NULL, delim);
	}
	return 0;
}
