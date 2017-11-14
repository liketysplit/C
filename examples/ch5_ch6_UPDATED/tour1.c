#include <stdio.h>

typedef struct island_type{
	char *name;
	char *opens;
	char *closes;
	struct island_type *next;
}island;

void display(island *);

void display(island *start){
	island *i = start;
	for(; i != NULL; i=i->next){
		printf("Name: %-20s open: %s-%s\n", i->name, i->opens, i->closes);
	}
}

int main(){
	island shutter = {"Shutter", "09:00", "17:00", NULL};	
	island isla_nublar = {"Isla Nublar", "09:00", "17:00", &shutter};	
	island craggy = {"Craggy", "09:00", "17:00", &isla_nublar};	
	island amity = {"Amity", "09:00", "17:00", &craggy};	
	display(&amity);

	island skull = {"Skull", "09:00", "17:00", NULL};	
	isla_nublar.next = &skull;
	skull.next = &shutter;
	printf("---\n");
	display(&amity);

	isla_nublar.next = &shutter;
	printf("---\n");
	display(&amity);

	return 0;
}
