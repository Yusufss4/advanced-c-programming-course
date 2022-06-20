#include <stdio.h>
#include <malloc.h>
#include <complex.h>
#include <math.h>

void printComplexNumber(double _Complex complexNum);
double _Complex calculateConjugate(double _Complex complexNum);

int main()
{
#ifdef __STDC_NO_COMPLEX__
  printf("Complex arithmetic is not supported.\n");
#else
  printf("Complex arithmetic is supported.\n");
  double complex cx;
  printf("\nPrinting Complex Number.\n");
  cx = 2.0 + 3.0 * I;
  printComplexNumber(cx);

  printf("\nSquared Imaginary Number.\n");
  cx = 2.0 + 3.0 * I;
  cx = creal(cx) + ((cimag(cx)*I) * (cimag(cx)*I));
  printComplexNumber(cx);

  printf("\nSquared Imaginary Number using POW.\n");
  cx = 2.0 + 3.0 * I;
  cx = creal(cx) + cpow(cimag(cx)*I, 2);
  printComplexNumber(cx);

  printf("\nEuler's Formula\n");
  cx = 2.0 + 3.0 * I;
  const double PI = acos(-1);
  cx = cexp(I * PI); //complex exp and complex pow should be used in complex numbers.
  printComplexNumber(cx);

  printf("\nConjugate\n");
  cx = 2.0 + 3.0 * I;
  cx = calculateConjugate(cx);
  printComplexNumber(cx);

#endif
  return 1;
}

void printComplexNumber(double _Complex complexNum)
{
  printf("Complex Number = %.2f %.2fi \n", creal(complexNum), cimag(complexNum));
}

double _Complex calculateConjugate(double _Complex complexNum)
{
  return complexNum = creal(complexNum) - cimag(complexNum)*I;
}