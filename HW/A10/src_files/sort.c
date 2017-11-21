#include "sort.h"
#include "globals.h" 

int compare(const void *a, const void *b){

    const card *card1 = *(card **)a;
    const card *card2 = *(card **)b;
    int q = card1->name;
    int w = card2->name;
    int e = card1->suit;
    int r = card2->suit;

    //Different card face value
    if (q < w)
        return 1;
    else if (q > w)
        return (-1);

    //Same Value Determine by Suit
    else if (q==w){

    	if (e < r)
        	return 1;
    	else if (e > r)
        	return (-1);
    
    }

    
}
