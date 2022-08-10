#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

struct myArray
{
    int len;
    int array[];
};


int main()  {
	struct myArray *m = NULL;
	int arraySize = 0;

	printf("Enter the size of the flexible array\n");
	scanf("%d", &arraySize);

	size_t size = sizeof(struct myArray);
	m = malloc(size + (sizeof(int) * arraySize));

	m->len = arraySize;
	m->array[0] = 55;
	m->array[1] = 199;

	printf("array is: %d:%d\n", m->array[0], m->array[1]);
	return 0;
}