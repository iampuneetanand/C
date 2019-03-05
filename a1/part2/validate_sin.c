#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.

    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.

  int sin_number = strtol(argv[1], NULL, 10); //saves first arg
  int sin_arr[9];
  //next to check if sin_number is a real sin value
  if ((sin_number <= 999999999) && (sin_number >= 100000000)){
  	populate_array(sin_number, sin_arr); //if so populate the array
  }
  if (argc == 2){ //if only 1 command line arg provided
  	if (check_sin(sin_arr) == 0){  //if check passes -> valid SIN
  	 printf("Valid SIN");
  	 return 0;
  }
    else{ //if the check failed -> sin is invalid
    	printf("Invalid SIN");
    	return 1;
    }
  }
  else{ //if more than one command line argument provided, fails, prints nothing.
  	return 1;
  }
}

