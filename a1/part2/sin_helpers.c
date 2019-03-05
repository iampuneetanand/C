// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
#include <stdio.h>
#include <stdlib.h>

int populate_array(int sin, int *sin_array) {
   
    int digits = 8; //placeholder
    int sin_2 = sin; //copy of sin number
    
    sin_array = malloc(sizeof(int) * 9); //allocate memory for array
    while ( digits >= 0){ //we want to fill array in reverse order
       sin_array[digits] = sin_2 % 10; //add the last digit aka remainder
       digits = digits - 1; //reduce index by 1 for next digit
       sin_2 = sin_2 / 10; //cut off last value of sin
	} 
    if (sin_2 == 0){
      return 0; //if the number is gone, then array has been filled

    } 
  else{ //if number not gone, then number was too big and fails
    return 1;
  }

    
       
}

// TODO: Implement check_sin
/* 
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
    int sin_total = 0;
    if (sin_array[0] != 1){  //multiplying sin values by algorithm
       sin_array[1] = sin_array[1] * 2;
       sin_array[3] = sin_array[3] * 2;
       sin_array[5] = sin_array[5] * 2;
       sin_array[7] = sin_array[7] * 2;
   }
   //add all sin values up
    sin_total = sin_array[0] + sin_array[1] + sin_array[2] + sin_array[3];
    sin_total = sin_total + sin_array[4] + sin_array[5] + sin_array[6];
    sin_total = sin_total + sin_array[7] + sin_array[8];
    if (sin_total % 10 == 0){ //if divisible by 10, return 0
       return 0;
    }
    else{ //if not then not a real sin and return 1
    return 1;
}
}