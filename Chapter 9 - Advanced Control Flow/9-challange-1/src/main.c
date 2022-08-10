#include <stdio.h>


int main(void)
{
	int value = 5;
	int i = 1,j,k=0;

	outerLoop:
		if(i<value) {
			j=i;
			innerLoop:
				if(j<value) {
					printf("");
					j++;
					goto innerLoop;
				}
		}


	return 0;
}

