#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t calendar = time(NULL);

  const char *day[] = {"Sunday",
                       "Monday",
                       "Tuesday",
                       "Wednesday",
                       "Thursday",
                       "Friday",
                       "Saturday"};

  const char *month[] = {
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

  const char *suffix[] = {"st", "nd", "rd", "th"};

  typedef enum
  {
    st,
    nd,
    rd,
    th
  } sufindex_t;
  sufindex_t sufsel = th;

  struct tm birthday = {0};
  char name[30] = {'\0'};

  printf("Enter a name of the user: ");
  scanf("%s", name);

  printf("Enter the birthday for %s as a {day month year} integers seperated by space.\n"
         "For example enter the \"26th November 1999\" as \"26 11 1999\".\n"
         "Waiting for your input: ",
         name);

  scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);

  birthday.tm_mon = birthday.tm_mon - 1; // because if user enters 1 it means 0th month.
  birthday.tm_year = birthday.tm_year - 1900;

  if (mktime(&birthday) == -1)
  {
    fprintf(stderr, "Operation Failed.\n");
    return -1;
  }
  switch (birthday.tm_mday)
  {
  case 1:
  case 21:
  case 31:
    sufsel = st;
    break;
  case 2:
  case 22:
    sufsel = nd;
    break;
  case 3:
  case 23:
    sufsel = rd;
    break;
  default:
    sufsel = st;
    break;
  }

  printf("\n%s was born on the %d%s %s %d, which was a %s.\n",
         name, birthday.tm_mday, suffix[sufsel], month[birthday.tm_mon], birthday.tm_year + 1900, day[birthday.tm_wday]);

  return 0;
}
