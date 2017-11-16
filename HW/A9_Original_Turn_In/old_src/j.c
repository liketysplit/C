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
	//printf("kill order%d\n", kill);
	while (countOfSoldiers!= 0){
		//printf("Outer Whileloop Ran\n");
		//printf("Number of soldiers%d\n", countOfSoldiers);
		count =0;
		while(count < kill){
			//printf("Inner Whileloop Ran\n");
			if(count == kill-1 ){//&& cursor->next != NULL){
				//printf("count: %d\n", count);
				//printf("kill order: %d\n", kill);
				release(cursor);
				countOfSoldiers--;
				count++;
			}
			else{
				//printf("count: %d\n", count);
				count++;
				cursor = (void *)advance(cursor);
			}

		}
	}

	// if(start == NULL){
	// 	printf("Empty list.\n");
	// }
 // 	else{

	// 	soldier *i = cursor;
	// 	for(; i != NULL; i=i->next){
	// 		printf("%s\t", i->name);
	// 	}
	// }


 
	return 0;
}
