#include "j.h"
#include "cl.h"

typedef struct soldier_type{
	char *name;
	struct soldier_type *next;
}soldier;


soldier *create(const char *name){
	soldier *s;
	if((s= malloc(sizeof(soldier)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}

	if((s->name= calloc(10, sizeof(char)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}
	strcpy(s->name, name);


	s->next = NULL;	

	return s;
}



int main(){

	void *start = NULL;
	void *cursor = NULL;
	soldier *n;
	char name[80];
	int kill;
	int countOfSoldiers = 0;

	for (; fgets(name, sizeof(name), stdin) != NULL ;){
		name[strlen(name)-1]='\0';
		if( (n=create(name))==NULL)
			return 1;
		start = insert(start,n);
		countOfSoldiers++; 		
	} 

	cursor = start;

	print(start);

  	fseek(stdin,0,SEEK_END);

	printf("\nWhat kill order do you want? ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1]='\0';
	kill = atoi(name);
	soldier *i;
	int count;

	while (countOfSoldiers!= 0){
		count =0;
		while(count < kill){
			if(count == kill-1 ){
				release(cursor);
				countOfSoldiers--;
				count++;
			}
			else{
				count++;
				cursor = (void *)advance(cursor);
			}

		}
	}
	
	return 0;
}
