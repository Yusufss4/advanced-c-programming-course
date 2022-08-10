#include <stdio.h>

int main() {
	int i, sum=0, size = 0;
	printf("Enter size of the array: ");
	scanf("%d", &size);
    
	int arr[size];   

	printf("Enter %d elements in the array: ", size);
  
	for(i=0; i<size; i++) {
      scanf("%d", &arr[i]);
	}

	for(i=0; i<size; i++)    {
		sum = sum + arr[i];
	}

	printf(“\nSum of all elements of array = %d”, sum);
    return 0;
}