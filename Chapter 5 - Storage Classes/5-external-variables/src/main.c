#include <stdio.h>
#include <stdlib.h>

extern int i;
int i = 0;


void display(void);

int main(void)
{

for(i=0;i<5;i++) {
  printf("\nMain: %d",i);
  display();
  }

}