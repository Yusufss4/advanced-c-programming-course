#include <limits.h>
#include <assert.h>
#include <stdio.h>

static_assert(CHAR_BIT == 16, "16 bit char falsely assumed.");

int main()
{
  puts("char is 16 bits.");
  return 1;
}