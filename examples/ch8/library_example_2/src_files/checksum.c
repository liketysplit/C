#include "checksum.h"

int checksum(char *message){
	char c;
	while (*message){
		c += c ^ (int)(*message);
		message++;
	}
	return c;
}
