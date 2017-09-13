#include <stdio.h>
#include <string.h>

int main(){

	char name[20];
	printf("Enter your name: ");

	// fgets consumes '\n' from stdin, places it in name, then adds '\0' at the end of name. 
	fgets(name, sizeof(name), stdin);
	// This is to replace '\n' with '\0' in name.
	name[strlen(name)-1] = '\0';
	printf("Hi, %s\n", name);

	char food[20];
	printf("Enter favorite food: ");
	fgets(food, sizeof(food), stdin);
	food[strlen(food)-1] = '\0';
	printf("%s's favorite food is %s\n", name, food);

 	return 0;
}
