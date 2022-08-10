#include <stdio.h>
#include <malloc.h>

struct s {
	int arraySize;
	int array[];
};

int main() {
	int desiredSize = 0;
	struct s *ptr;
	
  printf("Enter the flexible array size: ");
  scanf("%d",&desiredSize);
	ptr = malloc(sizeof(struct s) + desiredSize *sizeof(int));

  for(int i=0;i<desiredSize;i++) {
    ptr->array[i] = i*2;
    printf(" : %d",(*ptr).array[i]);
  }
	return 1;
}