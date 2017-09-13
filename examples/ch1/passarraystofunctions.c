#include <stdio.h>

void func1(int [], int);
void func2(int *, int);

void func1(int x[], int n){
// Equivalently, void func1(int * x, int n){
	int i;
	for (i=0; i<n; i++)
		printf("%d ", x[i]);	
		//  Equivalently, printf("%d ", *(x+i));	

}

void func2(int x[], int n){
// Equivalently, void func2(int * x, int n){
	x=x+n-1;
	int i;
	for (i=0; i<n; i++)
		printf("%d ", *(x-i));	
		// Equivalently, printf("%d ", *(x-i));	
}

int main(){
	int a[]={1,2,3,4};
	func1(a, sizeof(a)/sizeof(a[0])); 
	printf("\n");
	func2(a, sizeof(a)/sizeof(a[0])); 

	return 0;
}
