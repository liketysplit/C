#include <stdio.h>

typedef enum {DUMP, SECOND_CHANCE, MARRIAGE} response_type;
typedef struct{
	char *name;
	response_type type;
} response;

void dump(response);
void second_chance(response);
void marriage(response);

// -- Done declarations

void dump(response r){
	printf("Dear %s, you are dumped.\n", r.name);
}

void second_chance(response r){
	printf("Dear %s, you are given a second chance.\n", r.name);
}

void marriage(response r){
	printf("Dear %s, you will receive a proposal of marriage.\n", r.name);
}

int main(){
	response r[] = {{"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"Will", MARRIAGE}};

	int i;
	for (i=0; i<sizeof(r)/sizeof(response); i++){
		switch(r[i].type){
			case DUMP: 
				dump(r[i]);
				break;
			case SECOND_CHANCE: 
				second_chance(r[i]);
				break;
			case MARRIAGE: 
				marriage(r[i]);
				break;
		}
	}
	return 0;
}
