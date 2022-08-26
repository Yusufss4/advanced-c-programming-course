#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main()
{
  time_t calendar_start = time(NULL);
  clock_t cpu_start = clock();
  int count = 0;

  const long long iterations = 1000000LL;
  char answer = 'y';
  double x = 0.0;

  printf("Initial Clock Time = %lld Initial Calendar Time = %lld\n", (long long)cpu_start, (long long)calendar_start);

  while (tolower(answer) == 'y') //ctype.h used for tolower() func
  {
    for (long long i = 0LL; i < iterations; ++i)
    {
      x = sqrt(3.14159265);
    }

    printf("%lld square roots completed.\n", iterations * (++count));
    printf("Do you want to run some more(y and n)?\n");
    scanf("\n%c", &answer);
  }

  clock_t cpu_end = clock();        // Final CPU Time, Processor Time
  time_t calendar_end = time(NULL); // Final Calendar Time

  printf("Final clock time = %lld Final calendar time = %lld.\n", (long long)cpu_end, (long long)calendar_end);
  printf("CPU time for %lld iterations is %.2lf seconds.\n", iterations * count, ((double)(cpu_end - cpu_start)) / CLOCKS_PER_SEC);
  printf("Elapsed calendar time to execute the program is %8.2lf seconds.\n", difftime(calendar_end, calendar_start));
  return 0;
}
