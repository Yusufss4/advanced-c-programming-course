#include <stdio.h>

int main()
{
  size_t size = 0;
  int sum = 0;
  printf("Enter the number of elements you want to store: ");
  scanf("%zd", &size);
  int values[size];
  for (int i = 0; i < size; i++)
  {
    printf(": ");
    scanf("%d", &values[i]);
    sum = sum + values[i];
  }

  printf("\nSum = :%d", sum);

  return 0;
}