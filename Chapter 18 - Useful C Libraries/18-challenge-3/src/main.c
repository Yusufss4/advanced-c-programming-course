/* CHALLENGE 3
Write a program that prints the current time. 

- Use the time and ctime functions.
- Handle the errors with fprintf and exit functions with correct failure code.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
   time_t ltime;
   char current_time[] = "Wed Jun 30 21:49:08 1993\n";

   if(time(&ltime)<0) {
    fprintf(stderr,"Couldnt get the system clock.\n");
    exit(EXIT_FAILURE);
   }

   strcpy(current_time, ctime(&ltime));

   printf("Current time is %s", current_time);
}
