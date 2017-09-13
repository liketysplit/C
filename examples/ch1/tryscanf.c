#include <stdio.h>
#include <string.h>

int main(){

	char name[20];
	printf("Enter your name: ");
	scanf("%19s", name);
	// scanf leaves '\n' in stdin.
	printf("Hi, %s\n", name);
	printf("strlen(name)=%ld\n", strlen(name));

	char food[20];
	printf("Enter favorite food: ");
	// scanf ignores '\n' left in stdin stream by the previous scanf
	scanf("%19s", food);
	printf("%s's favorite food is %s\n", name, food);

 	return 0;
}
