#include <stdio.h>

void go_south_east_1(int, int);
void go_south_east_2(int *, int *);

void go_south_east_1(int lat, int lon){
	lat = lat -1;
	lon = lon +1;
}

void go_south_east_2(int *lat, int *lon){
	*lat = *lat -1;
	*lon = *lon +1;
}

int main(){
	int latitude = 32;
	int longitude = -64;
    go_south_east_1(latitude, longitude);
	//go_south_east_2(&latitude, &longitude);

	printf("Method 1: Avast! Now at:[%i, %i]\n", latitude, longitude);
    
	go_south_east_2(&latitude, &longitude);
	printf("Method 2: Avast! Now at:[%i, %i]\n", latitude, longitude);
	return 0;


}
