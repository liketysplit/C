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

void find_sports_and_no_bieber();
void find_sports_or_working_out();
void find_theater();
void find_art_or_theater_or_dining();

void find_sports_and_no_bieber(){
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if ( strstr(ADS[i], "sports")
			&& ! strstr(ADS[i], "bieber") )
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

void find_sports_or_working_out(){
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if ( strstr(ADS[i], "sports")
			|| strstr(ADS[i], "working out") )
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

void find_theater(){
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if ( strstr(ADS[i], "theater") )
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

void find_art_or_theater_or_dining(){
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if ( strstr(ADS[i], "art")
			|| strstr(ADS[i], "theater") 
			|| strstr(ADS[i], "dining") )
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

int main(){
	find_sports_and_no_bieber();
	find_sports_or_working_out();
	find_theater();
	find_art_or_theater_or_dining();
	
	return 0;
}
