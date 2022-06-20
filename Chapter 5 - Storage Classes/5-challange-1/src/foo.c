#include <stdio.h>
#include "foo.h"

extern float globalFloatValueAcessibleFromAnyhwere;

void foo(void)
{
  //printf("Testing global double value only that only exists in main.c %d",globalDoubleValueInsideFile);
  printf("Global Float Value Acessible From Anyhwere: %d",globalFloatValueAcessibleFromAnyhwere);

  extern int i; //Decleration for the external variable.
  i = 100;
}

int static staticFunctionReturnFive(void) {
  return 5;
}