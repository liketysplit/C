#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include <ctype.h>
// #include <err.h>
// #include <errno.h>
int main(int argc, char *argv[]){
  // Get the options (-c, -d, -u, some combinations of them, or none at all)
  // ... ...

  // Figure out whether the input is comng from a file 
  // whose name is provided as a command line argument like
  //  myuniq -c -d sorteddepts.lst
  // or from the stdin like
  //  mycut .... | mysort ... | myuniq -c -d
  // ... ...

  // You may assume the input inFile are all sorted.
  // Read and record two lines (if any) from input and compare them.
  // Let's call them prev and curr.
  // If they are the same, update the number of repeats;
  // If they are different, output the prev according the options (-c, -d, or -u)
  // Keey doing this until hitting the end of the input. 
  // ... ...

        //Variables
        const char *delivery = "";
        int count = 0, dup = 0, uniq = 0, fileProc = 0, num = 1;
        char ch;
        FILE *inFile;
        
        //
        while((ch  = getopt(argc, argv, "cdu"))!= EOF ){
                switch(ch){
                        case 'c': //count Arg
                                count = 1;
                                break;

                        case 'd': //duplicate Arg
                                dup = 1;
                                break;

                        case 'u': //uniq Arg
                                 uniq = 1;
                                break;

                        default:
                                fprintf(stderr, "unknown option: '%s'\n", optarg);
                                return 1;
                }//End Switch
        }//End While for Args

        //Close used Args
        argc -= optind;
        argv += optind;

        if(uniq == 1 && dup == 1){
            printf("\nInvalid Option: -d -u can not co-exist for uniq");
            printf("\n");
            return 0;
        }

        //Determine if taking stdin or file
        switch(argc){
          case 0:
            inFile = stdin;
            break;
          case 1:
            inFile = fopen(argv[fileProc],"r");
            break;
          default:
            printf("\nNeeds stdin passed in sorted with | or a file as an Arg");
        }

        char prev[1000];
        char curr[1000];
        fgets(prev, sizeof(prev)/sizeof(char), inFile);
        prev[strlen(prev)-1] = '\0';
        while(fgets(curr, sizeof(curr)/sizeof(char), inFile) != NULL){
                curr[strlen(curr)-1] = '\0';

                if(strcmp(prev,curr)==0){ //Collects Count
                        num++;
                }
                else{

                  if(count && num > 1 && !uniq){ //Prints counted number providing not uniq and count is asked for
                          printf("\n%d ",num);
                  }

                  if(dup && !uniq && !count) //Prints one copy of a duplicate string without count
                    if(num > 1)
                    printf("\n%s", prev);

                  if(dup && !uniq && count) //Prints one copy of a duplicate string with count already printed
                    if(num > 1)
                    printf("%s", prev);

                  if(uniq){ //Prints out uniq no regards to count one way or the other
                    if(num == 1){
                      printf("\n%s", prev);
                    }
                  }

                  num = 1;
                  strcpy(prev,curr);
                }

        }

        //Grabs the last set of Lines
        //Used as a work around might could have done with a do while
        if(num != 0){
          if(count && num > 1 && !uniq){ //Prints counted number providing not uniq and count is asked for
            printf("\n%d ",num);
          }

          if(dup&& !uniq && !count){ //Prints one copy of a duplicate string without count
            if(num > 1){
              printf("\n%s", prev);
            }
          }

          if(dup && !uniq && count){ //Prints one copy of a duplicate string with count already printed
            if(num > 1){
              printf("%s", prev);
            }
          }

          if(uniq) //Prints out uniq no regards to count one way or the other
            if(num == 1)
              printf("\n%s", prev);
          }

        printf("\n");

        return 0;
}