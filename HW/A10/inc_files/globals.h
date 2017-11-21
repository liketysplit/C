#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sort.h>
#include <time.h>
#include <unistd.h>

typedef enum{
	Two=2,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace
}face;

typedef enum{
	Spades=15,Hearts,Diamonds,Clubs 
}suit;

typedef struct card_type{
	int name;
	int suit;
}card;