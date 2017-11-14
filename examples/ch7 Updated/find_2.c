#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;
char *ADS[] = {
	"William: SBM GSOH likes sports, TV, and dining",
	"Matt: SWM NS likes art, movies, and theater",
	"Luis: SLM ND likes books, theater, and art",
	"Mike: DWM DS likes trucks, sports, and bieber",
	"Peter: SAM likes chess, working out, and art",
	"Josh: SJM likes sports, movies, and theater",
	"Jed: DBM likes theater, books, and dining"
};

// criteria needs to be formatted in "xxx and yyy"
void find(const char *criteria);

void find(const char *criteria){
	char p1[20], p2[20];
	if (sscanf(criteria, "%s and %s", p1, p2)!=2) 
		return;
	
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if ( strstr(ADS[i], p1)
			&& strstr(ADS[i], p2) )
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

int main(){
	find("sports and dining");
	find("sports and TV");
	
	return 0;
}
