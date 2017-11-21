#include "main.h"

card *create(int num){ 
	
	card *c;
	if((c= malloc(sizeof(card)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}

	if((c->name= calloc(10, sizeof(char)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}

	if(num<15&&num>1){
		c->suit = Clubs;
	}

	if (num<28&&num>14){
		num -= 13;
		c->suit = Diamonds;
	}

	if (num<41&&num>27){
		num -= 26;
		c->suit = Hearts;

	}

	if (num<54&&num>40){
		c->suit = Spades;
		num -= 39;

	}

		if(num == 14){
			c->name = Ace;
		}

		if(num == 13){
			c->name = King;
		}

		if(num == 12){
			c->name = Queen;
		}

		if(num == 11){
			c->name = Jack;
		}

		if(num == 10){
			c->name = Ten;
		}

		if(num == 9){
			c->name = Nine;
		}

		if(num == 8){
			c->name = Eight;
		}

		if(num == 7){
			c->name = Seven;
		}

		if(num == 6){
			c->name = Six;
		}

		if(num == 5){
			c->name = Five;
		}

		if(num == 4){
			c->name = Four;
		}

		if(num == 3){
			c->name = Three;
		}

		if(num == 2){
			c->name = Two;
		}

	return c;
}



int main(){

	card *hand[10];
	int numbers[10];
	int *temp;
	int i;
	card *tc;

	for (i=0;i<10;i++){
		temp = rCard(numbers);
		tc = create(temp);
		hand[i] = tc;
		numbers[i] = temp;	
	} 

	qsort (hand, sizeof(hand)/sizeof(card), sizeof(card), compare);
	printf("\nHere is a 10 card random hand that was dealt by the machine\n\n");
	for (i=0;i<10;i++){
		char cardname [10];
		char *x = cardname; 
		char cardsuit [10];
		char *y = cardsuit;

		if(hand[i]->suit == 18){
			y = "Clubs";
		}

		if (hand[i]->suit == 17){
			y = "Diamonds";
		}

		if (hand[i]->suit == 16){
			y = "Hearts";
		}

		if (hand[i]->suit == 15){
			y = "Spades";
		}

		if (hand[i]->name == 14){
			x = "Ace";
		}

		if (hand[i]->name == 13){
			x = "King";
		}

		if (hand[i]->name == 12){
			x = "Queen";
		}

		if (hand[i]->name == 11){
			x = "Jack";
		}

		if (hand[i]->name == 10){
			x = "10";
		}

		if (hand[i]->name == 9){
			x = "9";
		}

		if (hand[i]->name == 8){
			x = "8";
		}

		if (hand[i]->name == 7){
			x = "7";
		}

		if (hand[i]->name == 6){
			x = "6";
		}

		if (hand[i]->name == 5){
			x = "5";
		}

		if (hand[i]->name == 4){
			x = "4";
		}

		if (hand[i]->name == 3){
			x = "3";
		}

		if (hand[i]->name == 2){
			x = "2";
		}

		printf("Card %2d: %5s of %-7s\n",i+1,x,y);		
	}
	printf("\n");
 
	return 0;
}
