#include <stdio.h>

int main(){
	double d=10.34, *p;
	p = &d;
	printf("a=%lf\n", *p);
	printf("sizeof(d)=%ld\n", sizeof(*p));
	printf("p=%p\n", p);
	printf("sizeof(p)=%ld\n", sizeof(p));
	printf("address of p=%p\n", &p);

	// printf("\nProvid a new value for d: ");
	// scanf("%lf", &d);
	// scanf("%lf", p);
	*p = 30.2;
	printf("d=%lf\n", *p);
	printf("sizeof(d)=%ld\n", sizeof(*p));
	printf("p=%p\n", p);
	printf("sizeof(p)=%ld\n", sizeof(p));
	printf("address of p=%p\n", &p);
	
	p=NULL;
}
