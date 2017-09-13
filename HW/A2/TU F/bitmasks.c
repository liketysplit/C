#include <stdio.h>
#include <limits.h>

void bit_print(int);
int pack(char, char, char, char);
char unpack(int, int);
unsigned getbits(unsigned, int, int);
unsigned setbits (unsigned, int, int, unsigned);
unsigned invertbits (unsigned , int , int );

void bit_print(int a){
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n-1); // mask = 100...0
	
	for (i=1; i<=n; i++){
		putchar(((a & mask) == 0)? '0' : '1');
		a <<= 1;
		if (i % CHAR_BIT == 0 && i < n)
			putchar(' ');
	}
	putchar('\n');
}

int pack(char a, char b, char c, char d){
	int p=a;
	p = (p << CHAR_BIT) | b;
	p = (p << CHAR_BIT) | c;
	p = (p << CHAR_BIT) | d;
	return p;
}

char unpack(int p, int k){    // k=0, 1, 2, or 3
	int n = k * CHAR_BIT; // n = 0, 8, 16, 24
	unsigned mask = 255;  // mask = low-order byte
	
	mask <<= n;
	return ((p & mask) >> n);	
}

// getbits() extracts n bits from position p(start counting from the right-most bit) in x
unsigned getbits(unsigned x, int p, int n){
	unsigned temp = x >> (p+1-n);
	
	unsigned mask = 0;
	mask = ~mask;
	mask = mask << n;
	mask = ~mask;

	return temp & mask;
	// return (x >> (p+1-n)) & ~(~0<<n);
}
//-----------------------------------------------------------------------------
//-----------------------------------My Code-----------------------------------
//-----------------------------------------------------------------------------

//First Require method notes:
//returns x with the n bits that begin at position p (right-adjusted) set to the 
//rightmost n bits of y, leaving the other bits unchanged. Note: it does not change 
//the values of x and y though.
unsigned setbits (unsigned x, int p, int n, unsigned y) {

	unsigned temp = 0;
	unsigned tempX1 = x;
	unsigned tempX2 = x;
	unsigned tempY = y;

	//X Left
	tempX1 = tempX1 >> (p+1);
	tempX1 = tempX1 << (p+1);

	//X Right
	tempX2 = tempX2 << (p - (n+1));
	tempX2 = tempX2 >> (p - (n+1));

	//X Middle
	tempY =  tempY << (INT_MAX -n +1);	
	tempY =  tempY >> (INT_MAX -n +1);
	tempY =  tempY << (p-n+1);

	//Combine
	temp = (temp | tempX1);
	temp = (temp | tempY);
	temp = (temp | tempX2);
	

	return temp;

}

//Secound required method notes:
//returns x with the n bits that begin at position p (right-adjusted) inverted, i.e. 
//1 changed to 0 and vice versa, leaving the other bits unchanged. Note: it does not 
//change the value of x though
unsigned invertbits (unsigned x, int p, int n){

	unsigned tempXL = INT_MAX;
	unsigned temp2 = x;

	//Mask Left
	tempXL = tempXL << (INT_MAX-p);
	//Mask Right
	tempXL = tempXL >> ((INT_MAX-p)+(p-(n-1)));
	//Mask Position
	tempXL = tempXL << (p-(n-1));
	//Changes
	temp2 = (temp2 ^ tempXL);

	return temp2;

}

//-----------------------------------------------------------------------------
//-------------------------------End My Code-----------------------------------
//-----------------------------------------------------------------------------

int main(){
	int x = 19;

	printf("The binary rep. of %d is:\n", x);
	bit_print(x);

	int p=pack('w', 'x', 'y', 'z');
	printf("\n'w', 'x', 'y', and 'z' packed together is equal to %d. Its binary rep. is:\n", p);
	bit_print(p);
	printf("calling unpack(p, 0) to extract the byte # 0 from the right:\n");
	bit_print(unpack(p, 0));
	printf("calling unpack(p, 1) to extract the byte # 1 from the right:\n");
	bit_print(unpack(p, 1));
	printf("calling unpack(p, 2) to extract the byte # 2 from the right:\n");
	bit_print(unpack(p, 2));
	printf("calling unpack(p, 3) to extract the byte # 3 from the right:\n");
	bit_print(unpack(p, 3));

	unsigned result = getbits(p, 20, 7);
	printf("\ncalling getbits(p, 20, 7) to extract 7 bits from bit # 20 returns %d:\n", result);
	bit_print(result);

	printf("\nSet Bits\n");
	unsigned result2 = setbits (p, 20, 4, 238);
	bit_print(result2);
	printf("\nInvert Bits\n");
	unsigned result3 = invertbits (p, 29, 2);
	bit_print(result3);


	return 0;
}

