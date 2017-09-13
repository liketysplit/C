#include <stdio.h>
#include <limits.h>

void bit_print(int);
int pack(char, char, char, char);
char unpack(int, int);
unsigned getbits(unsigned, int, int);

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

int main(){
	int x = 145436546;

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

	return 0;
}

