#include <stdio.h>

struct fish {
	const char *name;
	const char *species;
	int teeth;
	int age;
};

void catalog(struct fish);
void happy_birthday(struct fish);
void happy_birthday2(struct fish *);

void catalog(struct fish f){
	printf("%s is a %s with %i teeth. He is %i.\n",
		f.name, f.species, f.teeth, f.age);
}

// This function will not work.
void happy_birthday(struct fish f){
	f.age = f.age + 1;
	printf("Happy B-day %s! You are now %i years old!\n", f.name, f.age);

}

void happy_birthday2(struct fish *f){
	f->age = f->age + 1;
	printf("Happy B-day %s! You are now %i years old!\n", f->name, f->age);
}

int main(){
	struct fish snappy = {"Snappy", "Piranha", 69, 4};
 	catalog(snappy); 

	happy_birthday(snappy);
	printf("%s is %i years old now.\n", snappy.name, snappy.age);

	happy_birthday2(&snappy);
	printf("%s is %i years old now.\n", snappy.name, snappy.age);

	return 0;
}
