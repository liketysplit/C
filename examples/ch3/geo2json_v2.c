#include <stdio.h>

int main(){
	float latitude;
	float longitude;
	char info[80];
	int started = 0;
	FILE *ifp, *ofp;

	ifp = fopen("gpsdata.csv", "r");
	ofp = fopen("output.json", "w");

	fputs("data=[\n", ofp);
	while(fscanf(ifp, "%f, %f, %79[^\n]", &latitude, &longitude, info)==3){
		if (started)
			fprintf(ofp, ",\n");
		else
			started = 1;
		fprintf(ofp, "{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info); 
	}
	fputs("\n]\n", ofp);
	
	fclose(ifp);
	fclose(ofp);
	return 0;
}
