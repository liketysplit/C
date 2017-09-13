#include <stdio.h>

// void fortune(char msg[]){
void fortune(char *msg){
	printf("msg: %s\n", msg);
	printf("sizeof(msg): %ld\n", sizeof(msg));

}

int main(void){
	char quote[]="Cookies make you fat";
	fortune(quote);
	return 0;
}
