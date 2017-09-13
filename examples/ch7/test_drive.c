#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_scores(const void *, const void *);
int compare_names(const void *, const void *);

typedef struct{
	int width;
	int height;
}rectangle;

int compare_areas(const void *, const void *);

// -- Done declarations

int compare_scores(const void *p_a, const void *p_b){
	int a = *(int *)p_a; 
	int b = *(int *)p_b; 
	return a-b;
}

int compare_names(const void *p_a, const void *p_b){
	char **a = (char **)p_a; 
	char **b = (char **)p_b; 
	return strcmp(*a, *b);
}

int compare_areas(const void *p_a, const void *p_b){
	rectangle *a = (rectangle *)p_a;
	rectangle *b = (rectangle *)p_b;

	int area_a = a->width * a->height;
	int area_b = b->width * b->height;
	return area_a - area_b;
}

int main(){
	int scores[] = {543, 323, 32, 554, 11, 3, 112};
	int i;
	qsort(scores, sizeof(scores)/sizeof(int), sizeof(int), compare_scores);
	puts("These are the scores in order: ");
	for (i=0; i<sizeof(scores)/sizeof(int); i++)
		printf("scores[%i] = %i\n", i, scores[i]);

	char *names[] = {"Karen", "Mark", "Brett", "Molly"};
	qsort(names, sizeof(names)/sizeof(char *), sizeof(char *), compare_names);
	puts("These are the names in order: ");
	for (i=0; i<sizeof(names)/sizeof(char *); i++)
		printf("names[%i] = %s\n", i, names[i]);

	rectangle rects[] = {{3,4}, {2,3}, {5,5}};
	qsort(rects, sizeof(rects)/sizeof(rectangle), sizeof(rectangle), compare_areas);
	puts("These are the rectangles in order of their areas: ");
	for (i=0; i<sizeof(rects)/sizeof(rectangle); i++)
		printf("rects[%i] = %i\n", i, rects[i].width * rects[i].height);
	return 0;
}
