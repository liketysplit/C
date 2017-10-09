#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// 	// Gather the command line arguments (options included) and combine them in one string.
// 	// Create a command string that begins with "cut ", followed by the argument string above. 
// 	// Finally replace the hardwired "cut ...." in the following system call with your command string.  
// 	// system("cut -d! -f3 emp.lst");


int main(int argc, char *argv[]) {
    int i; 
    int sizeArguments = argc-1;


    char *str = (char *)malloc(100);
    strcat(str , "cut ");




    for(i = 1; i <= sizeArguments; i++) {
        strcat(str, argv[i]);
        strcat(str, " ");
    }

    system(str);
    return 0;
}