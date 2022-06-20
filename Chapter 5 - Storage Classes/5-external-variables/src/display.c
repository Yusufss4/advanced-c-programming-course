#include <stdio.h>

void display(void) {
   extern int i;
   printf("\nDisplay: %d",i);
 }