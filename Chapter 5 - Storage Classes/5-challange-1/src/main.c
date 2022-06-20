#include <stdio.h>
#include <stdlib.h>
#include "foo.h"

void foo(void);
double globalDoubleValueInsideFile = 10;
float globalFloatValueAcessibleFromAnyhwere = 20; //Decleration for the external variable.
int i = 10;

int main(void)
{ 

int blockOfScopeVariable = 10;
  {
    int blockOfScopeVariable = 5;
  }
printf("\nInt variable with block scope: %d",blockOfScopeVariable);

printf("\nGlobal Float Value Acessible From Anyhwere: %f",globalFloatValueAcessibleFromAnyhwere);

register int registerIntVariable = 10;
printf("\nRegister Int Variable: %d",registerIntVariable);

//int five = staticFunctionReturnFive();
//printf("Five: %d",five);

localStaticVariable();
localStaticVariable();
localStaticVariable();



  return 0;
}

int localStaticVariable() {
  static float localVariableWithPermanentStorage = 10;
  localVariableWithPermanentStorage ++;
  printf("\nLocal Variable With Permanent Storage: %f",localVariableWithPermanentStorage);
}
