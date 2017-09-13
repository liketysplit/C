#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island_type{
	char *name;
	char *opens;
	char *closes;
	struct island_type *next;
}island;

void display(island *);

island *create(const char *);

// insert_end(h, n) inserts *n at the end of the linked list headed at h and returns the new head 
island *insert_end(island *, island *);
// insert_head(h, n) inserts *n at the head of the linked list headed at h and returns the new head 
island *insert_head(island *, island *);
// insert_after(w, n) inserts *n after *w in the linked list (assuming *w is somewhere in the list)
void insert_after(island *, island *);

// find(h, n) searches for the first record whose name is n in the linked list headed at h and returns 
// a pointer to that record. If not found, it returns NULL. 
island *find(island *, const char *);

// release(h, name) removes the first record whose name is name (if found) from the linked list headed at h
// and returns the new head. 
island *release(island *, const char *);

void display(island *start){
	if(start == NULL){
		printf("Empty list.\n");
	}
 	else{

		island *i = start;
		for(; i != NULL; i=i->next){
			printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
		}
	}
}

island *create(const char *name){
	island *i;
	if((i= malloc(sizeof(island)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}
	
	// The following is correct.
	i->name = strdup(name);
	// The following is wrong.
	// i->name = name;

	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;	

	return i;
}

// insert_end(h, n) inserts *n at the end of the linked list headed at h and returns the new head 
island *insert_end(island *h, island *n){
	if (h==NULL)
		return n;
	else {
		island *t = h;
		for(; t->next != NULL; t=t->next);

		t->next = n;
		return h;
	}
}

// insert_head(h, n) inserts *n at the head of the linked list headed at h and returns the new head 
island *insert_head(island *h, island *n){
	n->next = h;
	return n;
}

// insert_after(w, n) inserts *n after *w in the linked list (assuming *w is somewhere in the list)
void insert_after(island *w, island *n){
	w->next = n;
	n->next = w->next;
}

// find(h, n) searches for the first record whose name is n in the linked list headed at h and returns 
// a pointer to that record. If not found, it returns NULL. 
island *find(island *h, const char *name){
	if (h==NULL)
		return NULL;
	else {
		island *t = h;
		while( t != NULL ){
			if(strcmp(t->name, name) == 0)
				return t; // found it
			else
				t = t->next;
		}
		// not found
		return t;
		
	}
}

// release(h, name) removes the first record whose name is name (if found) from the linked list headed at h
// and returns the new head. 
island *release(island *h, const char *name){
	if (h==NULL)
		return NULL;
	else if (strcmp(h->name, name) == 0) {
		island *t=h;
		t=t->next;
		free(h->name);
		free(h);
		return t;
	}
	else{
		island *pre = h;
		island *n = pre->next;
		while( n != NULL ){
			if(strcmp(n->name, name) == 0){ // found it
				pre->next = n->next;
				free (n->name);
				free (n);
				return h;
			}
			else{
				pre = n;
				n = n->next;
			}
		}
		return h; // not found
	}
}

int main(){
	island *start = NULL;
	island *n;
	char name[80];
	for (; fgets(name, sizeof(name), stdin) != NULL ;){
		name[strlen(name)-1]='\0';
		if( (n=create(name))==NULL)
			return 1;
		start = insert_end(start,n); 		
	} 
	display(start);

	printf("\nWhat do you want to find? ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1]='\0';
	island *i;
	if( (i=find(start, name)) == NULL)
		printf("Not found.\n");
	else{
		printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes); 
		printf("\nWhat do you want to insert after %s? ", name);
		fgets(name, sizeof(name), stdin);
		name[strlen(name)-1]='\0';
		if( (n=create(name))==NULL)
			return 1;
		insert_after(i,n); 
	}
	display(start);
	
	printf("\nWhat do you want to remove? ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1]='\0';
	start =release(start, name);
	display(start);

	return 0;
}
