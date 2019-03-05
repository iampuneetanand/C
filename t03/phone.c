#include <stdio.h>
#include <stdlib.h>

int main(){


   char phonenumber_array[10];
   int number_selected;
   
   while (scanf("%9c %d\n", phonenumber_array, &number_selected) != EOF){
      if (number_selected){
         printf("%c\n", phonenumber_array[number_selected]);
      }
      else {
         printf("%s\n", phonenumber_array);
      }
    }
    return 0;
}