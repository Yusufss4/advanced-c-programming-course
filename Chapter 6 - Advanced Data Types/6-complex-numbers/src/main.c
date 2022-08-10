#include <stdio.h>
#include <malloc.h>
#include <complex.h>

int main()
{
#ifdef __STDC_NO_COMPLEX__
  printf("Complex arithmetic is not supported.\n");
#else
  printf("Complex arithmetic is supported.\n");
  double complex cx = 1.0 + 3.0 * I;
  double complex cy = 1.0 - 4.0 * I;

  printf("Working with complex numbers:\n");
  printf("Starting values: cx = %.2f+%.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

  double complex sum = cx + cy;
  printf("The sum cx+cy = %.2f %.2fi \n", creal(sum), cimag(sum));

  double complex difference = cx - cy;
  printf("The difference cx-cy = %.2f %.2fi \n", creal(difference), cimag(difference));

#endif
  return 1;
}