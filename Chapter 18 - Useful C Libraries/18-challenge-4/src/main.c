/* CHALLENGE 3
Write a program to compute the number of seconds passed since the beginning of the current month.

- Use the localtime, difftime and mktime functions.
- Handle erros using fprintf and exit function with the correct failure codes.
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

#define DATE_CHAR_STRING 50

static void print_date(struct tm *time_data, char print_date_string[DATE_CHAR_STRING])
{  
   const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
   const char *months[] = {
       "January",
       "February",
       "March",
       "April",
       "May",
       "June",
       "July",
       "August",
       "September",
       "October",
       "November",
       "December"};

   sprintf(print_date_string,"%s %s %d %d - %d:%d:%d", days[time_data->tm_wday],
          months[time_data->tm_mon],
          time_data->tm_mday,
          ((time_data->tm_year) + 1900),
          time_data->tm_hour,
          time_data->tm_min,
          time_data->tm_sec);
}

int main(void)
{
   time_t calendar = time(NULL); // Return the current time. 

   struct tm *time_data;

   time_data = localtime(&calendar); // Return the current time to the tm structure.

   struct tm start_of_the_month_date = {0}; // Transform the date to the end of the previous month. 
   start_of_the_month_date.tm_sec = 60;
   start_of_the_month_date.tm_min = 59;
   start_of_the_month_date.tm_hour = 23;
   start_of_the_month_date.tm_mon = time_data->tm_mon;
   start_of_the_month_date.tm_year = time_data->tm_year;

   time_t start_standard;

   start_standard = mktime(&start_of_the_month_date); // Transform the modified tm structure to the time_t 

   time_t end_standard = time(NULL); // Get the current date.

   double diff = difftime(end_standard, start_standard); // Calculate the difference between two dates.

   struct tm *end_date_local;
   end_date_local = localtime(&end_standard); // Transform the time_to tm structure. 

   char end_date_string[DATE_CHAR_STRING];
   print_date(&start_of_the_month_date, end_date_string); // print the current date.

   char start_date_string[DATE_CHAR_STRING];
   print_date(end_date_local, start_date_string); // print the start of the month.


   // Print the differences
   printf("Difference between the %s and %s is: \n",end_date_string,start_date_string);
   printf("%.0lf seconds of difference.\n", diff);
   printf("%.0f mins of difference\n", floor(diff / (60.0)));
   printf("%.0f hours of difference\n", floor(diff / (60.0 * 60)));
   printf("%.0f days difference\n", floor(diff / (60.0 * 60 * 24)));

   unsigned int total_hours_passed = floor(diff / (60.0 * 60));
   unsigned int total_minutes_passed = floor(diff / (60.0));
   unsigned int minutes_that_left = total_minutes_passed % 60;
   unsigned int seconds_that_left = (unsigned int)diff % 60;
   printf("-> %d hours %d minutes and %d seconds are passed since the start of the month.\n",total_hours_passed,minutes_that_left,seconds_that_left);


   return 0;
}
