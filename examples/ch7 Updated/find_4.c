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

int sports_and_no_bieber(char *);
int sports_or_working_out(char *);
int theater(char *);
int art_or_theater_or_dining(char *);
void find ( int (*)(char *) );


int sports_and_no_bieber(char *s){
	return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_working_out(char *s){
	return strstr(s, "sports") || strstr(s, "working out");
}

int theater(char *s){
	if( strstr(s, "theater") )
		return 1;
	else
		return 0;
}

int art_or_theater_or_dining(char *s){
	return strstr(s, "art") || strstr(s, "theater") || strstr(s, "dining");
}

void find ( int (*match)(char *) ){
	int i;
	puts("Search results: ");
	puts("------------------------");
	for (i=0; i<NUM_ADS; i++){
		if (match(ADS[i]))
			printf("%s\n", ADS[i]);
	}
	puts("------------------------");
}

int main(){
	find(sports_and_no_bieber);
	find(sports_or_working_out);
	find(theater);
	find(art_or_theater_or_dining);
	
	return 0;
}
