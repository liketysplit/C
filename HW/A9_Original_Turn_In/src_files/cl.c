#include "cl.h"
#include "j.h"

typedef struct soldier_type{
	char *name;
	struct soldier_type *next;
}soldier;

void *start;

void print(void *cursor){
	if(cursor == NULL){
		printf("Empty list.\n");
	}
 	else{

		soldier *i = cursor;
		for(; i != NULL; i=i->next){
			printf("%-10s", i->name);
			if(i->next==NULL){
				i->next = cursor;
				break;
			}
		}
	}
}

void * insert(void *cursor, void *name){

	if (cursor==NULL)
		return name;
	else {
		soldier *t = cursor;
		for(; t->next != NULL; t=t->next);

		t->next = name;
		return cursor;
	}

}

void *advance(void *cursor){
	soldier *pre = cursor;
 	return (void *)pre->next;
}

void *release(void *cursor){
		soldier *pre = cursor;
		soldier *n = pre->next;
		pre->next = n->next;
		printf("%15s is Dead!\n", n->name);
		free (n->name);
		free (n);
		return pre;	
}