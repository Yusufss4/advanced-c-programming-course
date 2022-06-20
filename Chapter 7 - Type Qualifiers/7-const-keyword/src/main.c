#include <stdio.h>
#include "foo.h"

int main(void) {

	const float *pf;
	float *const pt;
	const float * const ptr;
	float const *pfc;

	printf("\nPI: %.2f",PI);
	for(int i = 0;i<12;i++) {
	printf("\nMonths: %s",MONTHS[i]); 
	}
	return 0;

}

void display(const int array[],int limit);
char *strcat(char *restrict s1, const char *restrict s2);