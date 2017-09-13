// This example show the complexities when scanf and fgets are mixed.
#include <stdio.h>
#include <string.h>
#include <string.h>

int main(){
	char name[20];
	printf("Enter your name: ");
	scanf("%19s", name);
	// scanf leaves '\n' in stdin.
	printf("Hi, %s\n", name);
	printf("strlen(name)=%ld\n", strlen(name));

	// '\n' that scanf left in stream will prevent fgets below from working. 
	// We need to remove it from the stream before calling fgets
 	scanf("%*c");	
 	// getchar();
	 
	char food[20];
	printf("Enter favorite food: ");
	fgets(food, sizeof(food), stdin);
	food[strlen(food)-1]='\0';
	printf("%s's favorite food is %s\n", name, food);

 	return 0;
}
